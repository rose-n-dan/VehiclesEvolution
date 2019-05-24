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
    const double getAngle() const;
    std::vector<b2Vec2> getPolygon() const;

    b2Body* getBody();

private:
    static constexpr float DENSITY_ = 2.0f;
    static constexpr float FRICTION_ = 0.1f;

    b2BodyDef body_def_;
    b2PolygonShape dynamic_box_;
    b2FixtureDef fixture_def_;
    b2Body *body_;

};


#endif //VEHICLESEVOLUTION_CARBODY_H
