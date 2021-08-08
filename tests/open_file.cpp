#include <vi/open_file.hpp>

#include <gtest/gtest.h>

TEST(open_file, open_success)
{
  const char* path = PROJECT_SOURCE_DIR "tests/data/example_file.txt";

  auto file = vi::open_file(path);

  ASSERT_EQ(file.has_value(), true);

  EXPECT_EQ(*file, "It works!\n");
}
