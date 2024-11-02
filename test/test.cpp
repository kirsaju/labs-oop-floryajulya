#include <gtest/gtest.h>
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"
#include "point.h"

TEST(HexagonTest, AreaCalculation) {
    Hexagon hex(
        Point(0, 0), Point(2, 0), Point(3, std::sqrt(3)),
        Point(2, 2 * std::sqrt(3)), Point(0, 2 * std::sqrt(3)),
        Point(-1, std::sqrt(3))
    );
    double expectedArea = (3 * std::sqrt(3)) * 2;

    double area = static_cast<double>(hex);

    EXPECT_NEAR(area, expectedArea, 1e-5);
}

TEST(HexagonTest, CenterCalculation) {
    Hexagon hex(
        Point(0, 0), Point(2, 0), Point(3, std::sqrt(3)),
        Point(2, 2 * std::sqrt(3)), Point(0, 2 * std::sqrt(3)),
        Point(-1, std::sqrt(3))
    );
    Point expectedCenter(1, std::sqrt(3));

    Point center = hex.Center();

    EXPECT_NEAR(center.getX(), expectedCenter.getX(), 1e-5);
    EXPECT_NEAR(center.getY(), expectedCenter.getY(), 1e-5);
}

TEST(HexagonTest, EqualityOperator) {
    Hexagon hex1(
        Point(0, 0), Point(1, 0), Point(1.5, std::sqrt(0.75)),
        Point(1, std::sqrt(3)), Point(0, std::sqrt(3)),
        Point(-0.5, std::sqrt(0.75))
    );
    Hexagon hex2 = hex1;

    EXPECT_TRUE(hex1 == hex2);
}

TEST(OctagonTest, AreaCalculation) {
    Octagon oct(
        Point(1, 0), Point(3, 0), Point(4, 1), Point(4, 3),
        Point(3, 4), Point(1, 4), Point(0, 3), Point(0, 1)
    );
    double expectedArea = 14.0;

    double area = static_cast<double>(oct);

    EXPECT_NEAR(area, expectedArea, 1e-5);
}

TEST(OctagonTest, CenterCalculation) {
    Octagon oct(
        Point(1, 0), Point(3, 0), Point(4, 1), Point(4, 3),
        Point(3, 4), Point(1, 4), Point(0, 3), Point(0, 1)
    );
    Point expectedCenter(2, 2);

    Point center = oct.Center();

    EXPECT_NEAR(center.getX(), expectedCenter.getX(), 1e-5);
}

TEST(OctagonTest, EqualityOperator) {
    Octagon oct1(
        Point(1, 0), Point(2, 0), Point(3, 1), Point(3, 2),
        Point(2, 3), Point(1, 3), Point(0, 2), Point(0, 1)
    );
    Octagon oct2 = oct1;

    EXPECT_TRUE(oct1 == oct2);
}

TEST(TriangleTest, AreaCalculation) {
    Triangle tri(
        Point(0, 0), Point(4, 0), Point(2, 3)
    );
    double expectedArea = 6.0;

    double area = static_cast<double>(tri);

    EXPECT_NEAR(area, expectedArea, 1e-5);
}

TEST(TriangleTest, CenterCalculation) {
    Triangle tri(
        Point(0, 0), Point(4, 0), Point(2, 3)
    );
    Point expectedCenter(2, 1);

    Point center = tri.Center();

    EXPECT_NEAR(center.getX(), expectedCenter.getX(), 1e-5);
}

TEST(TriangleTest, EqualityOperator) {
    Triangle tri1(
        Point(0, 0), Point(1, 0), Point(0, 1)
    );
    Triangle tri2 = tri1;

    EXPECT_TRUE(tri1 == tri2);
}
