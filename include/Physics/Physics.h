//
// Created by SpiritStudio on 28.11.18.
//

#ifndef VEHICLESEVOLUTION_PHYSICS_H
#define VEHICLESEVOLUTION_PHYSICS_H

#include <vector>
#include <memory>
#include <iostream>

#include <Box2D/Box2D.h>

#include <Physics/Car.h>
#include <Physics/Map.h>
#include <Graphics/Graphics.h>
#include <EvolutionaryAlgorithm/CarParameters.h>

/**
 * Class implementing Factory and Singleton design patterns
 */

class Physics {

public:
    Physics(const Physics&) = delete;
    Physics& operator=(const Physics&) = delete;

    static Physics& getInstance() {
        static Physics physicsInstance;
        return physicsInstance;
    }

    void update(const int frame_rate);
    const bool allDead() const;

    void makeCars(const std::vector<CarParameters> &cars_parameters);
    void makeCar(const CarParameters &car_parameters);

    void notifyCars();
    void notifyMap();
    void notifyCarsPositions();

    const std::vector<Car>& getCars() const;
    const Map& getMap() const;

private:
    Physics();

    static const b2Vec2 CAR_STARTING_POSITION_;

    b2Vec2 gravity_;
    b2World world_;
    std::vector<Car> cars_;
    Map map_;

};

#endif //VEHICLESEVOLUTION_PHYSICS_H
