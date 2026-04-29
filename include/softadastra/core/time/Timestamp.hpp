/**
 *
 *  @file Timestamp.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_TIMESTAMP_HPP
#define SOFTADASTRA_DRIVE_CORE_TIMESTAMP_HPP

#include <chrono>
#include <cstdint>

#include <softadastra/core/time/Clock.hpp>

namespace softadastra::core::time
{

  /**
   * @brief Unix timestamp stored in milliseconds.
   *
   * Timestamp represents wall-clock time as milliseconds since the Unix epoch.
   *
   * It is designed for:
   * - WAL entries
   * - metadata
   * - audit logs
   * - JSON/network serialization
   *
   * Use Timestamp for persisted time.
   * Use Clock::monotonic_now() for durations, timeouts, and benchmarks.
   */
  class Timestamp
  {
  public:
    /**
     * @brief Underlying timestamp representation.
     */
    using rep = std::int64_t;

    /**
     * @brief Creates an invalid timestamp with value 0.
     */
    constexpr Timestamp() noexcept = default;

    /**
     * @brief Creates a timestamp from milliseconds since Unix epoch.
     *
     * @param value Milliseconds since Unix epoch.
     */
    explicit constexpr Timestamp(rep value) noexcept
        : value_(value)
    {
    }

    /**
     * @brief Creates a timestamp using the current wall-clock time.
     *
     * @return Current timestamp in milliseconds.
     */
    [[nodiscard]] static Timestamp now() noexcept
    {
      return from_time_point(Clock::now());
    }

    /**
     * @brief Creates a timestamp from a wall-clock time point.
     *
     * @param tp Time point from Clock::system_clock.
     * @return Timestamp in milliseconds.
     */
    [[nodiscard]] static Timestamp from_time_point(Clock::time_point tp) noexcept
    {
      const auto duration = tp.time_since_epoch();

      const auto millis =
          std::chrono::duration_cast<std::chrono::milliseconds>(duration);

      return Timestamp(millis.count());
    }

    /**
     * @brief Creates a timestamp from milliseconds since Unix epoch.
     *
     * @param millis Milliseconds since Unix epoch.
     * @return Timestamp.
     */
    [[nodiscard]] static constexpr Timestamp from_millis(rep millis) noexcept
    {
      return Timestamp(millis);
    }

    /**
     * @brief Returns the raw timestamp value in milliseconds.
     *
     * @return Milliseconds since Unix epoch.
     */
    [[nodiscard]] constexpr rep value() const noexcept
    {
      return value_;
    }

    /**
     * @brief Returns the raw timestamp value in milliseconds.
     *
     * Alias for value(), useful for explicit serialization code.
     */
    [[nodiscard]] constexpr rep millis() const noexcept
    {
      return value_;
    }

    /**
     * @brief Returns true if the timestamp is valid.
     *
     * A timestamp is valid when its value is greater than zero.
     */
    [[nodiscard]] constexpr bool is_valid() const noexcept
    {
      return value_ > 0;
    }

    /**
     * @brief Converts the timestamp to a std::chrono system time point.
     */
    [[nodiscard]] Clock::time_point to_time_point() const noexcept
    {
      return Clock::time_point(std::chrono::milliseconds(value_));
    }

    /**
     * @brief Equality comparison.
     */
    [[nodiscard]] friend constexpr bool operator==(
        const Timestamp &a,
        const Timestamp &b) noexcept
    {
      return a.value_ == b.value_;
    }

    /**
     * @brief Inequality comparison.
     */
    [[nodiscard]] friend constexpr bool operator!=(
        const Timestamp &a,
        const Timestamp &b) noexcept
    {
      return !(a == b);
    }

    /**
     * @brief Less-than comparison.
     */
    [[nodiscard]] friend constexpr bool operator<(
        const Timestamp &a,
        const Timestamp &b) noexcept
    {
      return a.value_ < b.value_;
    }

    /**
     * @brief Greater-than comparison.
     */
    [[nodiscard]] friend constexpr bool operator>(
        const Timestamp &a,
        const Timestamp &b) noexcept
    {
      return b < a;
    }

    /**
     * @brief Less-or-equal comparison.
     */
    [[nodiscard]] friend constexpr bool operator<=(
        const Timestamp &a,
        const Timestamp &b) noexcept
    {
      return !(b < a);
    }

    /**
     * @brief Greater-or-equal comparison.
     */
    [[nodiscard]] friend constexpr bool operator>=(
        const Timestamp &a,
        const Timestamp &b) noexcept
    {
      return !(a < b);
    }

  private:
    rep value_{0};
  };

} // namespace softadastra::core::time

#endif // SOFTADASTRA_DRIVE_CORE_TIMESTAMP_HPP
