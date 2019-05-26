//
// Created by SpiritStudio on 01.12.18.
//

#include <random>
#include <functional>

#include <Utils.h>
#include <EvolutionaryAlgorithm/EvolutionaryAlgorithm.h>

EvolutionaryAlgorithm& EvolutionaryAlgorithm::getInstance() {
    static EvolutionaryAlgorithm evolutionaryAlgorithmInstance;
    return evolutionaryAlgorithmInstance;
}

const std::vector<CarParameters> EvolutionaryAlgorithm::makeNewGeneration(const std::vector<double> &distances) {
    // add distances to last_generation_parameters vector
    {
        auto parIt = last_generation_parameters_.begin();
        auto distIt = distances.begin();
        for (; parIt != last_generation_parameters_.end() && distIt != distances.end(); parIt++, distIt++) {
            parIt->distance_ = *distIt;
        }
    }

    // sort last_generation_parameters by distance
    std::sort(last_generation_parameters_.begin(), last_generation_parameters_.end(),
        [](const CarParameters & a, const CarParameters & b) -> bool
        {
            return a.distance_ < b.distance_;
        });

    // newly generated population
    std::vector<CarParameters> newly_generated_population;

    // elitist selection - two best guys have guaranteed places in new population
    newly_generated_population.push_back(*last_generation_parameters_.end());
    newly_generated_population.push_back(*(last_generation_parameters_.end() - 1));

    // rank based selection
    while (newly_generated_population.size() < distances.size()) {
        // crossover - 100%
        CarParameters new_car = doCrossover(last_generation_parameters_.at(selectOneInN(CAR_NUMBER_IN_POPULATION_)),
                                            last_generation_parameters_.at(selectOneInN(CAR_NUMBER_IN_POPULATION_)));
        // mutation
        maybeMutate(new_car);
        newly_generated_population.push_back(new_car);
    }

    // store newly generated population as last generation
    last_generation_parameters_.clear();
    last_generation_parameters_ = newly_generated_population;

    return newly_generated_population;
}

// utility to rank based selection
const int EvolutionaryAlgorithm::selectOneInN(int n) const {
    std::uniform_real_distribution<double> distribution(0, n * n);
    return std::sqrt(distribution(generator_));
}

const double EvolutionaryAlgorithm::getMutationProbability() const {
    return mutation_probability_;
}

const double EvolutionaryAlgorithm::getCrossoverProbability() const {
    return crossover_probability_;
}

void EvolutionaryAlgorithm::setMutationProbability_(double mutation_probability) {
    EvolutionaryAlgorithm::mutation_probability_ = mutation_probability;
}

void EvolutionaryAlgorithm::setCrossoverProbability_(double crossover_probability) {
    EvolutionaryAlgorithm::crossover_probability_ = crossover_probability;
}

bool EvolutionaryAlgorithm::maybeMutate(CarParameters & parameters) const {
    // should return if mutation occured
    return maybeMutate(parameters.front_wheel_radius_, 0.15) &&
           maybeMutate(parameters.rear_wheel_radius_, 0.15);
}

bool EvolutionaryAlgorithm::maybeMutate(double & value, double sigma) const {
    if(drawLotsWithPercentage(mutation_probability_)) {
        doMutate(value, sigma);
        return true;
    }

    return false;
}

double EvolutionaryAlgorithm::doMutate(double value, double sigma) const {
    std::normal_distribution<double> distribution(value, sigma);
    return distribution(generator_);
}

CarParameters EvolutionaryAlgorithm::doCrossover(const CarParameters & mother, const CarParameters & father) const {
    CarParameters new_car_parameters;
    new_car_parameters.front_wheel_radius_ = doCrossover(mother.front_wheel_radius_, father.front_wheel_radius_);
    new_car_parameters.rear_wheel_radius_ = doCrossover(mother.rear_wheel_radius_, father.rear_wheel_radius_);

    return new_car_parameters;
}

double EvolutionaryAlgorithm::doCrossover(double mothers_value, double fathers_value) const {
    std::uniform_real_distribution<double> distribution(0, 1);
    double coefficient = distribution(generator_);
    return coefficient * mothers_value + (1 - coefficient) * fathers_value;
}

bool EvolutionaryAlgorithm::drawLotsWithPercentage(double percentage) const {
    std::uniform_real_distribution<double> distribution(0, 1);
    return distribution(generator_) < percentage;
}
