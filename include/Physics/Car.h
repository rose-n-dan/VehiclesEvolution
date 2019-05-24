//
// Created by SpiritStudio on 28.11.18.
//

#ifndef VEHICLESEVOLUTION_CAR_H
#define VEHICLESEVOLUTION_CAR_H

#include <Box2D/Box2D.h>

#include <Physics/CarBody.h>
#include <Physics/Wheel.h>
#include <EvolutionaryAlgorithm/CarParameters.h>

class Car {

public:
    Car(b2World &world, const b2Vec2 &position, const CarParameters &car_parameters);

    const b2Vec2& getPosition() const;
    const b2Vec2& getFrontWheelPosition() const;
    const b2Vec2& getRearWheelPosition() const;
    const double getFrontWheelRadius() const;
    const double getRearWheelRadius() const;
    std::vector<b2Vec2> getCarBodyVertices() const;
    const double getAngle() const;
    const bool isDead() const;

private:
    static constexpr float MAX_MOTOR_TORQUE_ = 100000.0f;
    static constexpr float MOTOR_SPEED_ = 40.0f;

    Wheel front_wheel_, rear_wheel_;
    CarBody car_body_;

    b2RevoluteJointDef front_joint_def_, rear_joint_def_;
    b2RevoluteJoint *front_joint_;
    b2RevoluteJoint *rear_joint_;

    bool is_dead_;

};


#endif //VEHICLESEVOLUTION_CAR_H
