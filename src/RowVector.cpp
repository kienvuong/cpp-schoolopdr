#include <iostream>
#include "RowVector.hpp"

RowVector::RowVector() : Vector() {}
RowVector::RowVector(Element e1) : Vector(e1) {}
RowVector::RowVector(Element e1, Element e2) : Vector(e1, e2) {}
RowVector::RowVector(Element e1, Element e2, Element e3) : Vector(e1, e2, e3) {}
RowVector::RowVector(Vector const &v) : Vector(v) {}
RowVector::RowVector(ColumnVector const &v) : Vector(v) {}

RowVector RowVector::operator+(Vector const vectorB)
{
    return add(vectorB);
}

RowVector RowVector::operator-(Vector const vectorB)
{
    return subtract(vectorB);
}

RowVector RowVector::operator*(Scalar const scalar)
{
    return multiply(scalar);
}

RowVector RowVector::operator*(Vector const vectorB)
{
    return multiply(vectorB);
}

bool RowVector::operator==(RowVector const vectorB) const
{
    return equals(vectorB);
}

bool RowVector::operator!=(RowVector const vectorB) const
{
    return !equals(vectorB);
}

ColumnVector RowVector::transpose()
{
    // ColumnVector columnVector;

    // for (int i = 0; i < elements.size() - 1; i++) {
    //     columnVector.addElement(elements[i]);
    // }

    // return columnVector;

    return (*this);
}

void RowVector::print()
{
    std::cout << "[ ";

    for (unsigned int i = 0; i <= elements.size() - 1; i++) {
        std::cout << elements[i];

        std::cout << " ";
    }

    std::cout << "]" << std::endl;
}

void RowVector::println()
{
    print();
    std::cout << std::endl;
}
