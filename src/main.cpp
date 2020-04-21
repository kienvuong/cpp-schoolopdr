#include <iostream>
#include "RowVector.hpp"
#include "ColumnVector.hpp"
#include "Matrix.hpp"

int main()
{
    std::cout << "Add up rowvectors:" << std::endl;

    RowVector rowVectorA(1, 2, 3);
    RowVector rowVectorB(1, 1, 1);
    RowVector rowVectorC;

    rowVectorC = rowVectorA + rowVectorB;

    rowVectorC.println();

    //----------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "Substract Matrices" << std::endl;

    Matrix matrixA(
        RowVector(2, 2, 2),
        RowVector(2, 2, 2),
        RowVector(2, 2, 2) );

    Matrix matrixB(
        RowVector(1, 1, 1),
        RowVector(1, 1, 1),
        RowVector(1, 1, 1) );

    Matrix matrixC;
    matrixC = matrixA - matrixB;

    matrixC.println();


    //----------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "Add rowvector in a matrix" << std::endl;

    Matrix matrixD(
        RowVector(2, 2, 2),
        RowVector(2, 2, 2),
        RowVector(2, 2, 2));

    matrixD.addRowVector(RowVector(1, 2, 3));

    matrixD.println();

    //----------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "Multiply a columnvector by a scalar" << std::endl;

    ColumnVector columnVectorA(2, 2);
    columnVectorA = columnVectorA * 5;
    columnVectorA.println();

    return 0;
}

// clear; make && make run
// clear; make test
