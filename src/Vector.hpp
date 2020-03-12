#pragma once

#include "Matrix.hpp"
#include <vector>

class Vector : public Matrix
{
    private:
        std::vector<Element> elements;

    public:
        void addElement(Element element);
        Vector add(Vector vector);
        void print();
};
