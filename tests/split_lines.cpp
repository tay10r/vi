#include <vi/split_lines.hpp>

#include <gtest/gtest.h>

TEST(split_lines, empty)
{
  std::string_view str;

  auto lines = vi::split_lines(str);

  EXPECT_EQ(lines.empty(), true);
}

TEST(split_lines, single_line)
{
  std::string_view str("abc");

  auto lines = vi::split_lines(str);

  ASSERT_EQ(lines.size(), 1);
  EXPECT_EQ(lines[0], "abc");
}

TEST(split_lines, single_line_lf)
{
  std::string_view str("abc\n");

  auto lines = vi::split_lines(str);

  ASSERT_EQ(lines.size(), 1);
  EXPECT_EQ(lines[0], "abc");
}

TEST(split_lines, single_line_crlf)
{
  std::string_view str("abc\r\n");

  auto lines = vi::split_lines(str);

  ASSERT_EQ(lines.size(), 1);
  EXPECT_EQ(lines[0], "abc");
}

TEST(split_lines, two_line_with_content)
{
  std::string_view str("abc\ndef");

  auto lines = vi::split_lines(str);

  ASSERT_EQ(lines.size(), 2);
  EXPECT_EQ(lines[0], "abc");
  EXPECT_EQ(lines[1], "def");
}

TEST(split_lines, two_line_with_lf)
{
  std::string_view str("abc\ndef\n");

  auto lines = vi::split_lines(str);

  ASSERT_EQ(lines.size(), 2);
  EXPECT_EQ(lines[0], "abc");
  EXPECT_EQ(lines[1], "def");
}

TEST(split_lines, three_line_with_empty_mid)
{
  std::string_view str("abc\n\ndef");

  auto lines = vi::split_lines(str);

  ASSERT_EQ(lines.size(), 3);
  EXPECT_EQ(lines[0], "abc");
  EXPECT_EQ(lines[1], "");
  EXPECT_EQ(lines[2], "def");
}
