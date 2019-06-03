//
// Created by SpiritStudio on 01.12.18.
//

#ifndef VEHICLESEVOLUTION_CARBODY_H
#define VEHICLESEVOLUTION_CARBODY_H

#include <vector>

#include <Box2D/Box2D.h>

class CarBody {

public:
    CarBody(b2World &world, const b2Vec2 &position, const std::vector<b2Vec2> &vertices);

    const b2Vec2& getPosition() const;
    const b2Vec2 getVelocity() const; //couldn't return reference - velocity object is temporary
    const double getAngle() const;
    std::vector<b2Vec2> getPolygon() const;

    b2Body* getBody();

private:
    static constexpr float DENSITY_ = 0.7f;
    static constexpr float FRICTION_ = 2.0f;
    static constexpr float RESTITIUTION_ = 0.001f;

    b2BodyDef body_def_;
    b2PolygonShape dynamic_box_;
    b2FixtureDef fixture_def_;
    b2Body *body_;

};


#endif //VEHICLESEVOLUTION_CARBODY_H
