#include <iostream>
#include "RowVector.hpp"
#include "ColumnVector.hpp"

int main()
{
    std::cout << "Started program." << std::endl;

    RowVector rowVectorA(1, 2, 3);
    ColumnVector columnVectorA(4, 5, 0);

    rowVectorA.println();
    columnVectorA.println();

    (rowVectorA + columnVectorA).print();

    return 0;
}
