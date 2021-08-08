#pragma once

namespace vi {

template<typename Scalar>
struct vec2 final
{
  Scalar x;
  Scalar y;

  constexpr auto operator==(const vec2& other) const noexcept
  {
    return (x == other.x) && (y == other.y);
  }
};

} // namespace vi
