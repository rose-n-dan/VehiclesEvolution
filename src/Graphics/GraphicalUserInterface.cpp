//
// Created by SpiritStudio on 03.12.18.
//

#include <Graphics/GraphicalUserInterface.h>
#include <Physics/Physics.h>

GraphicalUserInterface::GraphicalUserInterface(sf::RenderWindow &window, const int interface_width,
                                               const int interface_height)
    : window_(window)
    , interface_width_(interface_width)
    , interface_height_(interface_height)
    , background_color_(255, 153, 0, 50)
{
    background_.setSize(sf::Vector2f(interface_width_, interface_height_));
    background_.setPosition(sf::Vector2f(0.0f, 0.0f));
    background_.setFillColor(background_color_);
}

bool GraphicalUserInterface::handleEvent(sf::Event &event){
    return gui_.handleEvent(event);
}

void GraphicalUserInterface::setWindow() {
    gui_.setTarget(window_);
}

void GraphicalUserInterface::setView(sf::View &view) {
    background_.setSize(sf::Vector2f(interface_width_, view.getSize().y));
    gui_.setView(view);
}

void GraphicalUserInterface::addWidgets() {
    const float left_side_offset = (interface_width_ - BUTTON_WIDTH_PIXELS_)/2;
    float vertical_distance = FIRST_BUTTON_VERTICAL_DISTANCE_PIXELS_;

    auto button = addButton(sf::Vector2f(left_side_offset, vertical_distance), "Exit");
    button->connect("pressed", [&](){ window_.close(); });
    vertical_distance += BUTTONS_VERTICAL_DISTANCE_PIXELS_;

    // TODO: Change make functions into making from Evolutional Algorithm
    std::vector<CarParameters> params_example;
    params_example.emplace_back();

    button = addButton(sf::Vector2f(left_side_offset, vertical_distance), "Make new generation");
    button->connect("pressed", &Physics::makeCars, &Physics::getInstance(), params_example);
    vertical_distance += BUTTONS_VERTICAL_DISTANCE_PIXELS_;

    CarParameters param_example;
    button = addButton(sf::Vector2f(left_side_offset, vertical_distance), "Add new car");
    button->connect("pressed", &Physics::makeCar, &Physics::getInstance(), param_example);
    vertical_distance += BUTTONS_VERTICAL_DISTANCE_PIXELS_;

    auto checkbox = addCheckbox(sf::Vector2f(left_side_offset, vertical_distance), "Follow the leader");
    checkbox->connect("checked", [&](){ follow_the_leader_checked_ = true; });
    checkbox->connect("unchecked", [&](){ follow_the_leader_checked_ = false; });
}

std::shared_ptr<tgui::Button> GraphicalUserInterface::addButton(const sf::Vector2f &position, const std::string &text) {
    auto button = tgui::Button::create(text);
    button->setSize(BUTTON_WIDTH_PIXELS_, BUTTON_HEIGHT_PIXELS_);
    button->setPosition(position);
    gui_.add(button);

    return button;
}


std::shared_ptr<tgui::CheckBox> GraphicalUserInterface::addCheckbox(const sf::Vector2f &position,
                                                                    const std::string &text) {
    auto checkbox = tgui::CheckBox::create(text);
    checkbox->setSize(CHECKBOX_SIZE_PIXELS_, CHECKBOX_SIZE_PIXELS_);
    checkbox->setPosition(position);
    gui_.add(checkbox);

    return checkbox;
}


void GraphicalUserInterface::draw() {
    window_.draw(background_);
    gui_.draw();
}

const int GraphicalUserInterface::getInterfaceWidth() const {
    return interface_width_;
}

const bool GraphicalUserInterface::isFollowingTheLeader() const {
    return follow_the_leader_checked_;
}