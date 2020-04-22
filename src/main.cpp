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

    std::cout << "Transpose rowvector to columnvector" << std::endl;

    RowVector rowVectorD(1, 2, 3);
    ColumnVector columnVectorE;
    columnVectorE = rowVectorD.transpose();

    columnVectorE.println();

    //----------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "Multiply matrices" << std::endl;

    Matrix matrixP(
        RowVector(1, 2, 3),
        RowVector(4, 5, 6),
        RowVector(7, 8, 9));


    RowVector rowVectorH(1, 2, 3);

    Matrix matrixR;

    matrixR = matrixP * rowVectorH;

    matrixR.println();

    //----------------------------------------------------
    std::cout << "------------------------------" << std::endl;
    std::cout << "Add rowvector in a matrix" << std::endl;

    Matrix matrixD(
        RowVector(2, 2, 2),
        RowVector(2, 2, 2),
        RowVector(2, 2, 2));

    matrixD.addRowVector(RowVector(5, 2, 3));

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
