//
// Created by SpiritStudio on 03.12.18.
//

#ifndef VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
#define VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H

#include <string>
#include <functional>

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

class GraphicalUserInterface {

public:
    explicit GraphicalUserInterface(sf::RenderWindow &window, const int interface_width, const int interface_height);
    void setWindow();
    void setView(sf::View &view);
    void addWidgets();
    bool handleEvent(sf::Event &event);
    void draw();

    const int getInterfaceWidth() const;
    const bool isFollowingTheLeader() const;

private:
    std::shared_ptr<tgui::Button> addButton(const sf::Vector2f &position, const std::string &text);
    std::shared_ptr<tgui::CheckBox> addCheckbox(const sf::Vector2f &position, const std::string &text);

    static constexpr int BUTTON_HEIGHT_PIXELS_ = 40;
    static constexpr int BUTTON_WIDTH_PIXELS_ = 200;
    static constexpr float FIRST_BUTTON_VERTICAL_DISTANCE_PIXELS_ = 50;
    static constexpr int BUTTONS_VERTICAL_DISTANCE_PIXELS_ = 100;
    static constexpr int CHECKBOX_SIZE_PIXELS_ = 20;

    const int interface_width_, interface_height_;

    const sf::Color background_color_;

    sf::RenderWindow &window_;
    tgui::Gui gui_;
    sf::RectangleShape background_;

    bool follow_the_leader_checked_;
};


#endif //VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
