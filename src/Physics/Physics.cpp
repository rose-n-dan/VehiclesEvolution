//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Physics.h>

const b2Vec2 Physics::CAR_STARTING_POSITION_ = b2Vec2(10.0f, 3.0f);

Physics::Physics() : gravity_(0.0f, 9.81f),
                      world_(gravity_),
                      map_(world_) {
}

void Physics::update(const int frame_rate) {
    float32 timeStep = 1.0f / frame_rate;

    world_.Step(timeStep, VELOCITY_ITERATIONS_, POSITION_ITERATIONS_);
}

const bool Physics::allDead() const {
    bool ret = true;

    if (cars_.empty()) {
        return false;
    }

    for (auto &car : cars_){
        if (!car.isDead()) {
          ret = false;
        }
    }

    return ret;
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
    // store the initial parameters for future generations
    EvolutionaryAlgorithm::getInstance().setLastGenerationParameters(cars_parameters);

    cars_.clear();

    // don't mess with the order of constructed cars
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

void Physics::loadNewMap(const std::string &file_name) {
    map_ = Map(world_, file_name);

    notifyMap();
}

std::vector<double> Physics::getFinalDistances() const {
    std::vector<double> distances;
    for (const auto & car : cars_) {
        distances.push_back(car.getBestPosition());
        std::cout << car.getBestPosition() << std::endl;
    }

    return distances;
}

const std::vector<Car>& Physics::getCars() const {
    return cars_;
}

const Map& Physics::getMap() const {
    return map_;
}