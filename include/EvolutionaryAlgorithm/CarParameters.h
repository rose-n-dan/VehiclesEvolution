//!  A CarParameters class.
/*!
  A class which represents physical parameters of a car.
  Parameters includes car's shape, size and mass.
*/


#ifndef VEHICLESEVOLUTION_CARPARAMETERS_H
#define VEHICLESEVOLUTION_CARPARAMETERS_H

#include <vector>

#include <Box2D/Box2D.h>

class CarParameters {

public:
    //!  A CarParameters default constructor.
    CarParameters() = default;

    //! A CarParameters constructor.
    /*!
      Constructor that specifies front and rear wheel radius
      shape of the car body and position of rotation axis of wheels
    */
    CarParameters(double front_wheel_radius, double rear_wheel_radius,
                  const std::vector<b2Vec2>& car_body, b2Vec2 front_joint, b2Vec2 rear_joint);
    //! Public Variable
    /*!
        Store the information about front wheel radius
    */
    double front_wheel_radius_;
    //! Public Variable
    /*!
        Store the information about rear wheel radius
    */
    double rear_wheel_radius_;
    //! Public vector
    /*!
        Store the information about position of verticies of car body
    */
    std::vector<b2Vec2> car_body_;
    //! Public vector
    /*!
        Store the information about position of front rotation axis of wheels
    */
    b2Vec2 front_joint_;
    //! Public vector
    /*!
        Store the information about position of rear rotation axis of wheels
    */
    b2Vec2 rear_joint_;
    //! Public variable
    /*!
        Store the information about distance covered by car
    */
    double distance_{0};
    //! Public static constant expression
    /*!
        Store the information about number of verticies of car body
    */
    static constexpr int NUMBER_OF_CAR_BODY_POINTS_{6};

};


#endif //VEHICLESEVOLUTION_CARPARAMETERS_H
