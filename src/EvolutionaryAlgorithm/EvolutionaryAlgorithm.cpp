//
// Created by SpiritStudio on 01.12.18.
//

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
