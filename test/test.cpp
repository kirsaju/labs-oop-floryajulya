#include <gtest/gtest.h>
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"

TEST(HexagonTest, AreaCalculation) {
    Hexagon<double> hex(
        Point<double>(0, 0), Point<double>(2, 0), Point<double>(3, std::sqrt(3)),
        Point<double>(2, 2 * std::sqrt(3)), Point<double>(0, 2 * std::sqrt(3)),
        Point<double>(-1, std::sqrt(3))
    );
    double expectedArea = (3 * std::sqrt(3)) * 2;

    double area = static_cast<double>(hex);

    EXPECT_NEAR(area, expectedArea, 1e-5);
}

TEST(HexagonTest, CenterCalculation) {
    Hexagon<double> hex(
        Point<double>(0, 0), Point<double>(2, 0), Point<double>(3, std::sqrt(3)),
        Point<double>(2, 2 * std::sqrt(3)), Point<double>(0, 2 * std::sqrt(3)),
        Point<double>(-1, std::sqrt(3))
    );
    Point<double> expectedCenter(1, std::sqrt(3));

    Point<double> center = hex.Center();

    EXPECT_NEAR(center.x, expectedCenter.x, 1e-5);
    EXPECT_NEAR(center.y, expectedCenter.y, 1e-5);
}

TEST(HexagonTest, EqualityOperator) {
    Hexagon<double> hex1(
        Point<double>(0, 0), Point<double>(1, 0), Point<double>(1.5, std::sqrt(0.75)),
        Point<double>(1, std::sqrt(3)), Point<double>(0, std::sqrt(3)),
        Point<double>(-0.5, std::sqrt(0.75))
    );
    Hexagon<double> hex2 = hex1;

    EXPECT_TRUE(hex1 == hex2);
}

TEST(OctagonTest, AreaCalculation) {
    Octagon<double> oct(
        Point<double>(1, 0), Point<double>(3, 0), Point<double>(4, 1), Point<double>(4, 3),
        Point<double>(3, 4), Point<double>(1, 4), Point<double>(0, 3), Point<double>(0, 1)
    );
    double expectedArea = 14.0;

    double area = static_cast<double>(oct);

    EXPECT_NEAR(area, expectedArea, 1e-1);
}

TEST(OctagonTest, CenterCalculation) {
    Octagon<double> oct(
        Point<double>(1, 0), Point<double>(3, 0), Point<double>(4, 1), Point<double>(4, 3),
        Point<double>(3, 4), Point<double>(1, 4), Point<double>(0, 3), Point<double>(0, 1)
    );
    Point<double> expectedCenter(2, 2);

    Point<double> center = oct.Center();

    EXPECT_NEAR(center.x, expectedCenter.x, 1e-5);
    EXPECT_NEAR(center.y, expectedCenter.y, 1e-5);
}

TEST(OctagonTest, EqualityOperator) {
    Octagon<double> oct1(
        Point<double>(1, 0), Point<double>(2, 0), Point<double>(3, 1), Point<double>(3, 2),
        Point<double>(2, 3), Point<double>(1, 3), Point<double>(0, 2), Point<double>(0, 1)
    );
    Octagon<double> oct2 = oct1;

    EXPECT_TRUE(oct1 == oct2);
}

TEST(TriangleTest, AreaCalculation) {
    Triangle<double> tri(
        Point<double>(0, 0), Point<double>(4, 0), Point<double>(2, 3)
    );
    double expectedArea = 6.0;

    double area = static_cast<double>(tri);

    EXPECT_NEAR(area, expectedArea, 1e-5);
}

TEST(TriangleTest, CenterCalculation) {
    Triangle<double> tri(
        Point<double>(0, 0), Point<double>(4, 0), Point<double>(2, 3)
    );
    Point<double> expectedCenter(2, 1);

    Point<double> center = tri.Center();

    EXPECT_NEAR(center.x, expectedCenter.x, 1e-5);
    EXPECT_NEAR(center.y, expectedCenter.y, 1e-5);
}

TEST(TriangleTest, EqualityOperator) {
    Triangle<double> tri1(
        Point<double>(0, 0), Point<double>(1, 0), Point<double>(0, 1)
    );
    Triangle<double> tri2 = tri1;

    EXPECT_TRUE(tri1 == tri2);
}
