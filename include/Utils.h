//
// Created by SpiritStudio on 12.01.19.
//

#ifndef VEHICLESEVOLUTION_UTILS_H
#define VEHICLESEVOLUTION_UTILS_H

#include <vector>
#include <iostream>

#include <mapbox/earcut.h>

#include <Box2D/Box2D.h>

namespace utils {

std::vector<b2PolygonShape> applyTessellation(const std::vector<b2Vec2> &polyline);

bool isNearlyZero(double value, double precision);

} // utils

#endif //VEHICLESEVOLUTION_UTILS_H
