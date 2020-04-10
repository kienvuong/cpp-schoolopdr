#pragma once

#include "Vector.hpp"

class RowVector : public Vector
{
    public:
        RowVector();
        RowVector(Vector const &v);
        RowVector(Element);
        RowVector(Element, Element);
        RowVector(Element, Element, Element);

        RowVector operator+(Vector const vectorB);
        RowVector operator-(Vector const vectorB);

        RowVector operator*(int const scalar);
        RowVector operator*(Vector const vectorB);

        bool operator==(RowVector const) const;
        bool operator!=(RowVector const) const;
};
