//
// Created by SpiritStudio on 01.12.18.
//

#include <Physics/Wheel.h>

Wheel::Wheel(b2World &world, double radius) {
    body_def_.type = b2_dynamicBody;
    body_ = world.CreateBody(&body_def_);

    dynamic_circle_.m_radius = static_cast<float32>(radius);

    fixture_def_.shape = &dynamic_circle_;

    // Set the box density to be non-zero, so it will be dynamic.
    fixture_def_.density = DENSITY_;

    // Override the default friction.
    fixture_def_.friction = FRICTION_;

    fixture_def_.restitution = RESTITIUTION_;

    // Collision detection masks from box2d
    fixture_def_.filter.categoryBits = 0x0001;
    fixture_def_.filter.maskBits = 0x0002;

    // Add the shape to the body.
    body_->CreateFixture(&fixture_def_);
}

b2Body* Wheel::getBody() {
    return body_;
}

const b2Vec2& Wheel::getPosition() const {
    return body_->GetPosition();
}

const double Wheel::getRadius() const {
    return dynamic_circle_.m_radius;
}

const double Wheel::getAngle() const {
    return body_->GetAngle();
}