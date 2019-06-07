//!  A Wheel class.
/*!
  A class which represents the wheel object.
  Class attributes consists of wheel parameters like
  density, friction coefficient, restitiution coefficient and shape.
*/

#ifndef VEHICLESEVOLUTION_WHEEL_H
#define VEHICLESEVOLUTION_WHEEL_H

#include <Box2D/Box2D.h>

class Wheel {

public:
    Wheel(b2World &world, double radius);

    //!  A Method for getting a Wheel object's position.
    const b2Vec2& getPosition() const;
    //!  A Method for getting a Wheel object's angular position.
    const double getAngle() const;
    //!  A Method for getting a Wheel object's circle shape radius.
    const double getRadius() const;

    //!  A Method for getting a Wheel object's b2Body object.
    b2Body* getBody();

private:
    //!  Private static constant expression
    /*!
        The attribute consists of information about density of the Wheel object.
    */
    static constexpr float DENSITY_ = 2.0f;
    //!  Private static constant expression
    /*!
        The attribute consists of information about friction coefficient of the Wheel object.
    */
    static constexpr float FRICTION_ = 1.0f;
    //!  Private static constant expression
    /*!
        The attribute consists of information about restitiution coefficient of the Wheel object.
    */
    static constexpr float RESTITIUTION_ = 0.1f;

    //!  Private object
    /*!
        The attribute consists of object which represents a Wheel parameters.
    */
    b2BodyDef body_def_;
    //!  Private object
    /*!
        The attribute consists of object which represents a Wheel shape.
    */
    b2CircleShape dynamic_circle_;
    //!  Private object
    /*!
        The attribute consists of object which represents a Wheel shape's fixture parameters.
    */
    b2FixtureDef fixture_def_;
    //!  Private object
    /*!
        The attribute consists of object which represents a Body object.
    */
    b2Body *body_;

};

#endif //VEHICLESEVOLUTION_WHEEL_H
