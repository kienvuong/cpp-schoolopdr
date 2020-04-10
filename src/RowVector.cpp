#include "RowVector.hpp"

RowVector::RowVector() : Vector() {}
RowVector::RowVector(Vector const &v) : Vector(v) {}
RowVector::RowVector(Element e1) : Vector(e1) {}
RowVector::RowVector(Element e1, Element e2) : Vector(e1, e2) {}
RowVector::RowVector(Element e1, Element e2, Element e3) : Vector(e1, e2, e3) {}

RowVector RowVector::operator+(Vector const vectorB)
{
    return add(vectorB);
}

RowVector RowVector::operator-(Vector const vectorB)
{
    return subtract(vectorB);
}

RowVector RowVector::operator*(int const scalar)
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
