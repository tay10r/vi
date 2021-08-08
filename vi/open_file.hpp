#pragma once

#include <filesystem>
#include <fstream>
#include <optional>
#include <string>

namespace vi {

template<typename Char>
auto
open_file(const Char* path) -> std::optional<std::basic_string<Char>>;

//================//
// Implementation //
//================//

template<typename Char>
auto
open_file(const Char* path) -> std::optional<std::basic_string<Char>>
{
  std::basic_ifstream<Char> file(path, std::ios::in | std::ios::binary);

  if (file.good())
    return {};

  file.seekg(0, file.end);

  if (file.fail())
    return {};

  auto end_pos = file.tellg();
  if (end_pos == std::streamoff(-1))
    return {};

  file.seekg(0, file.beg);

  if (file.fail())
    return {};

  using string_type = std::basic_string<Char>;

  using size_type = typename string_type::size_type;

  string_type str(size_type(end_pos));

  file.read(&str[0], str.size());

  if (size_type(file.gcount()) != str.size())
    return {};

  return std::optional(str);
}

} // namespace vi
