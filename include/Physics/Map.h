//
// Created by SpiritStudio on 28.11.18.
//

#ifndef VEHICLESEVOLUTION_MAP_H
#define VEHICLESEVOLUTION_MAP_H

#include <Box2D/Box2D.h>

class Map {

public:
    Map(b2World &world);

    const b2Vec2& getPosition() const;
    const std::vector<b2Vec2>& getPolyline() const;

private:
    void loadFromFile(std::string filename);

    static constexpr float DENSITY_ = 1.0f;
    static constexpr float FRICTION_ = 0.1f;

    b2BodyDef body_def_;
    std::vector<b2PolygonShape> map_shape_;
    std::vector<b2FixtureDef> fixture_def_;
    std::vector<b2Vec2> polyline_;
    b2Body *body_;

};


#endif //VEHICLESEVOLUTION_MAP_H
