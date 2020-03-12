#include <iostream>
#include "RowVector.hpp"
#include "ColumnVector.hpp"

int main()
{
    std::cout << "Started program." << std::endl;

    RowVector rowVectorA;
    rowVectorA.addElement(1);
    rowVectorA.addElement(2);
    rowVectorA.addElement(3);

    RowVector rowVectorB;
    rowVectorB.addElement(4);
    rowVectorB.addElement(5);
    rowVectorB.addElement(6);

    auto rowVectorC = rowVectorA.add(rowVectorB);
    rowVectorA.print();
    rowVectorB.print();
    rowVectorC.print();
    // RowVector rowVectorC = rowVectorA + rowVectorB;

    // ColumnVector columnVectorA;
    // ColumnVector columnVectorB;

    return 0;
}
