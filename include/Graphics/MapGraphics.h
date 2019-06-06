//!  A MapGraphics class .
/*!
  A class which performs a graphical representation of a map.
  Determines the rules drawing and positioning of the map textures.
*/

#ifndef VEHICLESEVOLUTION_MAPGRAPHICS_H
#define VEHICLESEVOLUTION_MAPGRAPHICS_H

#include <SFML/Graphics.hpp>

class MapGraphics : public sf::Drawable {

public:
    //! A Method for resetting the shape of polygon
    void resetPolyline(size_t size);
    //! A Method for setting the position of i-th vertex
    void setVertex(int i, const sf::Vector2f &position);
    const sf::VertexArray& getVertices() const;

private:
    //!  A method for drawing the MapGraphics object
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    //! Private array
    /*!
        Store the information about verticies which altogether create shape of map
    */
    sf::VertexArray map_graphics_;

};


#endif //VEHICLESEVOLUTION_MAPGRAPHICS_H
