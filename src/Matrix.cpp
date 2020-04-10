#include "Matrix.hpp"

Matrix::Matrix() {}

Matrix::Matrix(RowVector v1)
{
    addRowVector(v1);
}

Matrix::Matrix(RowVector v1, RowVector v2)
{
    addRowVector(v1);
    addRowVector(v2);
}

Matrix::Matrix(RowVector v1, RowVector v2, RowVector v3)
{
    addRowVector(v1);
    addRowVector(v2);
    addRowVector(v3);
}

void Matrix::addRowVector(RowVector vector)
{
    rowVectors.push_back(vector);
}

Matrix Matrix::operator+(Matrix const matrixB)
{
    std::vector<RowVector> rowVectorsA = rowVectors;
    std::vector<RowVector> rowVectorsB = matrixB.rowVectors;

    Matrix matrixC;

    for (unsigned int i = 0; i < rowVectorsA.size(); i++) {
        RowVector vectorC = rowVectorsA[i] + rowVectorsB[i];
        matrixC.addRowVector(vectorC);
    }

    return matrixC;
}

Matrix Matrix::operator-(Matrix const matrixB)
{
    std::vector<RowVector> rowVectorsA = rowVectors;
    std::vector<RowVector> rowVectorsB = matrixB.rowVectors;

    Matrix matrixC;

    for (unsigned int i = 0; i < rowVectorsA.size(); i++) {
        RowVector vectorC = rowVectorsA[i] - rowVectorsB[i];
        matrixC.addRowVector(vectorC);
    }

    return matrixC;
}

Matrix Matrix::operator*(Scalar const scalar)
{
    Matrix matrixC;

    for (unsigned int i = 0; i < rowVectors.size(); i++) {
        RowVector vectorC = rowVectors[i] * scalar;
        matrixC.addRowVector(vectorC);
    }

    return matrixC;
}

bool Matrix::operator==(Matrix const matrixB) const
{
    std::vector<RowVector> rowVectorsA = rowVectors;
    std::vector<RowVector> rowVectorsB = matrixB.rowVectors;

    for (unsigned int i = 0; i < rowVectorsA.size(); i++) {
        if (rowVectorsA[i] != rowVectorsB[i]) {
            return false;
        }
    }

    return true;
}
