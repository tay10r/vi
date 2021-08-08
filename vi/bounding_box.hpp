#pragma once

#include <vi/vec2.hpp>

#include <algorithm>

namespace vi {

template<typename Scalar>
struct bounding_box
{
  using vec2_type = vec2<Scalar>;

  vec2_type min;
  vec2_type max;

  template<typename Char>
  static constexpr auto from_string(
    const std::basic_string_view<Char>& str) noexcept -> bounding_box;

  constexpr auto width() const noexcept { return max.x - min.x; }

  constexpr auto height() const noexcept { return max.y - min.y; }

  constexpr auto area() const noexcept { return width() * height(); }

  constexpr auto empty() const noexcept { return area() == 0; }

private:
  template<typename Char>
  static constexpr auto at_crlf(
    const std::basic_string_view<Char>& str) noexcept -> bool;
};

//================//
// Implementation //
//================//

template<typename Scalar>
template<typename Char>
constexpr auto
bounding_box<Scalar>::from_string(
  const std::basic_string_view<Char>& str) noexcept -> bounding_box
{
  using string_view = std::basic_string_view<Char>;

  using size_type = typename string_view::size_type;

  Scalar w = 0;

  Scalar max_w = 0;

  Scalar line = 1;

  for (size_type i = 0; i < str.size(); i++) {

    if (str[i] == Char('\n')) {
      max_w = std::max(max_w, w);
      w = 0;
      line++;
      continue;
    } else if (at_crlf(str.substr(i, str.size() - i))) {
      max_w = std::max(max_w, w);
      w = 0;
      line++;
      i++;
      continue;
    }

    w++;
  }

  max_w = std::max(w, max_w);

  return bounding_box<Scalar>{ vec2_type{ 0, 0 }, vec2_type{ max_w, line } };
}

template<typename Scalar>
template<typename Char>
static constexpr auto
bounding_box<Scalar>::at_crlf(const std::basic_string_view<Char>& str) noexcept
  -> bool
{
  if (str.size() < 2)
    return false;

  return (str[0] == '\r') && (str[1] == '\n');
}

} // namespace vi
