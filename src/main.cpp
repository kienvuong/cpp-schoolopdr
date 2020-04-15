#include <iostream>
#include "RowVector.hpp"
#include "ColumnVector.hpp"
#include "Matrix.hpp"

int main()
{
    std::cout << "Started program." << std::endl;

    Matrix matrixA(
        RowVector(1, 2, 3),
        RowVector(4, 5, 6),
        RowVector(7, 8, 9)
    );
    matrixA.addRowVector(RowVector(5, 0, 5));

    matrixA = matrixA.transpose();
    matrixA.println();

    return 0;
}
