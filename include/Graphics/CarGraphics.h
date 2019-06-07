//!  A CarGraphics class .
/*!
  A class which performs a graphical representation of a car.
  Determines the rules drawing and positioning of the car texture.
*/

#ifndef VEHICLESEVOLUTION_CARGRAPHICS_H
#define VEHICLESEVOLUTION_CARGRAPHICS_H

#include <SFML/Graphics.hpp>

class CarGraphics : public sf::Drawable {

public:
    //!  A CarGraphics constructors.
    /*!
        Constructor create an instance of CarGraphics specifying its parameters.
        \param vertices is a vector which consist of verticies coordinates of car body polygon.
        \param front_wheel_radius is a variable which consist of value of front wheel radius.
        \param rear_wheel_radius is a variable which consist of value of rear wheel radius.
    */
    CarGraphics(const std::vector<sf::Vector2f> &vertices, double front_wheel_radius, double rear_wheel_radius);

    //!  A method for setting the posistion and angle of the CarGraphics object
    /*!
        \param position is a vector which consist of car graphic's coordinates
    */
    void setPositionAndAngle(const sf::Vector2f &position, float angle);
    //!  A method for setting the position and angle of the front wheel from CarGraphics object
    /*!
        \param position is a vector which consist of front wheel graphic's coordinates
    */
    void setFrontWheelPosition(const sf::Vector2f &position);
    //!  A method for setting the position and angle of the rear wheel from CarGraphics object
    /*!
        \param position is a vector which consist of rear wheel graphic's coordinates
    */
    void setRearWheelPosition(const sf::Vector2f &position);

    //!  A method for getting the position of the CarGraphics object
    const sf::Vector2f& getPosition() const;

    //!  A method for getting a car body graphical representation object
    const sf::ConvexShape& getCarBodyGraphics() const;

    //!  A method for getting a car front wheel graphical representation object
    const sf::CircleShape& getFrontWheel() const;

    //!  A method for getting a car rear wheel graphical representation object
    const sf::CircleShape& getRearWheel() const;

private:
    //!  A method for drawing the CarGraphics object
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    //! Private consant variable.
    /*!
        Store the information about color of car body and wheels
    */
    const sf::Color car_body_color_, wheel_color_;

    //! Private constant variable.
    /*!
        Store the information about convex polygonal shape of car body
    */
    sf::ConvexShape car_body_graphics_;
    //! Private constant variable.
    /*!
        Store the information about circle shape of rear wheel
    */
    sf::CircleShape wheel_rear_;
    //! Private constant variable.
    /*!
        Store the information about circle shape of front wheel
    */
    sf::CircleShape wheel_front_;

};


#endif //VEHICLESEVOLUTION_CARGRAPHICS_H
