//
// Created by SpiritStudio on 20.11.18.
//

#include <Physics/Physics.h>
#include <Graphics/Graphics.h>

int main()
{
    constexpr int FRAME_RATE = 60;

    Physics::getInstance().notifyMap();
    Physics::getInstance().notifyCars();

//    Every generation goes like this
//
//
//    if (Physics::getInstance().allDead())
//    {
//        Physics::getInstance().makeCars(
//                EvolutionaryAlgorithm::getInstance.makeParameters(
//                        Physics::getInstance().getLatestDistances()));
//
//        Physics::getInstance().notifyCars(Graphics::getInstance());
//    }
    Graphics::getInstance().restartClock();

    while (Graphics::getInstance().isWindowOpen())
    {
        Graphics::getInstance().handleEvents();

        Physics::getInstance().update(FRAME_RATE);
        Physics::getInstance().notifyCarsPositions();

        Graphics::getInstance().draw();
        Graphics::getInstance().ensureConstantFrameRate(FRAME_RATE);
    }

    return 0;
}