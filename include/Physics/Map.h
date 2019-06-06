//!  A Map class.
/*!
  A class which represents the map object.
  Class attributes consists of map parameters which include
  a friction coefficient, density and shape
*/

#ifndef VEHICLESEVOLUTION_MAP_H
#define VEHICLESEVOLUTION_MAP_H

#include <Box2D/Box2D.h>

class Map {

public:
    //!  A Constructor of class.
    /*!
        The constructor creates a Map object specifying its world membership.
        The additional feature is that the map is being created using external .txt file
        \param world specifies the world which Map object belong to.
    */
    explicit Map(b2World &world, std::string file_name="data/map.txt");

    //!  A Method for getting a Map object's position.
    const b2Vec2& getPosition() const;
    //!  A Method for getting a Map object's polygon shape.
    const std::vector<b2Vec2>& getPolyline() const;

private:
    //!  A Method for loading parameters from external file
    /*!
        The Method is designed to load coordinates of consecutive verticies which create the shape of map.
        \param filename is a name of a .txt file which consists of Map object's verticies coordinates.
    */
    void loadFromFile(const std::string& filename);

    //!  Private static constant expression
    /*!
        The attribute consists of information about density of the Map object.
    */
    static constexpr float DENSITY_ = 1.0f;
    //!  Private static constant expression
    /*!
        The attribute consists of information about friction coefficient of the Map object.
    */
    static constexpr float FRICTION_ = 0.1f;

    //!  Private object
    /*!
        The attribute consists of object which represents a Map parameters.
    */
    b2BodyDef body_def_;
    //!  Private object
    /*!
        The attribute consists of vector of objects which represent a Map shape.
    */
    std::vector<b2PolygonShape> map_shape_;
    //!  Private object
    /*!
        The attribute consists of vector of objects which represent a Map shape's fixture parameters.
    */
    std::vector<b2FixtureDef> fixture_def_;
    //!  Private object
    /*!
        The attribute consists of vector of objects which represent a Map's polygon.
    */
    std::vector<b2Vec2> polyline_;
    //!  Private object
    /*!
        The attribute consists of object which represents a Body object.
    */
    b2Body *body_;

};


#endif //VEHICLESEVOLUTION_MAP_H
