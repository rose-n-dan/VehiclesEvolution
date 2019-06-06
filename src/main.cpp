/*! \mainpage Welcome to Vehicle Evolution's technical documentation
 *
 * \section intro_sec Introduction
 *
 * The program learns to build a car using a evolutionary algorithm.
 * It starts with a population of 15 randomly generated shapes with wheels and runs each one to see how far it goes.
 * The cars that go the furthest reproduce to produce offspring for the next generation.
 * The offspring combine the traits of the parents to hopefully produce better cars.
 * With the button at the upper left u can choose to input cars from new generation or exit the program.
 *
 * It uses a physics library called box2D to simulate the effects of gravity, friction, collisions, motor torque, and spring tension for the car.
 * This lets the car be a wide range of shapes and sizes, while still making the simulation realistic.
 * Implementation uses the physics library to make the car a real object instead of two point masses.
 *
 * \section library_sec Libraries used in implementation
 * During the designing and implementation stages the following opensource libraries were used:
 * \subsection lib1 1. Box2D
 * Is a free open source 2-dimensional physics simulator engine written in C++ by Erin Catto and published under the zlib license.
 * The repository with additional documentation could be found here
 * https://github.com/erincatto/Box2D
 *
 * \subsection lib2 2. SFML
 * It isis a cross-platform software development library designed to provide a simple application programming interface (API) to various multimedia components in computers.
 * It is written in C++ with bindings available for C, Crystal, D, Euphoria, Go, Java and more
 * The repository with additional documentation could be found here
 * https://github.com/SFML/SFML
 *
 * \subsection lib3 3. TGUI
 * TGUI is a cross-platform C++ GUI library for SFML.
 * The repository with additional documentation could be found here
 * https://tgui.eu/documentation/
 *
 * \subsection lib4 4. gtest
 * gtest is a Google's C++ test framework.
 * The repository with additional documentation could be found here
 * https://github.com/google/googletest
 *
 * \section alg_sec The Algorithm
 * \subsection car Designing the Car
 * Each car is a set of CarBody object and 2 Wheel objects.
 * CarBody object consists of 6 randomly chosen vectors: direction and magnitude.
 * All the vectors radiate from a central point (0,0).
 * For each wheel it randomly chooses a vertex to put the axle on.
 * Also the radius of wheel is choosen randomly
 * \subsection sel_sub Selection
 * At the end of each generation, pairs of parents have to be selected to produce offspring for the next generation.
 * That's the selection process and we've implemented two algorithms.
 * \subsubsection roul_sel_sub Roulette-Wheel Selection
 * This is the most obvious selection strategy, since it chooses parents based on their fitness scores.
 * Specifically, it finds the sum of all fitness scores for that generation and divides each score by the sum to get the probability.
 * Summing the probabilities creates a wheel we can select from.
 * \subsubsection tour_sel_sub Elite Selection
 * Selection pressure can more be controlled more easily with Elite selection,
 * which really increasing the pressure itself, making high scoring individuals dominating the population.
 * The elite selection always chooses the best car from the population for reproducing
 * \subsection mut_sub Mutation
 * In addition to crossover, each generation the chromosomes go through mutation.
 * This means theres a probability that each aspect of the car will change,
 * as determined by the mutation rate slider set by the user.
 * When a variable mutates, a new value is randomly chosen in the desired range.
 * By definition at 100% mutation rate, every variable is chosen randomly each generation and no information is retained.
*/

#include <Physics/Physics.h>
#include <Graphics/Graphics.h>
#include <EvolutionaryAlgorithm/EvolutionaryAlgorithm.h>

int main()
{
    constexpr int FRAME_RATE = 120;

    Physics::getInstance().notifyMap();
    Physics::getInstance().notifyCars();

    Graphics::getInstance().restartClock();

    while (Graphics::getInstance().isWindowOpen())
    {
        Graphics::getInstance().handleEvents();

        Physics::getInstance().update(FRAME_RATE);
        Physics::getInstance().notifyCarsPositions();

        // Every generation goes like this
        if (Physics::getInstance().allDead())
        {
            std::cout << "ALL DEAD" << std::endl;
            // stop simulation, save all distances, make new generation and so on...

            Physics::getInstance().makeCars(
                    EvolutionaryAlgorithm::getInstance().makeNewGeneration(
                            Physics::getInstance().getFinalDistances()));

            std::cout << "BEWARE, NEW GENERATION IS COMING!" << std::endl;
        }

        Graphics::getInstance().draw();
        Graphics::getInstance().ensureConstantFrameRate(FRAME_RATE);
    }

    return 0;
}