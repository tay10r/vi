#pragma once

#include <vi/vec2.hpp>

namespace vi {

template<typename Scalar>
struct cursor_state final
{
  using vec2_type = vec2<Scalar>;

  vec2_type position = vec2_type{ 0, 0 };

  Scalar target_column = 0;
};

} // namespace vi
