//
// Created by SpiritStudio on 28.11.18.
//

#include <vector>
#include <fstream>

#include <Physics/Map.h>
#include <Utils.h>

Map::Map(b2World &world, std::string file_name) {
    body_def_.position.Set(0.0f, 0.0f);

    body_ = world.CreateBody(&body_def_);

    loadFromFile(file_name);

    map_shape_ = utils::applyTessellation(polyline_);
    unsigned long i = 0;

    for (const auto &map_shape : map_shape_)
    {
        fixture_def_.emplace_back();

        fixture_def_.at(i).shape = &map_shape;

        // Set the box density to be non-zero, so it will be dynamic.
        fixture_def_.at(i).density = DENSITY_;

        // Override the default friction.
        fixture_def_.at(i).friction = FRICTION_;

        // Collision detection masks from box2d
        fixture_def_.at(i).filter.categoryBits = 0x0002;
        fixture_def_.at(i).filter.maskBits = 0x0001;
        body_->CreateFixture(&fixture_def_.at(i));
        ++i;
    }
}

const b2Vec2& Map::getPosition() const {
    return body_->GetPosition();
}

const std::vector<b2Vec2>& Map::getPolyline() const {
    return polyline_;
}

void Map::loadFromFile(const std::string& filename) {
    std::ifstream map_file(filename, std::ios::in);

    polyline_.clear();

    double x, y;

    while (map_file >> x >> y)
    {
        polyline_.emplace_back(x, y);
    }
}
