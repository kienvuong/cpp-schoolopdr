#pragma once

#include "RowVector.hpp"
#include "CanPrint.hpp"

class Matrix : public CanPrint
{
    public:
        using Scalar = Vector::Scalar;
        using RowVectorList = std::vector<RowVector>;

    private:
        RowVectorList rowVectors;

    public:
        Matrix();
        Matrix(RowVector);
        Matrix(RowVector, RowVector);
        Matrix(RowVector, RowVector, RowVector);

        void addRowVector(RowVector vector);

        Matrix operator+(Matrix const matrixB);
        Matrix operator-(Matrix const matrixB);

        Matrix operator*(Scalar const scalar);
        Matrix operator*(Matrix const matrixB);

        bool operator==(Matrix const matrixB) const;

        Matrix transpose();

        void print();
        void println();
};
