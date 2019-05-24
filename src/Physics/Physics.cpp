//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Physics.h>

const b2Vec2 Physics::CAR_STARTING_POSITION_ = b2Vec2(10.0f, 3.0f);

Physics::Physics() : gravity_(0.0f, 9.81f),
                      world_(gravity_, false),
                      map_(world_) {
}

void Physics::update(const int frame_rate) {
    float32 timeStep = 1.0f / frame_rate;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    world_.Step(timeStep, velocityIterations, positionIterations);
}

const bool Physics::allDead() const{
    return false;
}

void Physics::notifyCars() {
    Graphics::getInstance().newCars(cars_);
}

void Physics::notifyMap() {
    Graphics::getInstance().newMap(map_);
}

void Physics::notifyCarsPositions() {
    Graphics::getInstance().newCarsPositions(cars_);
}

void Physics::makeCars(const std::vector<CarParameters> &cars_parameters) {
    cars_.clear();

    for (const auto &car_parameters : cars_parameters)
    {
        cars_.emplace_back(world_, CAR_STARTING_POSITION_, car_parameters);
    }

    notifyCars();
}

void Physics::makeCar(const CarParameters &car_parameters) {
    cars_.emplace_back(world_, CAR_STARTING_POSITION_, car_parameters);

    notifyCars();
}

const std::vector<Car>& Physics::getCars() const{
    return cars_;
}

const Map& Physics::getMap() const{
    return map_;
}