//
// Created by SpiritStudio on 28.11.18.
//

#include <Physics/Car.h>

Car::Car(b2World &world, const b2Vec2 &position, const CarParameters &car_parameters) :
                                                                is_dead_(false),
                                                                started_(false),
                                                                car_body_(world, position, car_parameters.car_body_),
                                                                front_wheel_(world, car_parameters.front_wheel_radius_),
                                                                rear_wheel_(world, car_parameters.rear_wheel_radius_) {
    front_joint_def_.bodyA = car_body_.getBody();
    front_joint_def_.bodyB = front_wheel_.getBody();
    front_joint_def_.collideConnected = false;
    front_joint_def_.localAnchorA.Set(car_parameters.front_joint_.x, car_parameters.front_joint_.y);
    front_joint_def_.localAnchorB.Set(0.0f, 0.0f);
    front_joint_def_.maxMotorTorque = MAX_MOTOR_TORQUE_;
    front_joint_def_.motorSpeed = MOTOR_SPEED_;
    front_joint_def_.enableMotor = true;

    front_joint_ = (b2RevoluteJoint*)world.CreateJoint(&front_joint_def_);

    rear_joint_def_.bodyA = car_body_.getBody();
    rear_joint_def_.bodyB = rear_wheel_.getBody();
    rear_joint_def_.collideConnected = false;
    rear_joint_def_.localAnchorA.Set(car_parameters.rear_joint_.x, car_parameters.rear_joint_.y);
    rear_joint_def_.localAnchorB.Set(0.0f, 0.0f);
    rear_joint_def_.maxMotorTorque = MAX_MOTOR_TORQUE_;
    rear_joint_def_.motorSpeed = MOTOR_SPEED_;
    rear_joint_def_.enableMotor = true;

    rear_joint_ = (b2RevoluteJoint*)world.CreateJoint(&rear_joint_def_);
}

const b2Vec2& Car::getPosition() const {
    return car_body_.getPosition();
}

const double Car::getBestPosition() const {
    return best_position_x_;
}

const b2Vec2 Car::getVelocity() const{
    return car_body_.getVelocity();
}

const b2Vec2& Car::getFrontWheelPosition() const {
    return front_wheel_.getPosition();
}

const b2Vec2& Car::getRearWheelPosition() const {
    return rear_wheel_.getPosition();
}

const double Car::getFrontWheelRadius() const {
    return front_wheel_.getRadius();
}

const double Car::getRearWheelRadius() const {
    return rear_wheel_.getRadius();
}

std::vector<b2Vec2> Car::getCarBodyVertices() const {
    return car_body_.getPolygon();
}

const double Car::getAngle() const {
    return car_body_.getAngle();
}

const bool Car::isDead() const {
    if (!is_dead_) {
        std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - stands_still_since_;

        if (utils::isNearlyZero(getPosition().x - last_iteration_position_x_, MIN_DIST_IN_ITERATION_)) {
            if ((elapsed.count()) > TIME_STANDING_STILL_TO_DIE_S_) {
                is_dead_ = true;
            }
        } else {
            stands_still_since_ = std::chrono::high_resolution_clock::now();
        }
        last_iteration_position_x_ = getPosition().x;

        if (best_position_x_ < getPosition().x) {
            best_position_x_ = getPosition().x;
        }
    }

    return is_dead_;
}
