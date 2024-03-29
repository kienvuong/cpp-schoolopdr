#include <iostream>
#include "Matrix.hpp"

using ElementList = Vector::ElementList;
using Element = Vector::Element;

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

Matrix Matrix::operator*(Matrix const matrixB)
{
    RowVectorList rowVectorsA = rowVectors;
    RowVectorList rowVectorsB = matrixB.rowVectors;

    Matrix matrixC;

    for (unsigned int rowVectorCIndex = 0; rowVectorCIndex < rowVectorsA.size(); rowVectorCIndex++) {
        RowVector rowVectorC;

        RowVector rowVectorA = rowVectorsA[rowVectorCIndex];
        unsigned int matrixBColumnSize = rowVectorsB[0].getElements().size();

        for (unsigned int matrixBColumnIndex = 0; matrixBColumnIndex < matrixBColumnSize; matrixBColumnIndex++) {
            ColumnVector matrixBColumn;
            unsigned int matrixBRowSize = rowVectorsA[0].getElements().size();

            for (unsigned int matrixBRowIndex = 0; matrixBRowIndex < matrixBRowSize; matrixBRowIndex++) {
                RowVector matrixBRow = rowVectorsB[matrixBRowIndex];
                Element matrixBColumnElement = matrixBRow.getElements()[matrixBColumnIndex];
                matrixBColumn.addElement(matrixBColumnElement);
            }

            rowVectorC.addElement(rowVectorA.dotProduct(matrixBColumn));
        }

        matrixC.addRowVector(rowVectorC);
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

Matrix Matrix::transpose()
{
    Matrix transposedMatrix;

    //     0 1 2
    // 0: [1 2 3] <- untransposedRowVector
    // 1: [4 5 6]
    // 2: [7 8 9]
    // 3: [5 0 5]

    //     0 1 2 3
    // 0: [1 4 7 5] <- transposedRowVector
    // 1: [2 5 8 0] <- transposedRowVector
    // 2: [3 6 9 5]

    auto lastUntransposedRowIndex = rowVectors.size() - 1;

    auto lastTransposedRowIndex = rowVectors[0].getElements().size() - 1;

    for (unsigned int transposedElementIndex = 0; transposedElementIndex <= lastTransposedRowIndex; transposedElementIndex++) {
        RowVector transposedRowVector;

        for (unsigned int untransposedRowIndex = 0; untransposedRowIndex <= lastUntransposedRowIndex; untransposedRowIndex++) {
            auto untransposedElements = rowVectors[untransposedRowIndex].getElements();
            transposedRowVector.addElement(untransposedElements[transposedElementIndex]);
        }

        transposedMatrix.addRowVector(transposedRowVector);
    }

    return transposedMatrix;
}

void Matrix::print()
{
    auto lastRowIndex = rowVectors.size() - 1;

    for (unsigned int rowIndex = 0; rowIndex <= lastRowIndex; rowIndex++) {
        std::cout << "| ";

        auto elements = rowVectors[rowIndex].getElements();
        auto lastElementIndex = elements.size() - 1;

        for (unsigned int elementIndex = 0; elementIndex <= lastElementIndex; elementIndex++) {
            std::cout << elements[elementIndex] << " ";
        }

        std::cout << "|";

        if (rowIndex <= lastRowIndex) {
            std::cout << std::endl;
        }
    }
}

void Matrix::println()
{
    print();
    std::cout << std::endl;
}
