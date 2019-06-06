/**
 * The library implements a modified ear slicing algorithm for polygon triangulation
 * It is optimized by z-order curve hashing and extended to handle holes, twisted polygons, degeneracies and self-intersections.
 * It works in a way that doesn't guarantee correctness of triangulation, but attempts to always produce acceptable results for practical data.
 * It's based on ideas from FIST:
 *  Fast Industrial-Strength Triangulation of Polygons by Martin Held
 *  Triangulation by Ear Clipping by David Eberly.
 */

#ifndef VEHICLESEVOLUTION_UTILS_H
#define VEHICLESEVOLUTION_UTILS_H

#include <vector>
#include <iostream>

#include <mapbox/earcut.h>

#include <Box2D/Box2D.h>

namespace utils {

    //!  A main function of library
    /*!
        The function apply a triangulation algorithm to polygon shape in order to create simplified shapes.
        \param polyline is a vector which consists of consecutive verticies which create the shape of polygon.
    */
    std::vector<b2PolygonShape> applyTessellation(const std::vector<b2Vec2> &polyline);

    //!  A auxiliary function of library
    /*!
        The function check whether the value is near zero within the precision limits.
        \param value is a parameter which is being checked whether it is near zero value.
        \param precision is a parameter which states for precision of checking.
    */
    bool isNearlyZero(double value, double precision);

}

#endif //VEHICLESEVOLUTION_UTILS_H
