#include <catch2/catch_test_macros.hpp>

#include "lib.hpp"

TEST_CASE("Name is comp-4300-init", "[library]")
{
  auto const lib = library {};
  REQUIRE(lib.name == "comp-4300-init");
}
