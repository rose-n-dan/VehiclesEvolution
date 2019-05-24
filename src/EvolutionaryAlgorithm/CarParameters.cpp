//
// Created by SpiritStudio on 28.11.18.
//

#include <EvolutionaryAlgorithm/CarParameters.h>

CarParameters::CarParameters() : front_wheel_radius_(0.5f),
                                 rear_wheel_radius_(0.5f),
                                 front_joint_(1.25f, 0.5f),
                                 rear_joint_(-1.25f, 0.5f) {
    car_body_.emplace_back(1.25f, -0.8f);
    car_body_.emplace_back(2.0f, 0.0f);
    car_body_.emplace_back(1.25f, 0.5f);
    car_body_.emplace_back(-1.25f, 0.5f);
    car_body_.emplace_back(-1.25f, -0.5f);
}