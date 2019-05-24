//
// Created by SpiritStudio on 29.11.18.
//

#include <iostream>

#include <Graphics/Graphics.h>
#include <include/Graphics/Graphics.h>


Graphics::Graphics() : settings_(0, 0, 8),
                       view_action_(sf::FloatRect(0.0f, 0.0f, WINDOW_WIDTH_PIXELS_, WINDOW_HEIGHT_PIXELS_)),
                       view_gui_(view_action_),
                       window_(sf::VideoMode(WINDOW_WIDTH_PIXELS_, WINDOW_HEIGHT_PIXELS_),
                               "Vehicles Evolution Simulation", sf::Style::Default, settings_),
                       gui_(window_, INTERFACE_WIDTH_PIXELS_, WINDOW_HEIGHT_PIXELS_),
                       clock_(),
                       background_color_(51,204,153) {
    window_.setView(view_action_);
    gui_.setWindow();
    gui_.addWidgets();
}

void Graphics::newCars(const std::vector<Car> &cars) {
    cars_graphics_.clear();

    for (const auto &car : cars)
    {
        cars_graphics_.push_back(generateGraphics(car));
    }
}

void Graphics::newMap(const Map &map) {
    auto polyline = map.getPolyline();

    if (!polyline.empty())
    {
        // Needed to duplicate first vertex as the end, to make Map a closed ring

        map_graphic_.resetPolyline(polyline.size() + 1);

        int i = 0;

        auto first_vertex = polyline.at(0);
        for (const auto &vertex : polyline)
        {
            map_graphic_.setVertex(i, sf::Vector2f(PIXELS_PER_METER_ * vertex.x, PIXELS_PER_METER_ * vertex.y));
            ++i;
        }

        map_graphic_.setVertex(i, sf::Vector2f(PIXELS_PER_METER_ * first_vertex.x, PIXELS_PER_METER_ * first_vertex.y));
    }

}

void Graphics::newCarsPositions(const std::vector<Car> &cars) {
    unsigned long i = 0;
    for (const auto &car : cars)
    {
        auto angle = static_cast<float>(car.getAngle() * 180.0f / M_PI);
        sf::Vector2f position = sf::Vector2f(PIXELS_PER_METER_ * car.getPosition().x,
                                             PIXELS_PER_METER_ * car.getPosition().y);
        cars_graphics_.at(i).setPositionAndAngle(position, angle);

        sf::Vector2f front_wheel_position = sf::Vector2f(PIXELS_PER_METER_ * car.getFrontWheelPosition().x,
                                                         PIXELS_PER_METER_ * car.getFrontWheelPosition().y);
        cars_graphics_.at(i).setFrontWheelPosition(front_wheel_position);

        sf::Vector2f rear_wheel_position = sf::Vector2f(PIXELS_PER_METER_ * car.getRearWheelPosition().x,
                                                        PIXELS_PER_METER_ * car.getRearWheelPosition().y);
        cars_graphics_.at(i).setRearWheelPosition(rear_wheel_position);

        ++i;
    }
}

const bool Graphics::isWindowOpen() const {
    return window_.isOpen();
}

void Graphics::handleEvents() {
    sf::Event event;
    while (window_.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window_.close();

        if (event.type == sf::Event::Resized)
        {
            auto visible_area = sf::Vector2f(event.size.width, event.size.height);
            view_gui_.setSize(visible_area);
            view_gui_.setCenter(event.size.width / 2.0f, event.size.height / 2.0f);
            view_action_.setSize(visible_area);
            gui_.setView(view_gui_);
        }
        gui_.handleEvent(event);
    }
}

void Graphics::draw() {
    window_.clear(background_color_);
    followTheLeader();
    window_.draw(map_graphic_);

    for (const auto &car_graphics : cars_graphics_)
    {
        window_.draw(car_graphics);
    }

    window_.setView(view_gui_);
    gui_.draw();

    window_.display();
}

void Graphics::ensureConstantFrameRate(const int frameRate) {
    time_ = clock_.restart();
    sf::Time time_for_sleep = sf::milliseconds(static_cast<int>(1000.0f / static_cast<float>(frameRate))) - time_;
    sf::sleep(time_for_sleep);
    time_ = clock_.restart();
}

void Graphics::restartClock() {
    time_ = clock_.restart();
}

void Graphics::followTheLeader() {
    if (gui_.isFollowingTheLeader() && !cars_graphics_.empty())
    {
        sf::Vector2f new_leader_position(std::numeric_limits<float>::lowest(), 0.0f);

        for (const auto &car : cars_graphics_) {
            if (car.getPosition().x >= new_leader_position.x)
                new_leader_position = car.getPosition();
        }

        view_action_.setCenter(new_leader_position -
                               sf::Vector2f(static_cast<float>(gui_.getInterfaceWidth()), 0.0f) / 2.0f);
    }

    window_.setView(view_action_);
}

CarGraphics Graphics::generateGraphics(const Car &car) {
    auto vertices = car.getCarBodyVertices();
    std::vector<sf::Vector2f> sf_vertices;
    sf_vertices.reserve(vertices.size());

    for (const auto &vertex : vertices)
    {
        sf_vertices.emplace_back(vertex.x * PIXELS_PER_METER_, vertex.y * PIXELS_PER_METER_);
    }

    return CarGraphics(sf_vertices, car.getFrontWheelRadius() * PIXELS_PER_METER_,
                       car.getRearWheelRadius() * PIXELS_PER_METER_);
}
