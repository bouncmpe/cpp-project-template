#include "bouncmpe/jsonmerge.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Dummy Addition", "[core]") {
  int a = 10;
  int b = 12;

  int result = bouncmpe::add_two_integer(a, b);
  int expected = 22;

  REQUIRE(result == expected);
}

TEST_CASE("Merge Operation", "[core]") {
  boost::json::value target = {{"key1", "v1"}, {"key2", "a"}};
  boost::json::value patch = {{"key1", "v2"}};

  boost::json::value result = bouncmpe::jsonmerge(target, patch);
  boost::json::value expected = {{"key1", "v2"}, {"key2", "a"}};

  REQUIRE(result == expected);
}

// Complete the test suite by writing more tests...
// When is it a good time to stop writing more tests?