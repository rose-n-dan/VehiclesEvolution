//
// Created by SpiritStudio on 01.12.18.
//

#ifndef VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H
#define VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H

#include <vector>
#include <chrono>
#include <random>

#include <EvolutionaryAlgorithm/CarParameters.h>

class EvolutionaryAlgorithm {

public:
    EvolutionaryAlgorithm(const EvolutionaryAlgorithm&) = delete;
    EvolutionaryAlgorithm& operator=(const EvolutionaryAlgorithm&) = delete;
    static EvolutionaryAlgorithm& getInstance();

    const std::vector<CarParameters> makeNewGeneration(const std::vector<double> &distances);
    const std::vector<CarParameters> generateNewPopulation();
    const double getMutationProbability() const;
    const double getCrossoverProbability() const;
    void setMutationProbability_(double mutation_probability);
    void setCrossoverProbability_(double crossover_probability);

    bool maybeMutate(double & value, double sigma) const;
    bool maybeMutate(CarParameters & parameters) const;

    void setLastGenerationParameters(const std::vector<CarParameters> &last_generation_parameters_);

private:
    EvolutionaryAlgorithm();

    const CarParameters generateRandomCar() const;

    double doMutate(double value, double sigma) const;
    double doCrossover(double mothers_value, double fathers_value) const;
    CarParameters doCrossover(const CarParameters & mother, const CarParameters & father) const;

    bool drawLotsWithPercentage(double percentage) const;
    const int selectOneInN(int n) const;

    // may be problem with adding new car?
    const int CAR_NUMBER_IN_POPULATION_{3};

    std::vector<CarParameters> last_generation_parameters_;
    double mutation_probability_{0.02};
    double crossover_probability_{0.4};

    mutable std::default_random_engine generator_;

};


#endif //VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H
