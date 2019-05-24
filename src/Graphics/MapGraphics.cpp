//
// Created by SpiritStudio on 30.11.18.
//

#include <Graphics/MapGraphics.h>

void MapGraphics::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(map_graphics_, states);
}

void MapGraphics::resetPolyline(size_t size) {
    map_graphics_ = sf::VertexArray(sf::LineStrip, size);
}

void MapGraphics::setVertex(int i, const sf::Vector2f &position) {
    map_graphics_[i].position = position;
}