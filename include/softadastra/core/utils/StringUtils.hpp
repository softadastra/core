/*
 * StringUtils.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_STRING_UTILS_HPP
#define SOFTADASTRA_DRIVE_CORE_STRING_UTILS_HPP

#include <string>
#include <vector>

namespace softadastra::core::utils
{
  class StringUtils
  {
  public:
    static bool is_empty(const std::string &s) noexcept
    {
      return s.empty();
    }

    static std::string trim(const std::string &s)
    {
      std::size_t start = 0;
      while (start < s.size() && is_space(s[start]))
        ++start;

      std::size_t end = s.size();
      while (end > start && is_space(s[end - 1]))
        --end;

      return s.substr(start, end - start);
    }

    static std::vector<std::string> split(const std::string &s, char delimiter)
    {
      std::vector<std::string> result;
      std::string current;

      for (char c : s)
      {
        if (c == delimiter)
        {
          result.push_back(current);
          current.clear();
        }
        else
        {
          current.push_back(c);
        }
      }

      result.push_back(current);
      return result;
    }

  private:
    static bool is_space(char c) noexcept
    {
      return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }
  };

} // namespace softadastra::core::utils

#endif
