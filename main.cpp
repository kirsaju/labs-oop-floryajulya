#include <iostream>
#include "include/list.h"
#include "include/allocator.h"

struct Rectangle {
    double a;
    double b;

    Rectangle(double r, double i) : a{r}, b{i}{}
};

std::ostream& operator<< (std::ostream& os, const Rectangle &complexNumber){
    std::cout << "(" << complexNumber.a << "; " << complexNumber.b << ")";
    return os;
}


int main()
{

    StaticStruct<1024> resource; 

    ListAllocator<int> allocator(&resource); 

    LinkedList<int> list(allocator);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.push_back(5);
    list.print();
    list.pop_back();
    list.pop_front();
    list.print();

    ListAllocator<Rectangle> allocatorRects(&resource); 

    LinkedList<Rectangle> listComplex(allocatorRects);
    listComplex.push_front(Rectangle(1, 2));
    listComplex.push_front(Rectangle(2, 2));
    listComplex.push_front(Rectangle(3, 2));
    listComplex.push_front(Rectangle(4, 2));
    listComplex.push_back(Rectangle(5, 2));
    listComplex.print();
    listComplex.pop_back();
    listComplex.pop_front();
    listComplex.print();


}
