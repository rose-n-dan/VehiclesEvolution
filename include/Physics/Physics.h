//!  A Physics class.
/*!
  A class which represents the Physics object.
  Class attributes consists of physical environment features like
  gravity force, cars container and map object.
*/

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
#include <EvolutionaryAlgorithm/EvolutionaryAlgorithm.h>

/**
 * Class implementing Factory, Singleton and Visitor design patterns.
 */

class Physics {

public:
    //!  A Physics copy and copy-assignment constructors are deleted.
    Physics(const Physics&) = delete;
    //!  A Physics copy and copy-assignment constructors are deleted.

    Physics& operator=(const Physics&) = delete;
    //!  A Method for design pattern of singleton.
    /*!
        The Method to recall the singleton instance of Physics object.
    */
    static Physics& getInstance() {
        static Physics physicsInstance;
        return physicsInstance;
    }

    //!  A Method for updating the physics after next iteration.
    /*!
        The Method is designed to update the parameters of the object after next interation was computed.
        \param frame_rate is a frequency rate at which consecutive images called frames appear and are displayed.
    */
    void update(const int frame_rate);
    //!  A Method for checking whether all cars from population are stuck.
    const bool allDead() const;

    //!  A Method for creating a vector of cars which will try to beat the track.
    void makeCars(const std::vector<CarParameters> &cars_parameters);
    //!  A Method for creating a single car object from parameters given.
    void makeCar(const CarParameters &car_parameters);
    void loadNewMap(const std::string &file_name);

    //!  A Method for updating the distances covered by lastly generated cars.
    std::vector<double> getFinalDistances() const;

    //!  A Methods implemented for Visitor design pattern purposes.
    /*!
        Methods were designed to notify other object about created Map, Cars and their position
    */
    void notifyCars();
    void notifyMap();
    void notifyCarsPositions();

    //!  A Method designed for getting the Car vector.
    const std::vector<Car>& getCars() const;
    //!  A Method designed for getting the Map object.
    const Map& getMap() const;

private:
    //!  A private class constructor.
    Physics();

    //!  Private static constant expression.
    /*!
        The attribute consists of information about number of velocity computing iterations per second.
    */
    static constexpr int32 VELOCITY_ITERATIONS_{16};
    //!  Private static constant expression
    /*!
        The attribute consists of information about number of position computing iterations per second.
    */
    static constexpr int32 POSITION_ITERATIONS_{16};

    //!  Private static constant
    /*!
        The attribute consists of information about starting position of created cars.
    */
    static const b2Vec2 CAR_STARTING_POSITION_;

    //!  Private vector
    /*!
        The attribute consists of information about gravity force.
    */
    b2Vec2 gravity_;
    //!  Private object
    /*!
        The attribute consists of object which represents a world.
    */
    b2World world_;
    //!  Private vector
    /*!
        The attribute consists of cars that were lastly generated
    */
    std::vector<Car> cars_;
    //!  Private object
    /*!
        The attribute consists of object which represents a map.
    */
    Map map_;

};

#endif //VEHICLESEVOLUTION_PHYSICS_H
