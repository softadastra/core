/**
 *
 *  @file StrongType.hpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2026, Softadastra.
 *  All rights reserved.
 *  https://github.com/softadastra/softadastra
 *
 *  Licensed under the Apache License, Version 2.0.
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND.
 *
 *  Softadastra Drive
 *
 */

#ifndef SOFTADASTRA_DRIVE_CORE_STRONG_TYPE_HPP
#define SOFTADASTRA_DRIVE_CORE_STRONG_TYPE_HPP

#include <type_traits>
#include <utility>

namespace softadastra::core::types
{

  /**
   * @brief Strongly typed wrapper around a value.
   *
   * StrongType prevents accidental mixing of values that share the same
   * underlying type but represent different concepts.
   *
   * @tparam T Underlying value type.
   * @tparam Tag Unique tag type used to create a distinct strong type.
   *
   * @code
   * struct FileIdTag {};
   * struct UserIdTag {};
   *
   * using FileId = StrongType<std::string, FileIdTag>;
   * using UserId = StrongType<std::string, UserIdTag>;
   *
   * FileId file{"abc"};
   * UserId user{"abc"};
   *
   * // file == user; // compile error
   * @endcode
   */
  template <typename T, typename Tag>
  class StrongType
  {
  public:
    /**
     * @brief Underlying value type.
     */
    using value_type = T;

    /**
     * @brief Tag type used to make this type unique.
     */
    using tag_type = Tag;

    /**
     * @brief Creates a default value.
     *
     * Available only when T is default constructible.
     */
    constexpr StrongType()
      requires std::is_default_constructible_v<T>
    = default;

    /**
     * @brief Creates a strong type from a const value.
     *
     * @param value Value to copy.
     */
    explicit constexpr StrongType(const T &value)
        : value_(value)
    {
    }

    /**
     * @brief Creates a strong type from an rvalue.
     *
     * @param value Value to move.
     */
    explicit constexpr StrongType(T &&value)
        : value_(std::move(value))
    {
    }

    /**
     * @brief Returns a const reference to the underlying value.
     */
    [[nodiscard]] constexpr const T &get() const noexcept
    {
      return value_;
    }

    /**
     * @brief Returns a mutable reference to the underlying value.
     */
    [[nodiscard]] constexpr T &get() noexcept
    {
      return value_;
    }

    /**
     * @brief Compares two strong values for equality.
     */
    [[nodiscard]] friend constexpr bool operator==(
        const StrongType &a,
        const StrongType &b)
    {
      return a.value_ == b.value_;
    }

    /**
     * @brief Compares two strong values for inequality.
     */
    [[nodiscard]] friend constexpr bool operator!=(
        const StrongType &a,
        const StrongType &b)
    {
      return !(a == b);
    }

    /**
     * @brief Compares two strong values using the underlying less-than operator.
     */
    [[nodiscard]] friend constexpr bool operator<(
        const StrongType &a,
        const StrongType &b)
    {
      return a.value_ < b.value_;
    }

  private:
    T value_{};
  };

} // namespace softadastra::core::types

#endif // SOFTADASTRA_DRIVE_CORE_STRONG_TYPE_HPP
