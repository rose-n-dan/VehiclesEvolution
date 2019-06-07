//!  A CarBody class.
/*!
  A class which represents the car body object.
  Class attributes consists of car body parameters like
  density, friction coefficient, restitiution coefficient and shape.
*/

#ifndef VEHICLESEVOLUTION_CARBODY_H
#define VEHICLESEVOLUTION_CARBODY_H

#include <vector>

#include <Box2D/Box2D.h>

class CarBody {

public:
    //!  A Constructor of class.
    /*!
        The constructor creates a CarBody object specifying its position, parameters and world membership
        \param world specifies the world which CarBody object belong to.
        \param position defines the position of the CarBody object.
        \param vertices is a vector, which gathers the coordinates of the vertices used to create CarBody polygon shape.
    */
    CarBody(b2World &world, const b2Vec2 &position, const std::vector<b2Vec2> &vertices);

    //!  A Method for getting a CarBody object's position.
    const b2Vec2& getPosition() const;
    //!  A Method for getting a CarBody object's velocity.
    const b2Vec2 getVelocity() const;
    //!  A Method for getting a CarBody object's angular position.
    const double getAngle() const;
    //!  A Method for getting a CarBody object's polygon shape.
    std::vector<b2Vec2> getPolygon() const;

    //!  A Method for getting a CarBody object's b2Body object.
    b2Body* getBody();

private:
    //!  Private static constant expression
    /*!
        The attribute consists of information about density of the CarBody object.
    */
    static constexpr float DENSITY_ = 0.7f;
    //!  Private static constant expression
    /*!
        The attribute consists of information about friction coefficient of the CarBody object.
    */
    static constexpr float FRICTION_ = 3.0f;
    //!  Private static constant expression
    /*!
        The attribute consists of information about restitiution coefficient of the CarBody object.
    */
    static constexpr float RESTITIUTION_ = 0.001f;

    //!  Private object
    /*!
        The attribute consists of object which represents a CarBody parameters.
    */
    b2BodyDef body_def_;
    //!  Private object
    /*!
        The attribute consists of object which represents a CarBody shape.
    */
    b2PolygonShape dynamic_box_;
    //!  Private object
    /*!
        The attribute consists of object which represents a CarBody shape's fixture parameters.
    */
    b2FixtureDef fixture_def_;
    //!  Private object
    /*!
        The attribute consists of object which represents a Body object.
    */
    b2Body *body_;

};


#endif //VEHICLESEVOLUTION_CARBODY_H
