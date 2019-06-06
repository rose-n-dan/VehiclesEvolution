//
// Created by dan on 06/06/19.
//

#include <fstream>

#include <gtest/gtest.h>

#include <Physics/Physics.h>
#include <Graphics/Graphics.h>


TEST(HolisticTests, Map)
{
    std::string map_file_name = "../data/test_map.txt";
    std::ifstream map_file(map_file_name, std::ios::in);
    double x, y;
    int i = 0;

    Physics::getInstance().loadNewMap(map_file_name);

    while (map_file >> x >> y)
    {
        // Testing if physical representation of map is consistent with the file
        EXPECT_FLOAT_EQ(Physics::getInstance().getMap().getPolyline().at(i).x, x);
        EXPECT_FLOAT_EQ(Physics::getInstance().getMap().getPolyline().at(i).y, y);

        // Testing if graphical representation of map is consistent with the file
        EXPECT_FLOAT_EQ(Graphics::getInstance().getMapGraphicsVertexInMeters(i).first, x);
        EXPECT_FLOAT_EQ(Graphics::getInstance().getMapGraphicsVertexInMeters(i).second, y);
        ++i;
    }
}