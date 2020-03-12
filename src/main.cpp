#include <iostream>
#include "RowVector.hpp"
#include "ColumnVector.hpp"

void testRowVectorAddition();
void testColumnVectorAddition();

int main()
{
    std::cout << "Started program." << std::endl;

    testRowVectorAddition();

    return 0;
}

void testRowVectorAddition()
{
    RowVector rowVectorA;
    rowVectorA.addElement(1);
    rowVectorA.addElement(2);
    rowVectorA.addElement(3);

    RowVector rowVectorB;
    rowVectorB.addElement(4);
    rowVectorB.addElement(5);
    rowVectorB.addElement(6);

    auto rowVectorC = rowVectorA + rowVectorB;
    // auto rowVectorC = rowVectorA.add(rowVectorB);
    rowVectorA.print();
    rowVectorB.print();
    rowVectorC.print();
}

void testColumnVectorAddition()
{
    ColumnVector columnVectorA;
    columnVectorA.addElement(1);
    columnVectorA.addElement(2);
    columnVectorA.addElement(3);

    ColumnVector columnVectorB;
    columnVectorB.addElement(4);
    columnVectorB.addElement(5);
    columnVectorB.addElement(6);

    auto columnVectorC = columnVectorA.add(columnVectorB);
    columnVectorA.print();
    columnVectorB.print();
    columnVectorC.print();
}
