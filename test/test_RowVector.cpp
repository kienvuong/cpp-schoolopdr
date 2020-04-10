#include <Catch2/catch.hpp>
#include "RowVector.hpp"

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
