#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"


void Vector::addElement(Element element)
{
    elements.push_back(element);
}

void Vector::print()
{
    std::cout << "[ ";

    for (unsigned int i = 0; i < elements.size(); i++) {
       std::cout << elements[i] << " ";
    }

    std::cout << "]";
    std::cout << std::endl;
}
