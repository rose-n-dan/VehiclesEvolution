//
// Created by SpiritStudio on 12.01.19.
//

#include <Utils.h>

namespace utils {

std::vector<b2PolygonShape> applyTessellation(const std::vector<b2Vec2> &polyline) {
    // The number type to use for tessellation
    using Coord = double;
    using N = uint32_t;
    using Point = std::array<Coord, 2>;
    std::vector<std::vector<Point>> polygon;
    std::vector<Point> points;

    for (const auto &point : polyline) {
        points.push_back({point.x, point.y});
    }

    polygon.push_back(points);

    std::vector<N> indices = mapbox::earcut<N>(polygon);

    for (auto index : indices) {
        std::cout << points[index][0] << " " << points[index][1] << std::endl;
    }

    if (indices.size() % 3 != 0) {
        throw std::runtime_error("Ear cutting algorithm failed!");
    }

    unsigned long i = 0;

    std::vector<b2PolygonShape> map_shape;

    for (auto it = indices.begin(); it != indices.end(); it += 3)
    {
        map_shape.emplace_back();

        b2Vec2 triangle[3];
        Point point = points.at(*it);
        triangle[0] = b2Vec2(static_cast<float32>(point[0]), static_cast<float32>(point[1]));
        point = points.at(*(it + 1));
        triangle[1] = b2Vec2(static_cast<float32>(point[0]), static_cast<float32>(point[1]));
        point = points.at(*(it + 2));
        triangle[2] = b2Vec2(static_cast<float32>(point[0]), static_cast<float32>(point[1]));

        map_shape.at(i).Set(triangle, 3);
        ++i;
    }

    return map_shape;
}

} // utils