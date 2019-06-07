//!  A EvolutionaryAlgorithm class .
/*!
  A class which represents the Evolutionary Algorithm
  Determines the rules of crossover and mutation on car attributes
*/

#ifndef VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H
#define VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H

#include <vector>
#include <chrono>
#include <random>

#include <EvolutionaryAlgorithm/CarParameters.h>

class EvolutionaryAlgorithm {

public:
    //!  A CarParameters copy and copy-assignment constructors are deleted
    EvolutionaryAlgorithm(const EvolutionaryAlgorithm&) = delete;
    //!  A CarParameters copy and copy-assignment constructors are deleted
    EvolutionaryAlgorithm& operator=(const EvolutionaryAlgorithm&) = delete;
    //!  A Method for design pattern of singleton
    /*!
        The Method to recall the singleton instance of EvolutionaryAlgorithm object
    */
    static EvolutionaryAlgorithm& getInstance();

    //!  A Method for producing new generation of cars
    /*!
        The Method is designed to produce new generation of cars once the cars from previous generations are unable to move further.
        \param distances a vector that stores the information about distances covered by corresponding car in previous generation.
    */
    const std::vector<CarParameters> makeNewGeneration(const std::vector<double> &distances);
    //!  A Method for producing the first generation of cars
    /*!
        The Method is designed to produce the first generation of cars on start of the program.
        The parameters of the car ale selected randomly by using uniform and normal distributions.
        \param distances is a vector which consist of distances covered by lastly created generation.
    */
    const std::vector<CarParameters> generateNewPopulation();
    //!  A Method for getting the value of mutation probability in newly generated populations.
    const double getMutationProbability() const;
    //!  A Method for getting the value of crossover probability in newly generated populations.
    const double getCrossoverProbability() const;
    //!  A Method for setting the value of mutation probability in newly generated populations.
    void setMutationProbability_(double mutation_probability);
    //!  A Method for setting the value of crossover probability in newly generated populations.
    void setCrossoverProbability_(double crossover_probability);

    //!  A Method for deciding whether a mutation will occur.
    /*!
        The Method is designed to perform the mutation on specified parameter.
        The decision about whether the mutation occurs is based on value of mutation_probability_.
        \sa maybeMutate()
        \param value is an attribute's value on which mutation may be performed.
        \param sigma is a expectation value of the normal distribution
    */
    bool maybeMutate(double & value, double sigma) const;
    //!  A Method for deciding whether a mutation will occur.
    /*!
        The Method is designed to perform the mutation on specified parameter.
        The decision about whether the mutation occurs is based on value of mutation_probability_.
        \param parameters is a vector of car parameters on which mutation may be performed.
    */
    bool maybeMutate(CarParameters & parameters) const;

    //!  A Method for setting the value of the class vector attrubute which consist of parameters of lastly generated cars.
    void setLastGenerationParameters(const std::vector<CarParameters> &last_generation_parameters_);

private:
    //!  A CarParameters default constructor.
    EvolutionaryAlgorithm();

    //!  A Method for generating a car with random parameters.
    /*!
        The Method is designed to generate the very first population of cars on beginning of the program.
        The car parameters are generated randomly by using uniform and normal distributions.
    */
    const CarParameters generateRandomCar() const;
    //!  A Method for performing a mutation.
    /*!
        The Method is designed to perform the mutation on specified attribute from CarParameter object.
        \param value is an attribute's value on which mutation will be performed.
        \param sigma is an expectation value of the normal distribution.
    */
    double doMutate(double value, double sigma) const;
    //!  A Method for performing a crossover over two values.
    /*!
        The Method is designed to perform the crossover of attributes originated from mother and father attribute.
        \param mother is an attribute which will be crossed with father's value in order to generate new value.
        \param father is an attribute which will be crossed with mother's value in order to generate new value.
    */
    double doCrossover(double mothers_value, double fathers_value) const;
    //!  A Method for performing a crossover over two CarParameters object
    /*!
        The Method is designed to perform the crossover of attributes over two CarParameters which consist of mother and father parameters
        \param mother is a CarParameter object which attributes will be crossed with father in order to generate new CarParameter
        \param father is a CarParameter object which attributes will be crossed with mother in order to generate new CarParameter
    */
    CarParameters doCrossover(const CarParameters & mother, const CarParameters & father) const;
    //!  A Method randomizing feature
    /*!
        The Method is designed to perform the randomizing feature in order to choose
        whether the mutation or crossover occurs.
    */
    bool drawLotsWithPercentage(double percentage) const;
    //!  A Method for selecting one instance from population to perform crossover
    /*!
        The Method is designed to select an instance of CarParameters from population.
        The method is based on rank based selection which depends on how the car with CarParameters perform on road.
        If car covered further distance, the probability of picking it from population is higher.
    */
    const int selectOneInN(int n) const;

    //! Private constant variable.
    /*!
        Store the information about number of cars in each of the population.
    */
    const int CAR_NUMBER_IN_POPULATION_{15};

    //! Private vector.
    /*!
        Store the information about parameters of lastly produced generation.
    */
    std::vector<CarParameters> last_generation_parameters_;
    //! Private variable.
    /*!
        Store the information about probability of mutation occurrence.
    */
    double mutation_probability_{0.03};
    //! Private variable.
    /*!
        Store the information about standard deviation of wheel radius.
    */
    double wheel_sigma_{0.15};
    //! Private variable.
    /*!
        Store the information about expected value of wheel radius.
    */
    double wheel_expedted_value_{0.5};
    //! Private variable.
    /*!
        Store the information about min radius of car body point (in regard to expected car body center in polar coordinates).
    */
    double min_car_body_point_radius_{0.3};
    //! Private variable.
    /*!
        Store the information about max radius of car body point (in regard to expected car body center in polar coordinates).
    */
    double max_car_body_point_radius_{2};
    //! Private variable.
    /*!
        Store the information about standard deviation of car body points cartesian coordinates (x and y).
    */
    double car_body_point_cartesian_sigma_{0.3};
    //! Private variable.
    /*!
        Store the information about probability of crossover occurrence.
    */
    double crossover_probability_{0.4};
    //! Private default_random_engine.
    /*!
        The attribute to perform effective randomization.
    */
    mutable std::default_random_engine generator_;

};


#endif //VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H
