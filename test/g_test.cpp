#include "hello.hpp"

#include <gtest/gtest.h>

#include <filesystem>
#include <string>

namespace {} // namespace

int main(int argc, char *argv[]) {
  say_hello();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

  return 0;
}