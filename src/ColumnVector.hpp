#pragma once

#include "Vector.hpp"
#include "RowVector.hpp"
#include "CanPrint.hpp"

class RowVector;

class ColumnVector : public Vector, public CanPrint
{
public:
    ColumnVector();
    ColumnVector(Element);
    ColumnVector(Element, Element);
    ColumnVector(Element, Element, Element);
    ColumnVector(Vector const &v);
    ColumnVector(RowVector const &v);

    ColumnVector operator+(Vector const vectorB);
    ColumnVector operator-(Vector const vectorB);

    ColumnVector operator*(Scalar const scalar);
    ColumnVector operator*(Vector const vectorB);

    bool operator==(ColumnVector const) const;
    bool operator!=(ColumnVector const) const;

    RowVector transpose();

    void print();
    void println();
};
