//
// Created by SpiritStudio on 28.11.18.
//

#include <EvolutionaryAlgorithm/CarParameters.h>


CarParameters::CarParameters(double front_wheel_radius,
                             double rear_wheel_radius,
                             const std::vector<b2Vec2>& car_body,
                             b2Vec2 front_joint,
                             b2Vec2 rear_joint) : front_wheel_radius_(front_wheel_radius),
                                                  rear_wheel_radius_(rear_wheel_radius),
                                                  front_joint_(front_joint),
                                                  rear_joint_(rear_joint),
                                                  car_body_(car_body) {}

