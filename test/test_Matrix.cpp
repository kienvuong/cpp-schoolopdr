#include <Catch2/catch.hpp>
#include "Matrix.hpp"
#include "RowVector.hpp"

TEST_CASE("Matrix can be added/subtracted with another") {
    Matrix matrixA(
        RowVector(1, 2, 3),
        RowVector(4, 5, 6),
        RowVector(7, 8, 9)
    );

    Matrix matrixB(
        RowVector(-1, 2, 3),
        RowVector(-4, 5, 6),
        RowVector(-7, 8, 9)
    );

    SECTION("Addition using +") {
        Matrix actual = matrixA + matrixB;
        Matrix expected(
            RowVector(0, 4, 6),
            RowVector(0, 10, 12),
            RowVector(0, 16, 18)
        );
        REQUIRE(actual == expected);
    }

    SECTION("Subtraction using -") {
        Matrix actual = matrixA - matrixB;
        Matrix expected(
            RowVector(2, 0, 0),
            RowVector(8, 0, 0),
            RowVector(14, 0, 0)
        );
        REQUIRE(actual == expected);
    }
}

TEST_CASE("Matrix can be multiplied with scalar") {
    Matrix matrixA(
        RowVector(1, 2, 3),
        RowVector(4, 5, 6),
        RowVector(7, 8, 9)
    );

    SECTION("Multiplication using *") {
        Matrix actual = matrixA * 2;
        Matrix expected(
            RowVector(2, 4, 6),
            RowVector(8, 10, 12),
            RowVector(14, 16, 18)
        );
        REQUIRE(actual == expected);
    }
}
