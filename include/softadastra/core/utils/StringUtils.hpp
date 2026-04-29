/**
 *
 *  @file StringUtils.hpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2026, Softadastra.
 *
 *  Licensed under the Apache License, Version 2.0.
 *
 *  Softadastra Drive
 *
 */

#ifndef SOFTADASTRA_DRIVE_CORE_STRING_UTILS_HPP
#define SOFTADASTRA_DRIVE_CORE_STRING_UTILS_HPP

#include <string>
#include <string_view>
#include <vector>

namespace softadastra::core::utils
{

  /**
   * @brief Utility functions for string manipulation.
   */
  class StringUtils
  {
  public:
    /**
     * @brief Returns true if string is empty.
     */
    [[nodiscard]] static bool is_empty(std::string_view s) noexcept
    {
      return s.empty();
    }

    /**
     * @brief Trims whitespace (view version, no allocation).
     */
    [[nodiscard]] static std::string_view trim_view(std::string_view s) noexcept
    {
      std::size_t start = 0;
      while (start < s.size() && is_space(s[start]))
        ++start;

      std::size_t end = s.size();
      while (end > start && is_space(s[end - 1]))
        --end;

      return s.substr(start, end - start);
    }

    /**
     * @brief Trims whitespace (owning string).
     */
    [[nodiscard]] static std::string trim(std::string_view s)
    {
      auto v = trim_view(s);
      return std::string(v);
    }

    /**
     * @brief Splits a string by delimiter.
     */
    [[nodiscard]] static std::vector<std::string>
    split(std::string_view s, char delimiter)
    {
      std::vector<std::string> result;
      std::string current;

      for (char c : s)
      {
        if (c == delimiter)
        {
          result.push_back(std::move(current));
          current.clear();
        }
        else
        {
          current.push_back(c);
        }
      }

      result.push_back(std::move(current));
      return result;
    }

  private:
    /**
     * @brief Checks if character is whitespace.
     */
    [[nodiscard]] static constexpr bool is_space(char c) noexcept
    {
      return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }
  };

} // namespace softadastra::core::utils

#endif
