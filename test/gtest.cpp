//
// Created by SpiritStudio on 04.12.18.
//

#include <math.h>

#include <gtest/gtest.h>

#include <Physics/Physics.h>

TEST(ExamplePhysicsTest, Physics) {
    EXPECT_FALSE(Physics::getInstance().allDead());
}

TEST(CarTests, Tests) {
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

    EXPECT_EQ(car_parameters.car_body_.at(0).x, -1);
    EXPECT_EQ(car_parameters.car_body_.at(0).y, 0);
    EXPECT_EQ(car_parameters.car_body_.at(1).x, 0);
    EXPECT_EQ(car_parameters.car_body_.at(1).y, 1);
    EXPECT_EQ(car_parameters.car_body_.at(2).x, 1);
    EXPECT_EQ(car_parameters.car_body_.at(2).y, 1);
    EXPECT_EQ(car_parameters.car_body_.at(3).x, 2);
    EXPECT_EQ(car_parameters.car_body_.at(3).y, 0);
    EXPECT_EQ(car_parameters.car_body_.at(4).x, 1);
    EXPECT_EQ(car_parameters.car_body_.at(4).y, -1);
    EXPECT_EQ(car_parameters.car_body_.at(5).x, 0);
    EXPECT_EQ(car_parameters.car_body_.at(5).y, -1);

    EXPECT_EQ(car_parameters.front_joint_.x, 1);
    EXPECT_EQ(car_parameters.front_joint_.y, -1);
    EXPECT_EQ(car_parameters.rear_joint_.x, 0);
    EXPECT_EQ(car_parameters.rear_joint_.y, -1);


    // Testing makeCar method
    Physics::getInstance().makeCar(car_parameters);
    Car car = Physics::getInstance().getCars().at(0);

    EXPECT_FLOAT_EQ(car.getFrontWheelRadius(), front_wheel_radius);
    EXPECT_FLOAT_EQ(car.getRearWheelRadius(), rear_wheel_radius);

    EXPECT_EQ(car.getCarBodyVertices().at(0).x, -1);
    EXPECT_EQ(car.getCarBodyVertices().at(0).y, 0);
    EXPECT_EQ(car.getCarBodyVertices().at(1).x, 0);
    EXPECT_EQ(car.getCarBodyVertices().at(1).y, 1);
    EXPECT_EQ(car.getCarBodyVertices().at(2).x, 1);
    EXPECT_EQ(car.getCarBodyVertices().at(2).y, 1);
    EXPECT_EQ(car.getCarBodyVertices().at(3).x, 2);
    EXPECT_EQ(car.getCarBodyVertices().at(3).y, 0);
    EXPECT_EQ(car.getCarBodyVertices().at(4).x, 1);
    EXPECT_EQ(car.getCarBodyVertices().at(4).y, -1);
    EXPECT_EQ(car.getCarBodyVertices().at(5).x, 0);
    EXPECT_EQ(car.getCarBodyVertices().at(5).y, -1);


    // Testing makeCars method for two sets of parameters
    std::vector<CarParameters> multiple_car_parameters;
    multiple_car_parameters.push_back(car_parameters);
    multiple_car_parameters.push_back(car_parameters);

    Physics::getInstance().makeCars(multiple_car_parameters);

    EXPECT_EQ(Physics::getInstance().getCars().size(), 2);
    for (const auto &car : Physics::getInstance().getCars()) {
        EXPECT_FLOAT_EQ(car.getFrontWheelRadius(), front_wheel_radius);
        EXPECT_FLOAT_EQ(car.getRearWheelRadius(), rear_wheel_radius);

        EXPECT_EQ(car.getCarBodyVertices().at(0).x, -1);
        EXPECT_EQ(car.getCarBodyVertices().at(0).y, 0);
        EXPECT_EQ(car.getCarBodyVertices().at(1).x, 0);
        EXPECT_EQ(car.getCarBodyVertices().at(1).y, 1);
        EXPECT_EQ(car.getCarBodyVertices().at(2).x, 1);
        EXPECT_EQ(car.getCarBodyVertices().at(2).y, 1);
        EXPECT_EQ(car.getCarBodyVertices().at(3).x, 2);
        EXPECT_EQ(car.getCarBodyVertices().at(3).y, 0);
        EXPECT_EQ(car.getCarBodyVertices().at(4).x, 1);
        EXPECT_EQ(car.getCarBodyVertices().at(4).y, -1);
        EXPECT_EQ(car.getCarBodyVertices().at(5).x, 0);
        EXPECT_EQ(car.getCarBodyVertices().at(5).y, -1);
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
