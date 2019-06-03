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
    car_body_.emplace_back(-2.0f, 0.0f);
}

CarParameters::CarParameters(double front_wheel_radius,
                             double rear_wheel_radius,
                             const std::vector<b2Vec2>& car_body,
                             b2Vec2 front_joint,
                             b2Vec2 rear_joint) : front_wheel_radius_(front_wheel_radius),
                                                  rear_wheel_radius_(rear_wheel_radius),
                                                  front_joint_(front_joint),
                                                  rear_joint_(rear_joint),
                                                  car_body_(car_body) {}

