//
// Created by SpiritStudio on 01.12.18.
//

#ifndef VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H
#define VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H

#include <vector>

#include <EvolutionaryAlgorithm/CarParameters.h>

class EvolutionaryAlgorithm {

public:
    EvolutionaryAlgorithm(const EvolutionaryAlgorithm&) = delete;
    EvolutionaryAlgorithm& operator=(const EvolutionaryAlgorithm&) = delete;
    static EvolutionaryAlgorithm& getInstance();

    const std::vector<CarParameters>& makeNewGeneration(const std::vector<double> &distances);
    const double getMutationProbablity() const;
    const double getCrossoverProbability() const;
    void setMutationProbablity_(double mutation_probablity);
    void setCrossoverProbability_(double crossover_probability);

    double maybeMutate(double value, double sigma) const;


private:
    EvolutionaryAlgorithm() = default;

    double doMutate(double value, double sigma) const;

    bool drawLotsWithPercentage(double percentage) const;

    std::vector<CarParameters> last_generation_parameters_;
    double mutation_probablity_{0.02};
    double crossover_probability_{0.4};

    std::default_random_engine generator_;

};


#endif //VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H
