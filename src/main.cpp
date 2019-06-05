//
// Created by SpiritStudio on 20.11.18.
//

/**
 * The program learns to build a car using a evolutionary algorithm.
 * It starts with a population of 15 randomly generated shapes with wheels and runs each one to see how far it goes.
 * The cars that go the furthest reproduce to produce offspring for the next generation.
 * The offspring combine the traits of the parents to hopefully produce better cars.
 * With the button at the upper left u can choose to input cars from new generation or exit the program.
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