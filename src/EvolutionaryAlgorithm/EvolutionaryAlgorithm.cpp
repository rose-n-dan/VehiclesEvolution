//
// Created by SpiritStudio on 01.12.18.
//

#include <functional>

#include <Utils.h>
#include <EvolutionaryAlgorithm/EvolutionaryAlgorithm.h>

EvolutionaryAlgorithm& EvolutionaryAlgorithm::getInstance() {
    static EvolutionaryAlgorithm evolutionaryAlgorithmInstance;
    return evolutionaryAlgorithmInstance;
}

const CarParameters EvolutionaryAlgorithm::generateRandomCar() const {
    std::normal_distribution<double> wheel_radius_distribution(0.7, 0.3);
    double first_wheel_radius = std::fabs(wheel_radius_distribution(generator_));
    double second_wheel_radius = std::fabs(wheel_radius_distribution(generator_));

    std::normal_distribution<double> car_body_distribution_x(0.0, 1.5);
    std::normal_distribution<double> car_body_distribution_y(0.0, 0.7);
    std::vector<b2Vec2> car_body_points;
    while (car_body_points.size() < CarParameters::NUMBER_OF_CAR_BODY_POINTS_) {
        car_body_points.emplace_back(car_body_distribution_x(generator_), car_body_distribution_y(generator_));
    }

    std::uniform_int_distribution<int> joint_index_distribution(0, 7);
    int first_joint_index = joint_index_distribution(generator_);
    int second_joint_index = joint_index_distribution(generator_);
    while (first_joint_index == second_joint_index) {
        second_joint_index = joint_index_distribution(generator_);
    }
    b2Vec2 first = car_body_points.at(first_joint_index);
    b2Vec2 second = car_body_points.at(second_joint_index);
    b2Vec2 front_joint;
    b2Vec2 rear_joint;
    if (first.x < second.x) {
        front_joint = second;
        rear_joint = first;
    }
    else {
        front_joint = first;
        rear_joint = second;
    }

    return CarParameters(first_wheel_radius, second_wheel_radius, car_body_points, front_joint, rear_joint);
}

const std::vector<CarParameters> EvolutionaryAlgorithm::generateNewPopulation() {
    std::vector<CarParameters> newly_generated_population;

    while (newly_generated_population.size() < CAR_NUMBER_IN_POPULATION_) {
        newly_generated_population.push_back(generateRandomCar());
    }

    return newly_generated_population;
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
    newly_generated_population.push_back(last_generation_parameters_.rbegin()[0]);
    newly_generated_population.push_back(last_generation_parameters_.rbegin()[1]);

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

void EvolutionaryAlgorithm::setLastGenerationParameters(const std::vector<CarParameters> &last_generation_parameters) {
    last_generation_parameters_ = last_generation_parameters;
}
