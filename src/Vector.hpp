#pragma once

#include <vector>

class Vector
{
    public:
        using Element = double;
        using Scalar = double;

    protected:
        std::vector<Element> elements;

    public:
        Vector();
        Vector(Element);
        Vector(Element, Element);
        Vector(Element, Element, Element);

        void addElement(Element element);

        Vector add(Vector const vectorB);
        Vector subtract(Vector const vectorB);
        Vector multiply(Scalar const scalar);
        Vector multiply(Vector const vectorB);

        bool equals(Vector const) const;

        void print();
};
