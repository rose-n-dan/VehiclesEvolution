//!  A Car class .
/*!
  A class which represents the compound Car object.
  Class attributes consists of CarBody and Wheels object
  which are integrated through this class.
*/

#ifndef VEHICLESEVOLUTION_CAR_H
#define VEHICLESEVOLUTION_CAR_H

#include <chrono>

#include <Box2D/Box2D.h>

#include <Physics/CarBody.h>
#include <Physics/Wheel.h>
#include <EvolutionaryAlgorithm/CarParameters.h>
#include <Utils.h>

class Car {

public:
    //!  A Constructor of class.
    /*!
        The constructor creates a Car object specifying its position, parameters and world membership
        \param world specifies the world which Car object belong to.
        \param position defines the position of the Car object.
        \param car_parameters is an object, which gathers the parameters Car object should obtain.
    */
    Car(b2World &world, const b2Vec2 &position, const CarParameters &car_parameters);

    //!  A Method for getting a Car object's position.
    const b2Vec2& getPosition() const;
    //!  A Method for getting a Car object's best position.
    const double getBestPosition() const;
    //!  A Method for getting a Car object's velocity.
    const b2Vec2 getVelocity() const;
    //!  A Method for getting a Car object's front wheel position.
    const b2Vec2& getFrontWheelPosition() const;
    //!  A Method for getting a Car object's rear wheel position.
    const b2Vec2& getRearWheelPosition() const;
    //!  A Method for getting a Car object's front wheel radius.
    const double getFrontWheelRadius() const;
    //!  A Method for getting a Car object's rear wheel radius.
    const double getRearWheelRadius() const;
    //!  A Method for getting a Car object's car body shape.
    std::vector<b2Vec2> getCarBodyVertices() const;
    //!  A Method for getting a Car object's angular position.
    const double getAngle() const;
    //!  A Method for checking whether Car object is dead.
    const bool isDead() const;

private:
    //!  Private static constant expression
    /*!
        The attribute consists of information about max torque of the wheel motor.
    */
    static constexpr float MAX_MOTOR_TORQUE_ = 7000.0f;
    //!  Private static constant expression
    /*!
        The attribute consists of information about max speed of the wheel motor.
    */
    static constexpr float MOTOR_SPEED_ = 30.0f;

    //!  Private static constant expression
    /*!
        The attribute consists of information about time, after which Car which is not moving further, is regarding as dead.
    */
    static constexpr double TIME_STANDING_STILL_TO_DIE_S_{5};

    //!  Private static constant expression
    /*!
        The attribute consists of information about minimal distance that car needs to cover in one iteration not to be considered dead.
    */
    static constexpr double MIN_DIST_IN_ITERATION_{1e-5};

    //!  Private object
    /*!
        The attribute consists of object which represents front wheel.
    */
    Wheel front_wheel_;
    //!  Private object
    /*!
        The attribute consists of object which represents rear wheel.
    */
    Wheel rear_wheel_;
    //!  Private object
    /*!
        The attribute consists of object which represents car body.
    */
    CarBody car_body_;

    //!  Private object
    /*!
        The attribute consists of object which represents a front revolute joint parameters.
    */
    b2RevoluteJointDef front_joint_def_;
    //!  Private object
    /*!
        The attribute consists of object which represents a rear revolute joint parameters.
    */
    b2RevoluteJointDef rear_joint_def_;

    //!  Private object
    /*!
        The attribute consists of object which represents a front revolute joint.
    */
    b2RevoluteJoint *front_joint_;
    //!  Private object
    /*!
        The attribute consists of object which represents a rear revolute joint.
    */
    b2RevoluteJoint *rear_joint_;

    //!  Private variable
    /*!
        The attribute consists of information about whether the Car object is dead.
    */
    mutable bool is_dead_;
    //!  Private variable
    /*!
        The attribute consists of information about whether the Car object started its ride.
    */
    mutable bool started_;
    //!  Private variable
    /*!
        The attribute consists of information about time which passed since car had stopped.
    */
    mutable std::chrono::time_point<std::chrono::high_resolution_clock> stands_still_since_;
    //!  Private variable
    /*!
        The attribute consists of information about position of the Car object from the last iteration.
    */
    mutable double last_iteration_position_x_;
    //!  Private variable
    /*!
        The attribute consists of greatest x position.
    */
    mutable double best_position_x_{0};

};


#endif //VEHICLESEVOLUTION_CAR_H
