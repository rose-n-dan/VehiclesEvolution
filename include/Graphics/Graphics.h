//
// Created by SpiritStudio on 29.11.18.
//

#ifndef VEHICLESEVOLUTION_GRAPHICS_H
#define VEHICLESEVOLUTION_GRAPHICS_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Graphics/CarGraphics.h>
#include <Graphics/MapGraphics.h>
#include <Graphics/GraphicalUserInterface.h>
#include <Physics/Car.h>
#include <Physics/Map.h>

/**
 * Class implementing Singleton and Pseudo-Observer design patterns
 */

class Graphics {

public:
    Graphics(const Graphics&) = delete;
    Graphics& operator=(const Graphics&) = delete;

    static Graphics& getInstance() {
        static Graphics graphicsInstance;
        return graphicsInstance;
    }

    void newCars(const std::vector<Car> &cars);
    void newMap(const Map &map);
    void newCarsPositions(const std::vector<Car> &cars);

    const bool isWindowOpen() const;
    void handleEvents();

    void ensureConstantFrameRate(int frameRate);
    void restartClock();

    void draw();

private:
    Graphics();

    CarGraphics generateGraphics(const Car &car);

    void followTheLeader();

    static constexpr float PIXELS_PER_METER_ = 60.0f;
    static constexpr int WINDOW_WIDTH_PIXELS_ = 1000;
    static constexpr int WINDOW_HEIGHT_PIXELS_ = 600;
    static constexpr int INTERFACE_WIDTH_PIXELS_ = 300;

    const sf::Color background_color_;

    std::vector<CarGraphics> cars_graphics_;
    MapGraphics map_graphic_;
    GraphicalUserInterface gui_;

    sf::ContextSettings settings_;
    sf::RenderWindow window_;
    sf::Clock clock_;
    sf::Time time_;
    sf::View view_action_, view_gui_;

};

#endif //VEHICLESEVOLUTION_GRAPHICS_H
