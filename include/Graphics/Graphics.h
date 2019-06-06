//!  A Graphics class.
/**
 * Class implementing Singleton and Pseudo-Observer design patterns.
 * It was designed in order to create graphics of cars and map and showing their movement.
 */


#ifndef VEHICLESEVOLUTION_GRAPHICS_H
#define VEHICLESEVOLUTION_GRAPHICS_H

#include <iostream>

#include <SFML/Graphics.hpp>

#include <Graphics/CarGraphics.h>
#include <Graphics/MapGraphics.h>
#include <Graphics/GraphicalUserInterface.h>
#include <Physics/Car.h>
#include <Physics/Map.h>



class Graphics {

public:
    //!  A Graphics copy and copy-assigned constructor deleted.
    Graphics(const Graphics&) = delete;
    //!  A Graphics copy and copy-assigned constructor deleted.
    Graphics& operator=(const Graphics&) = delete;
    //!  A Graphics singleton constructor.
    static Graphics& getInstance() {
        static Graphics graphicsInstance;
        return graphicsInstance;
    }

    //!  A Method for creating graphics of cars.
    /*!
        The Method is designed to fill the vector of car graphics
        from the vector of corresponding objects of class Car.
    */
    void newCars(const std::vector<Car> &cars);
    //!  A Method for creating graphics of map.
    /*!
        The Method is designed in order to create the map from the information
        about verticies of the polygon which represents earth.
    */
    void newMap(const Map &map);
    //!  A Method for updating the position of cars
    /*!
        The Method is designed to update the position of the cars from the population.
        Cars change their position every single iteration and Graphics object need to
        update their textures every iteration.
    */
    void newCarsPositions(const std::vector<Car> &cars);

    //! Public constant variable.
    /*!
        Store the information whether the application window is open.
    */
    const bool isWindowOpen() const;
    //!  A method for handling on-running events, like mouse-click.
    void handleEvents();

    //!  A method for ensuring the constant frame rate of the application graphic refreshing.
    void ensureConstantFrameRate(int frameRate);
    //!  A method for restarting the application clock.
    void restartClock();
    //!  A method for drawing texture on window.
    void draw();

    const MapGraphics& getMapGraphics() const;
    const std::vector<CarGraphics>& getCarGraphics() const;
    const std::pair<double, double> getMapGraphicsVertexInMeters(int vertex_index) const;

    static double convertPixelsToMeters(double pixels);

private:
    //!  A Graphics private constructor.
    Graphics();

    CarGraphics generateGraphics(const Car &car);

    //!  A Method for following the car which covered the greatest distance.
    /*!
        The Method is designed to follow the leader of the population.
        A car which is first on the map is being followed.
    */
    void followTheLeader();

    //! Static constant expression.
    /*!
        A attribute consists of information about pixels per meter density.
    */
    static constexpr float PIXELS_PER_METER_ = 60.0f;
    //! Static constant expression.
    /*!
        A attribute consists of information about application window width in pixels.
    */
    static constexpr int WINDOW_WIDTH_PIXELS_ = 1000;
    //! Static constant expression.
    /*!
        A attribute consists of information about application window height in pixels.
    */
    static constexpr int WINDOW_HEIGHT_PIXELS_ = 600;
    //! Static constant expression.
    /*!
        A attribute consists of information about application interface width in pixels.
    */
    static constexpr int INTERFACE_WIDTH_PIXELS_ = 300;

    //! Constant object.
    /*!
        A attribute consists of information about color of the application background.
    */
    const sf::Color background_color_;

    //! Private vector.
    /*!
        A vector consists of CarGraphics objects.
    */
    std::vector<CarGraphics> cars_graphics_;
    //! Private object.
    /*!
        An object consists of graphic representation of map.
    */
    MapGraphics map_graphic_;
    //! Private object.
    /*!
        An object consists of graphic representation of User Interface.
    */
    GraphicalUserInterface gui_;

    //! Private object.
    /*!
        An object consists of information about current application settings
    */
    sf::ContextSettings settings_;
    //! Private object.
    /*!
        An object which represents the application window.
    */
    sf::RenderWindow window_;
    //! Private object.
    /*!
        An object which represents the application clock.
    */
    sf::Clock clock_;
    //! Private object.
    /*!
        An object which consists of the information about time which passed from application start.
    */
    sf::Time time_;
    //! Private object.
    /*!
        An object which consists of the representation of the current action view
    */
    sf::View view_action_;
    //! Private object.
    /*!
        An object which consists of the representation of the current Graphical User Interface view
    */
    sf::View view_gui_;

};

#endif //VEHICLESEVOLUTION_GRAPHICS_H
