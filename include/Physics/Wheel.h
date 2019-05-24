//
// Created by SpiritStudio on 01.12.18.
//

#ifndef VEHICLESEVOLUTION_WHEEL_H
#define VEHICLESEVOLUTION_WHEEL_H

#include <Box2D/Box2D.h>

class Wheel {

public:
    Wheel(b2World &world, double radius);

    const b2Vec2& getPosition() const;
    const double getAngle() const;
    const double getRadius() const;

    b2Body* getBody();

private:
    static constexpr float DENSITY_ = 1.0f;
    static constexpr float FRICTION_ = 0.5f;
    static constexpr float RESTITIUTION_ = 0.2f;

    b2BodyDef body_def_;
    b2CircleShape dynamic_circle_;
    b2FixtureDef fixture_def_;
    b2Body *body_;

};

#endif //VEHICLESEVOLUTION_WHEEL_H
