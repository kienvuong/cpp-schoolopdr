#include <Catch2/catch.hpp>
#include "ColumnVector.hpp"
#include "RowVector.hpp"

TEST_CASE("ColumnVector can get elements") {
    ColumnVector vector(1, 2, 3);

    std::vector<double> expected = {1, 2, 3};
    std::vector<double> actual = vector.getElements();

    REQUIRE(actual == expected);
}

TEST_CASE("ColumnVector can be added/subtracted with another") {
    ColumnVector vectorA(1, 2, 3);
    ColumnVector vectorB(4, 5, 6);

    SECTION("Addition using +") {
        ColumnVector actual = vectorA + vectorB;
        ColumnVector expected(5, 7, 9);
        REQUIRE(actual == expected);
    }

    SECTION("Subtraction using -") {
        ColumnVector actual = vectorA - vectorB;
        ColumnVector expected(-3, -3, -3);
        REQUIRE(actual == expected);
    }
}

TEST_CASE("ColumnVector can be multiplied using scalar") {
    ColumnVector vectorA(1, 2, 3);

    SECTION("Multiplication using *") {
        ColumnVector actual = vectorA * 3;
        ColumnVector expected(3, 6, 9);
        REQUIRE(actual == expected);
    }
}

TEST_CASE("ColumnVector can be multiplied with another") {
    ColumnVector vectorA(1, 2, 3);
    ColumnVector vectorB(4, 5, 6);

    SECTION("Multiplication using *") {
        ColumnVector actual = vectorA * vectorB;
        ColumnVector expected(4, 10, 18);
        REQUIRE(actual == expected);
    }
}

TEST_CASE("ColumnVector dot product with second vector")
{
    ColumnVector columnVectorA(1, 2, 3);
    ColumnVector columnVectorB(4, -5, 6);

    /*
    Formula:
        a ⋅ b = 1(4) + 2(-5) + 3(6)
            = 4 − 10 + 18
            = 12
    */
    float expected = 1 * 4 + 2 * (-5) + 3 * 6;

    SECTION("as ColumnVector")
    {
        float actual = columnVectorA.dotProduct(columnVectorB);

        REQUIRE(actual == expected);
    }

    SECTION("as RowVector")
    {
        RowVector rowVectorB(4, -5, 6);
        float actual = columnVectorA.dotProduct(rowVectorB);

        REQUIRE(actual == expected);
    }
}

TEST_CASE("ColumnVector can be transposed to RowVector") {
    ColumnVector columnVector(1, 2, 3);

    RowVector expected(1, 2, 3);
    RowVector actual = columnVector.transpose();

    REQUIRE(actual == expected);
}
