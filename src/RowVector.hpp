#pragma once

#include "Vector.hpp"
#include "ColumnVector.hpp"
#include "CanPrint.hpp"

class ColumnVector;

class RowVector : public Vector, public CanPrint
{
    public:
        RowVector();
        RowVector(Element);
        RowVector(Element, Element);
        RowVector(Element, Element, Element);
        RowVector(Vector const &v); // For type casting, see: https://stackoverflow.com/a/22880726
        RowVector(ColumnVector const &v); // For type casting, see: https://stackoverflow.com/a/22880726

        RowVector operator+(Vector const vectorB);
        RowVector operator-(Vector const vectorB);

        RowVector operator*(Scalar const scalar);
        RowVector operator*(Vector const vectorB);

        bool operator==(RowVector const) const;
        bool operator!=(RowVector const) const;

        ColumnVector transpose();

        void print();
        void println();
};
