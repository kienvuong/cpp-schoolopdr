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

TEST_CASE("Matrix can be multiplied with another") {
    SECTION("2x2 * 2x3") {
        Matrix matrixA(
            RowVector(1, 2),
            RowVector(4, 3)
        );

        Matrix matrixB(
            RowVector(1, 2, 3),
            RowVector(3, -4, 7)
        );

        /**
         *            B = | 1   2   3 |
         *                | 3  -4   7 |
         *
         *      | 1   2 |   7  -6  17
         *  A = | 4   3 |   13 -4  33
         *
         */

        Matrix actual = matrixA * matrixB;
        Matrix expected(
            RowVector(7, -6, 17),
            RowVector(13, -4, 33)
        );
        REQUIRE(actual == expected);
    }

    SECTION("2x3 * 3x2") {
        Matrix matrixA(
            RowVector(1, 2, 3),
            RowVector(3, -4, 7)
        );

        Matrix matrixB(
            RowVector(1, 2),
            RowVector(4, 3),
            RowVector(0, 5)
        );

        /**
         *                    | 1   2 |
         *                B = | 4   3 |
         *                    | 0   5 |
         *
         *  A = | 1   2   3 |   9   23
         *      | 3  -4   7 |  -13  29
         *
         */

        Matrix actual = matrixA * matrixB;
        Matrix expected(
            RowVector(9, 23),
            RowVector(-13, 29)
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

TEST_CASE("Matrix can be transposed") {
    Matrix matrixA(
        RowVector(1, 2, 3),
        RowVector(4, 5, 6),
        RowVector(7, 8, 9)
    );

    Matrix expected(
        RowVector(1, 4, 7),
        RowVector(2, 5, 8),
        RowVector(3, 6, 9)
    );
    Matrix actual = matrixA.transpose();

    REQUIRE(actual == expected);
}
