#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"


void Vector::addElement(Element element)
{
    elements.push_back(element);
}

Vector Vector::add(Vector vectorB)
{
    std::vector<Element> elementsA = elements;
    std::vector<Element> elementsB = vectorB.elements;

    Vector vectorC;

    for (unsigned int i = 0; i < elementsA.size(); i++) {
        vectorC.addElement(elementsA[i] + elementsB[i]);
    }

    return vectorC;
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
