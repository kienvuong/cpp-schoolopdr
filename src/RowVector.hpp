#pragma once

#include "Vector.hpp"

class RowVector : public Vector
{
    public:
        RowVector();
        RowVector(Element);
        RowVector(Element, Element);
        RowVector(Element, Element, Element);
        RowVector(Vector const &v); // For type casting, see: https://stackoverflow.com/a/22880726

        RowVector operator+(Vector const vectorB);
        RowVector operator-(Vector const vectorB);

        RowVector operator*(Scalar const scalar);
        RowVector operator*(Vector const vectorB);

        bool operator==(RowVector const) const;
        bool operator!=(RowVector const) const;
};
