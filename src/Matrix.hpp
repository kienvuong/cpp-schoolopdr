#pragma once

#include "RowVector.hpp"

class Matrix
{
    public:
        using Scalar = Vector::Scalar;

    private:
        std::vector<RowVector> rowVectors;

    public:
        Matrix();
        Matrix(RowVector);
        Matrix(RowVector, RowVector);
        Matrix(RowVector, RowVector, RowVector);

        void addRowVector(RowVector vector);

        Matrix operator+(Matrix const matrixB);
        Matrix operator-(Matrix const matrixB);

        Matrix operator*(Scalar const scalar);

        bool operator==(Matrix const matrixB) const;

        Matrix transpose();

        void print();
        void println();
};
