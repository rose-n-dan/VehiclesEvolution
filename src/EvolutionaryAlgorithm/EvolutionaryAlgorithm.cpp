//
// Created by SpiritStudio on 01.12.18.
//

#include <random>

#include <Utils.h>
#include <EvolutionaryAlgorithm/EvolutionaryAlgorithm.h>

EvolutionaryAlgorithm& EvolutionaryAlgorithm::getInstance() {
    static EvolutionaryAlgorithm evolutionaryAlgorithmInstance;
    return evolutionaryAlgorithmInstance;
}

const std::vector<CarParameters>& EvolutionaryAlgorithm::makeNewGeneration(const std::vector<double> &distances) {

}

const double EvolutionaryAlgorithm::getMutationProbablity() const {
    return mutation_probablity_;
}

const double EvolutionaryAlgorithm::getCrossoverProbability() const {
    return crossover_probability_;
}

void EvolutionaryAlgorithm::setMutationProbablity_(double mutation_probablity) {
    EvolutionaryAlgorithm::mutation_probablity_ = mutation_probablity;
}

void EvolutionaryAlgorithm::setCrossoverProbability_(double crossover_probability) {
    EvolutionaryAlgorithm::crossover_probability_ = crossover_probability;
}

double EvolutionaryAlgorithm::maybeMutate(double value, double sigma) const {
    if(drawLotsWithPercentage(mutation_probablity_)) {
        return doMutate(value, sigma);
    }

    return value;
}

double EvolutionaryAlgorithm::doMutate(double value, double sigma) const {
    std::normal_distribution<double> distribution(value, sigma);
    return distribution(generator_);
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
