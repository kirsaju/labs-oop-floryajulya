#include "array.h"
#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"
#include <iostream>

int main() {
    FigureArray<double> figures;

    figures.Add(std::make_unique<Triangle<double>>(Point<double>(0, 0), Point<double>(1, 0), Point<double>(0, 1)));
    figures.Add(std::make_unique<Hexagon<double>>(Point<double>(0, 0), Point<double>(1, 0), Point<double>(1, 1), 
                                                   Point<double>(0, 1), Point<double>(-1, 1), Point<double>(-1, 0)));
    figures.Add(std::make_unique<Octagon<double>>(Point<double>(0, 0), Point<double>(1, 0), Point<double>(1, 1), 
                                                   Point<double>(0, 1), Point<double>(-1, 1), Point<double>(-1, 0), 
                                                   Point<double>(-1, -1), Point<double>(0, -1)));

    std::cout << "Total area: " << figures.TotalArea() << std::endl;

    for (size_t i = 0; i < figures.Size(); ++i) {
        Figure<double>* figure = figures.Get(i);
        figure->Print(std::cout);
        std::cout << std::endl;
    }

    figures.Remove(0);

    std::cout << "Total area after removing the first figure: " << figures.TotalArea() << std::endl;

    return 0;
}
