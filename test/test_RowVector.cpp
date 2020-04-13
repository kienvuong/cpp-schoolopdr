#include <Catch2/catch.hpp>
#include "RowVector.hpp"
#include "ColumnVector.hpp"

TEST_CASE("RowVector can get elements") {
    RowVector vector(1, 2, 3);

    std::vector<double> expected = {1, 2, 3};
    std::vector<double> actual = vector.getElements();

    REQUIRE(actual == expected);
}

TEST_CASE("RowVector can be added/subtracted with another") {
    RowVector vectorA(1, 2, 3);
    RowVector vectorB(4, 5, 6);

    SECTION("Addition using +") {
        RowVector actual = vectorA + vectorB;
        RowVector expected(5, 7, 9);
        REQUIRE(actual == expected);
    }

    SECTION("Subtraction using -") {
        RowVector actual = vectorA - vectorB;
        RowVector expected(-3, -3, -3);
        REQUIRE(actual == expected);
    }
}

TEST_CASE("RowVector can be multiplied using scalar") {
    RowVector vectorA(1, 2, 3);

    SECTION("Multiplication using *") {
        RowVector actual = vectorA * 3;
        RowVector expected(3, 6, 9);
        REQUIRE(actual == expected);
    }
}

TEST_CASE("RowVector can be multiplied with another") {
    RowVector vectorA(1, 2, 3);
    RowVector vectorB(4, 5, 6);

    SECTION("Multiplication using *") {
        RowVector actual = vectorA * vectorB;
        RowVector expected(4, 10, 18);
        REQUIRE(actual == expected);
    }
}

TEST_CASE("RowVector dot product with second vector")
{
    RowVector rowVectorA(1, 2, 3);
    RowVector rowVectorB(4, -5, 6);

    /*
    Formula:
        a ⋅ b = 1(4) + 2(-5) + 3(6)
            = 4 − 10 + 18
            = 12
    */
    float expected = 1 * 4 + 2 * (-5) + 3 * 6;

    SECTION("as RowVector") {
        float actual = rowVectorA.dotProduct(rowVectorB);

        REQUIRE(actual == expected);
    }

    SECTION("as ColumnVector") {
        ColumnVector columnVectorB(4, -5, 6);
        float actual = rowVectorA.dotProduct(columnVectorB);

        REQUIRE(actual == expected);
    }
}

TEST_CASE("RowVector can be transposed to ColumnVector") {
    RowVector rowVector(1, 2, 3);

    ColumnVector expected(1, 2, 3);
    ColumnVector actual = rowVector.transpose();

    REQUIRE(actual == expected);
}
