//
// Created by SpiritStudio on 20.11.18.
//

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