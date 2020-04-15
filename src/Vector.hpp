#pragma once

#include <vector>

class Vector
{
    public:
        using Element = double;
        using Scalar = double;
        using ElementList = std::vector<Element>;

    protected:
        ElementList elements;

    public:
        Vector();
        Vector(Element);
        Vector(Element, Element);
        Vector(Element, Element, Element);

        void addElement(Element element);
        ElementList getElements();

        Vector add(Vector const vectorB);
        Vector subtract(Vector const vectorB);
        Vector multiply(Scalar const scalar);
        Vector multiply(Vector const vectorB);

        double dotProduct(Vector const vectorB);
        Vector crossProduct(Vector const vectorB);

        bool equals(Vector const) const;
};
