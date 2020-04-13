#pragma once

#include "Vector.hpp"
#include "RowVector.hpp"

class RowVector;

class ColumnVector : public Vector
{
    public:
        ColumnVector();
        ColumnVector(Element);
        ColumnVector(Element, Element);
        ColumnVector(Element, Element, Element);
        ColumnVector(Vector const &v); // For type casting, see: https://stackoverflow.com/a/22880726
        ColumnVector(RowVector const &v); // For type casting, see: https://stackoverflow.com/a/22880726

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
