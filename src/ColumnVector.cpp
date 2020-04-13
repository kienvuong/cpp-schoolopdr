#include <iostream>
#include "ColumnVector.hpp"

ColumnVector::ColumnVector() : Vector() {}
ColumnVector::ColumnVector(Element e1) : Vector(e1) {}
ColumnVector::ColumnVector(Element e1, Element e2) : Vector(e1, e2) {}
ColumnVector::ColumnVector(Element e1, Element e2, Element e3) : Vector(e1, e2, e3) {}
ColumnVector::ColumnVector(Vector const &v) : Vector(v) {}
ColumnVector::ColumnVector(RowVector const &v) : Vector(v) {}

ColumnVector ColumnVector::operator+(Vector const vectorB)
{
    return add(vectorB);
}

ColumnVector ColumnVector::operator-(Vector const vectorB)
{
    return subtract(vectorB);
}

ColumnVector ColumnVector::operator*(Scalar const scalar)
{
    return multiply(scalar);
}

ColumnVector ColumnVector::operator*(Vector const vectorB)
{
    return multiply(vectorB);
}

bool ColumnVector::operator==(ColumnVector const vectorB) const
{
    return equals(vectorB);
}

bool ColumnVector::operator!=(ColumnVector const vectorB) const
{
    return !equals(vectorB);
}

RowVector ColumnVector::transpose()
{
    // RowVector rowVector;

    // for (int i = 0; i < elements.size() - 1; i++) {
    //     rowVector.addElement(elements[i]);
    // }

    // return rowVector;

    return (*this);
}

void ColumnVector::print()
{
    for (unsigned int i = 0; i <= elements.size() - 1; i++) {
        std::cout << "| " << elements[i] << " |" << std::endl;
    }
}

void ColumnVector::println()
{
    print();
    std::cout << std::endl;
}
