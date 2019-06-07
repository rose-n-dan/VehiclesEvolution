//!  A GraphicalUserInterface class.
/*!
  A class designed in order to create GUI.
  It consists information about widgets, buttons and background.
*/

#ifndef VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
#define VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H

#include <string>
#include <functional>

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

class GraphicalUserInterface {

public:
    //!  An explicit constructor of class.
    explicit GraphicalUserInterface(sf::RenderWindow &window, const int interface_width, const int interface_height);
    //!  A method for setting the application window.
    void setWindow();
    //!  A method for setting the displaying background.
    void setView(sf::View &view);
    //!  A method for setting and creating the button widget.
    void addWidgets();
    //!  A method for handling on-running events, like mouse-click.
    bool handleEvent(sf::Event &event);
    //!  A method for drawing widget on window.
    void draw();

    //!  Store the information about width of the displayed interface.
    const int getInterfaceWidth() const;

    //!  A method for checking whether the following leather button is checked.
    const bool isFollowingTheLeader() const;

private:
    //! Private pointer
    /*!
        Creates and stores the pointer to button specifying its text and position
    */
    std::shared_ptr<tgui::Button> addButton(const sf::Vector2f &position, const std::string &text);
    //! Private pointer
    /*!
        Creates and stores the pointer to checkbox specifying its text and position
    */
    std::shared_ptr<tgui::CheckBox> addCheckbox(const sf::Vector2f &position, const std::string &text);

    //! Static constant expression
    /*!
        A attribute consists of information about height of the button widgets in pixels
    */
    static constexpr int BUTTON_HEIGHT_PIXELS_ = 40;
    //! Static constant expression
    /*!
        A attribute consists of information about width of the button widgets in pixels
    */
    static constexpr int BUTTON_WIDTH_PIXELS_ = 200;
    //! Static constant expression
    /*!
        A attribute consists of information about distance of the button widgets from another button widgets in pixels
    */
    static constexpr float FIRST_BUTTON_VERTICAL_DISTANCE_PIXELS_ = 50;
    //! Static constant expression
    /*!
        A attribute consists of information about distance of the checkbox widgets from another checkbox widgets in pixels
    */
    static constexpr int BUTTONS_VERTICAL_DISTANCE_PIXELS_ = 100;
    //! Static constant expression
    /*!
        A attribute consists of information about size of the checkbox widgets in pixels
    */
    static constexpr int CHECKBOX_SIZE_PIXELS_ = 20;

    //! Constant expression
    /*!
        A attribute consists of information about width of the interface in pixels
    */
    const int interface_width_;
    //! Constant expression
    /*!
        A attribute consists of information about width height of the interface in pixels
    */
    const int interface_height_;

    //! Constant expression
    /*!
        A attribute consists of information color of the interface's background
    */
    const sf::Color background_color_;

    //! Private object
    /*!
        An object representing an application window
    */
    sf::RenderWindow &window_;
    //! Private object
    /*!
        An object representing an interface
    */
    tgui::Gui gui_;
    //! Private object
    /*!
        An object representing background of interface
    */
    sf::RectangleShape background_;

    //! Private variable.
    /*!
        Store the information about whether the Follow The Leader checkbox is checked.
    */
    bool follow_the_leader_checked_{false};
};


#endif //VEHICLESEVOLUTION_GRAPHICALUSERINTERFACE_H
