//
// Created by SpiritStudio on 28.11.18.
//

#ifndef VEHICLESEVOLUTION_CARPARAMETERS_H
#define VEHICLESEVOLUTION_CARPARAMETERS_H

#include <vector>

#include <Box2D/Box2D.h>

class CarParameters {

public:
    CarParameters();
    CarParameters(double front_wheel_radius, double rear_wheel_radius) : CarParameters() {
        front_wheel_radius_ = front_wheel_radius;
        rear_wheel_radius_ = rear_wheel_radius;
    }

    double front_wheel_radius_;
    double rear_wheel_radius_;
    std::vector<b2Vec2> car_body_;
    b2Vec2 front_joint_;
    b2Vec2 rear_joint_;

    double distance_{0};

};


#endif //VEHICLESEVOLUTION_CARPARAMETERS_H
