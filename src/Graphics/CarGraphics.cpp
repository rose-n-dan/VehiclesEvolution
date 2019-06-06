//
// Created by SpiritStudio on 30.11.18.
//

#include <cmath>

#include <Graphics/CarGraphics.h>
#include <include/Graphics/CarGraphics.h>


CarGraphics::CarGraphics(const std::vector<sf::Vector2f> &vertices,
                         double front_wheel_radius, double rear_wheel_radius) : car_body_color_(255,204,0),
                                                                                wheel_color_(255,51,102) {
    car_body_graphics_.setPointCount(vertices.size());
    car_body_graphics_.setOrigin(sf::Vector2f(0.0f, 0.0f));

    size_t index = 0;
    for (const auto &vertex : vertices)
    {
        car_body_graphics_.setPoint(index, vertex);
        ++index;
    }

    car_body_graphics_.setFillColor(car_body_color_);
    car_body_graphics_.setPosition(0.0f, 0.0f);

    auto rear_wheel_radius_f = static_cast<float>(rear_wheel_radius);
    wheel_rear_.setRadius(rear_wheel_radius_f);
    wheel_rear_.setOrigin(rear_wheel_radius_f, rear_wheel_radius_f);
    wheel_rear_.setFillColor(wheel_color_);

    auto front_wheel_radius_f = static_cast<float>(front_wheel_radius);
    wheel_front_.setRadius(front_wheel_radius_f);
    wheel_front_.setOrigin(front_wheel_radius_f, front_wheel_radius_f);
    wheel_front_.setFillColor(wheel_color_);
}

void CarGraphics::setPositionAndAngle(const sf::Vector2f &position, float angle) {
    car_body_graphics_.setPosition(position);
    car_body_graphics_.setRotation(angle);
}

void CarGraphics::setFrontWheelPosition(const sf::Vector2f &position) {
    wheel_front_.setPosition(position);
}

void CarGraphics::setRearWheelPosition(const sf::Vector2f &position) {
    wheel_rear_.setPosition(position);
}

const sf::Vector2f& CarGraphics::getPosition() const {
    return car_body_graphics_.getPosition();
}

const sf::ConvexShape& CarGraphics::getCarBodyGraphics() const {
    return car_body_graphics_;
}

const sf::CircleShape& CarGraphics::getFrontWheel() const {
    return wheel_front_;
}

const sf::CircleShape& CarGraphics::getRearWheel() const {
    return wheel_rear_;
}

void CarGraphics::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(car_body_graphics_, states);
    target.draw(wheel_front_, states);
    target.draw(wheel_rear_, states);
}
