#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"

using ElementList = Vector::ElementList;

Vector::Vector()
{
    //
}

Vector::Vector(Element e1)
{
    addElement(e1);
}

Vector::Vector(Element e1, Element e2)
{
    addElement(e1);
    addElement(e2);
}

Vector::Vector(Element e1, Element e2, Element e3)
{
    addElement(e1);
    addElement(e2);
    addElement(e3);
}

void Vector::addElement(Element element)
{
    elements.push_back(element);
}

ElementList Vector::getElements()
{
    return elements;
}

Vector Vector::add(Vector const vectorB)
{
    ElementList elementsA = elements;
    ElementList elementsB = vectorB.elements;

    Vector vectorC;

    for (unsigned int i = 0; i < elementsA.size(); i++) {
        vectorC.addElement(elementsA[i] + elementsB[i]);
    }

    return vectorC;
}

Vector Vector::subtract(Vector const vectorB)
{
    ElementList elementsA = elements;
    ElementList elementsB = vectorB.elements;

    Vector vectorC;

    for (unsigned int i = 0; i < elementsA.size(); i++) {
        vectorC.addElement(elementsA[i] - elementsB[i]);
    }

    return vectorC;
}

Vector Vector::multiply(Scalar const scalar)
{
    ElementList elementsA = elements;

    Vector vectorC;

    for (unsigned int i = 0; i < elementsA.size(); i++) {
        vectorC.addElement(elementsA[i] * scalar);
    }

    return vectorC;
}

Vector Vector::multiply(Vector const vectorB)
{
    ElementList elementsA = elements;
    ElementList elementsB = vectorB.elements;

    Vector vectorC;

    for (unsigned int i = 0; i < elementsA.size(); i++) {
        vectorC.addElement(elementsA[i] * elementsB[i]);
    }

    return vectorC;
}

double Vector::dotProduct(Vector const vectorB)
{
    ElementList elementsA = elements;
    ElementList elementsB = vectorB.elements;

    double result = 0;

    for (unsigned int i = 0; i < elementsA.size(); i++) {
        result += elementsA[i] * elementsB[i];
    }

    return result;
}

Vector Vector::crossProduct(Vector const vectorB)
{
    ElementList elementsA = elements;
    ElementList elementsB = vectorB.elements;

    Vector vectorC;

    for (unsigned int a1 = 1; a1 < elementsA.size(); a1++) {
        unsigned int b1 = a1 + 1;

        int lastElementIndex = elements.size() - 1;

        if (a1 == lastElementIndex) {
            b1 = 0;
        }

        vectorC.addElement(
            elementsA[a1] * elementsB[b1] - elementsA[b1] * elementsB[a1]
        );
    }

    vectorC.addElement(elementsA[0] * elementsB[1] - elementsA[1] * elementsB[0]);

    return vectorC;
}

bool Vector::equals(Vector const vectorB) const
{
    ElementList elementsA = elements;
    ElementList elementsB = vectorB.elements;

    for (unsigned int i = 0; i < elementsA.size(); i++) {
        if (elementsA[i] != elementsB[i]) {
            return false;
        }
    }

    return true;
}
