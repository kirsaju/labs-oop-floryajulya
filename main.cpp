#include <iostream>
#include "../include/eleven.h"

int main()
{
    try
    {
        std::string el1, el2;
        std::cout << "Enter first eleven number: ";
        std::cin >> el1;

        std::cout << "Enter second eleven number: ";
        std::cin >> el2;

        Eleven Numb1(el1);
        Eleven Numb2(el2);

        Numb1 += Numb2;

        std::cout << "Result of addition: ";
        for (size_t i = 0; i < Numb1.getSize(); ++i)
        {
            std::cout << Numb1.getData()[i];
        }
        std::cout << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}