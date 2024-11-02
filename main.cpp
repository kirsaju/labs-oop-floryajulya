#include <iostream>
#include <vector>
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"

int main() {
    std::vector<Figure*> figures;

    try {
        Hexagon hex(
            Point(0, 0), Point(1, 0), Point(1.5, std::sqrt(0.75)),
            Point(1, std::sqrt(3)), Point(0, std::sqrt(3)),
            Point(-0.5, std::sqrt(0.75))
        );
        std::cout << "Adding a hexagon: " << std::endl;
        hex.Print(std::cout);
        figures.push_back(new Hexagon(hex));

        Octagon oct(
            Point(1, 0), Point(2, 0), Point(3, 1), Point(3, 2),
            Point(2, 3), Point(1, 3), Point(0, 2), Point(0, 1)
        );
        std::cout << "Adding an octagon: " << std::endl;
        oct.Print(std::cout);
        figures.push_back(new Octagon(oct));

        Triangle tri(
            Point(0, 0), Point(4, 0), Point(2, 3)
        );
        std::cout << "\nAdding a triangle:" << std::endl;
        tri.Print(std::cout);
        figures.push_back(new Triangle(tri));

    } catch (const std::exception& e) {
        std::cout << "Error creating figure: " << e.what() << std::endl;
    }

    std::cout << "\n=== List of all figures ===\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        Figure* fig = figures[i];
        std::cout << "\nFigure #" << i + 1 << ":\n";
        fig->Print(std::cout);
        Point center = fig->Center();
        std::cout << "Center: (" << center.getX() << ", " << center.getY() << ")" << std::endl;
        double area = static_cast<double>(*fig);
        std::cout << "Area: " << area << "\n";
    }

    double totalArea = 0.0;
    for (const auto& fig : figures) {
        totalArea += static_cast<double>(*fig);
    }
    std::cout << "\nTotal area of all figures: " << totalArea << std::endl;

    std::cout << "\nRemoving the second figure (Octagon)...\n";
    if (figures.size() > 1) {
        delete figures[1];
        figures.erase(figures.begin() + 1);
    } else {
        std::cout << "No figure to remove at position 2." << std::endl;
    }

    std::cout << "\n=== List of figures after removal ===\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        Figure* fig = figures[i];
        std::cout << "\nFigure #" << i + 1 << ":\n";
        fig->Print(std::cout);
        Point center = fig->Center();
        std::cout << "Center: (" << center.getX() << ", " << center.getY() << ")" << std::endl;
        double area = static_cast<double>(*fig);
        std::cout << "Area: " << area << std::endl;
    }

    totalArea = 0.0;
    for (const auto& fig : figures) {
        totalArea += static_cast<double>(*fig);
    }
    std::cout << "Total area after removal: " << totalArea << std::endl;

    for (auto& fig : figures) {
        delete fig;
    }
    figures.clear();

    return 0;
}