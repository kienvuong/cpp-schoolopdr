#include <Catch2/catch.hpp>
#include <Vector.hpp>

TEST_CASE("testing print function") {
    Vector vector;
    REQUIRE(vector.print() == 3);
}
