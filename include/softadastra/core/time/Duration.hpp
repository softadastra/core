/**
 *
 *  @file Duration.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_DURATION_HPP
#define SOFTADASTRA_DRIVE_CORE_DURATION_HPP

#include <cstdint>
#include <chrono>

namespace softadastra::core::time
{

  /**
   * @brief Time duration expressed in milliseconds.
   *
   * Duration is a simple, stable representation of time intervals.
   *
   * Internally stored as a 64-bit integer in milliseconds to ensure:
   * - easy serialization (JSON, WAL)
   * - deterministic behavior across platforms
   * - no dependency on std::chrono at API boundaries
   *
   * @code
   * auto d1 = Duration::from_seconds(5);
   * auto d2 = Duration::from_millis(250);
   *
   * if (d1 > d2) { ... }
   * @endcode
   */
  class Duration
  {
  public:
    /**
     * @brief Underlying representation (milliseconds).
     */
    using rep = std::int64_t;

    /**
     * @brief Creates a zero duration.
     */
    constexpr Duration() noexcept = default;

    /**
     * @brief Creates a duration from milliseconds.
     */
    explicit constexpr Duration(rep millis) noexcept
        : millis_(millis)
    {
    }

    /**
     * @brief Creates a duration from milliseconds.
     */
    [[nodiscard]] static constexpr Duration from_millis(rep millis) noexcept
    {
      return Duration(millis);
    }

    /**
     * @brief Creates a duration from seconds.
     */
    [[nodiscard]] static constexpr Duration from_seconds(rep seconds) noexcept
    {
      return Duration(seconds * 1000);
    }

    /**
     * @brief Creates a duration from any std::chrono duration.
     */
    template <typename Rep, typename Period>
    [[nodiscard]] static Duration from_chrono(
        std::chrono::duration<Rep, Period> d) noexcept
    {
      const auto ms =
          std::chrono::duration_cast<std::chrono::milliseconds>(d);

      return Duration(ms.count());
    }

    /**
     * @brief Returns the duration in milliseconds.
     */
    [[nodiscard]] constexpr rep millis() const noexcept
    {
      return millis_;
    }

    /**
     * @brief Returns true if duration is zero.
     */
    [[nodiscard]] constexpr bool is_zero() const noexcept
    {
      return millis_ == 0;
    }

    /**
     * @brief Converts to std::chrono::milliseconds.
     */
    [[nodiscard]] constexpr std::chrono::milliseconds to_chrono() const noexcept
    {
      return std::chrono::milliseconds(millis_);
    }

    /**
     * @brief Addition of durations.
     */
    [[nodiscard]] friend constexpr Duration operator+(
        const Duration &a,
        const Duration &b) noexcept
    {
      return Duration(a.millis_ + b.millis_);
    }

    /**
     * @brief Subtraction of durations.
     */
    [[nodiscard]] friend constexpr Duration operator-(
        const Duration &a,
        const Duration &b) noexcept
    {
      return Duration(a.millis_ - b.millis_);
    }

    /**
     * @brief Equality comparison.
     */
    [[nodiscard]] friend constexpr bool operator==(
        const Duration &a,
        const Duration &b) noexcept
    {
      return a.millis_ == b.millis_;
    }

    /**
     * @brief Inequality comparison.
     */
    [[nodiscard]] friend constexpr bool operator!=(
        const Duration &a,
        const Duration &b) noexcept
    {
      return !(a == b);
    }

    /**
     * @brief Less-than comparison.
     */
    [[nodiscard]] friend constexpr bool operator<(
        const Duration &a,
        const Duration &b) noexcept
    {
      return a.millis_ < b.millis_;
    }

    /**
     * @brief Greater-than comparison.
     */
    [[nodiscard]] friend constexpr bool operator>(
        const Duration &a,
        const Duration &b) noexcept
    {
      return b < a;
    }

    /**
     * @brief Less-or-equal comparison.
     */
    [[nodiscard]] friend constexpr bool operator<=(
        const Duration &a,
        const Duration &b) noexcept
    {
      return !(b < a);
    }

    /**
     * @brief Greater-or-equal comparison.
     */
    [[nodiscard]] friend constexpr bool operator>=(
        const Duration &a,
        const Duration &b) noexcept
    {
      return !(a < b);
    }

  private:
    rep millis_{0};
  };

} // namespace softadastra::core::time

#endif // SOFTADASTRA_DRIVE_CORE_DURATION_HPP
