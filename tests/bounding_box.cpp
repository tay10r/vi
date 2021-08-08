#include <gtest/gtest.h>

#include <vi/bounding_box.hpp>

TEST(bounding_box, from_string)
{
  std::string_view in;

  auto box = vi::bounding_box<int>::from_string(in);

  EXPECT_EQ(box.empty(), true);
}

TEST(bounding_box, from_string_2)
{
  std::string_view in("a");

  auto box = vi::bounding_box<int>::from_string(in);

  EXPECT_EQ(box.width(), 1);
  EXPECT_EQ(box.height(), 1);
}

TEST(bounding_box, from_string_3)
{
  std::string_view in("a\n");

  auto box = vi::bounding_box<int>::from_string(in);

  EXPECT_EQ(box.width(), 1);
  EXPECT_EQ(box.height(), 2);
}

TEST(bounding_box, from_string_4)
{
  std::string_view in("a\r\n");

  auto box = vi::bounding_box<int>::from_string(in);

  EXPECT_EQ(box.width(), 1);
  EXPECT_EQ(box.height(), 2);
}
