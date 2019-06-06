//
// Created by dan on 06/06/19.
//

#include <gtest/gtest.h>

#include <Physics/Physics.h>
#include <Graphics/Graphics.h>


TEST(HolisticTests, Car)
{
    // Preparing car attributes
    double front_wheel_radius = 1.2;
    double rear_wheel_radius = 3.4;

    std::vector<b2Vec2> car_body;
    car_body.emplace_back(-1, 0);
    car_body.emplace_back(0, 1);
    car_body.emplace_back(1, 1);
    car_body.emplace_back(2, 0);
    car_body.emplace_back(1, -1);
    car_body.emplace_back(0, -1);

    b2Vec2 front_joint = car_body.at(4);
    b2Vec2 rear_joint = car_body.at(5);


    // Testing CarParameters constructor
    CarParameters car_parameters(front_wheel_radius, rear_wheel_radius, car_body, front_joint, rear_joint);

    EXPECT_FLOAT_EQ(car_parameters.front_wheel_radius_, front_wheel_radius);
    EXPECT_FLOAT_EQ(car_parameters.rear_wheel_radius_, rear_wheel_radius);

    int i = 0;
    for (const auto &v : car_parameters.car_body_) {
        EXPECT_FLOAT_EQ(v.x, car_body.at(i).x);
        EXPECT_FLOAT_EQ(v.y, car_body.at(i).y);
        ++i;
    }

    EXPECT_FLOAT_EQ(car_parameters.front_joint_.x, 1);
    EXPECT_FLOAT_EQ(car_parameters.front_joint_.y, -1);
    EXPECT_FLOAT_EQ(car_parameters.rear_joint_.x, 0);
    EXPECT_FLOAT_EQ(car_parameters.rear_joint_.y, -1);


    // Testing makeCar method
    Physics::getInstance().makeCar(car_parameters);
    Car car = Physics::getInstance().getCars().at(0);

    EXPECT_FLOAT_EQ(car.getFrontWheelRadius(), front_wheel_radius);
    EXPECT_FLOAT_EQ(car.getRearWheelRadius(), rear_wheel_radius);

    i = 0;
    for (const auto &v : car.getCarBodyVertices()) {
        EXPECT_FLOAT_EQ(v.x, car_body.at(i).x);
        EXPECT_FLOAT_EQ(v.y, car_body.at(i).y);
        ++i;
    }


    // Testing makeCars method for two sets of parameters
    std::vector<CarParameters> multiple_car_parameters;
    multiple_car_parameters.push_back(car_parameters);
    multiple_car_parameters.push_back(car_parameters);

    Physics::getInstance().makeCars(multiple_car_parameters);

    EXPECT_EQ(Physics::getInstance().getCars().size(), 2);
    for (const auto &car : Physics::getInstance().getCars()) {
        EXPECT_FLOAT_EQ(car.getFrontWheelRadius(), front_wheel_radius);
        EXPECT_FLOAT_EQ(car.getRearWheelRadius(), rear_wheel_radius);

        i = 0;
        for (const auto &v : car.getCarBodyVertices()) {
            EXPECT_FLOAT_EQ(v.x, car_body.at(i).x);
            EXPECT_FLOAT_EQ(v.y, car_body.at(i).y);
            ++i;
        }
    }

    // Testing if graphical representation of Car is consistent with the physical
    CarGraphics car_graphics = Graphics::getInstance().getCarGraphics().at(0);

    EXPECT_FLOAT_EQ(Graphics::convertPixelsToMeters(car_graphics.getFrontWheel().getRadius()), front_wheel_radius);
    EXPECT_FLOAT_EQ(Graphics::convertPixelsToMeters(car_graphics.getRearWheel().getRadius()), rear_wheel_radius);

    for (i = 0; i < car_body.size(); ++i) {
        EXPECT_FLOAT_EQ(Graphics::convertPixelsToMeters(car_graphics.getCarBodyGraphics().getPoint(i).x),
                car_body.at(i).x);
        EXPECT_FLOAT_EQ(Graphics::convertPixelsToMeters(car_graphics.getCarBodyGraphics().getPoint(i).y),
                car_body.at(i).y);
    }
}
