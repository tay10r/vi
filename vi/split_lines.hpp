#pragma once

#include <string_view>
#include <vector>

namespace vi {

template<typename Char>
auto
split_lines(const std::basic_string_view<Char>& str)
  -> std::vector<std::basic_string_view<Char>>;

//================//
// Implementation //
//================//

template<typename Char>
auto
split_lines(const std::basic_string_view<Char>& str)
  -> std::vector<std::basic_string_view<Char>>
{
  using string_view_type = std::basic_string_view<Char>;

  using size_type = typename string_view_type::size_type;

  std::vector<string_view_type> lines;

  size_type line_start = 0;

  for (size_type i = 0; i < str.size(); i++) {

    auto at_lf = str[i] == Char('\n');

    auto at_crlf = ((i + 1) < str.size())
                     ? ((str[i] == '\r') && (str[i + 1] == '\n'))
                     : false;

    if (at_lf) {
      lines.emplace_back(str.substr(line_start, i - line_start));
      line_start = i + 1;
      continue;
    } else if (at_crlf) {
      lines.emplace_back(str.substr(line_start, i - line_start));
      line_start = i + 2;
      i++;
      continue;
    }
  }

  if (line_start != str.size())
    lines.emplace_back(str.substr(line_start, str.size() - line_start));

  return lines;
}

} // namespace vi
