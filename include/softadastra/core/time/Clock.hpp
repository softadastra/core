/**
 *
 *  @file Clock.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_CLOCK_HPP
#define SOFTADASTRA_DRIVE_CORE_CLOCK_HPP

#include <chrono>

namespace softadastra::core::time
{

  /**
   * @brief Time utility for Softadastra.
   *
   * Clock provides a minimal and consistent abstraction over system time.
   *
   * It exposes:
   * - wall clock time (system_clock) for timestamps
   * - monotonic time (steady_clock) for durations and timeouts
   *
   * Rules:
   * - Use now() for timestamps (logs, WAL, metadata)
   * - Use monotonic_now() for measuring time (retries, timeouts)
   */
  class Clock
  {
  public:
    using system_clock = std::chrono::system_clock;
    using steady_clock = std::chrono::steady_clock;

    /**
     * @brief Wall clock time point.
     *
     * Represents real-world time (can jump if system clock changes).
     */
    using time_point = system_clock::time_point;

    /**
     * @brief Monotonic time point.
     *
     * Always increases, not affected by system clock changes.
     */
    using steady_time_point = steady_clock::time_point;

    /**
     * @brief Returns current wall clock time.
     *
     * Use for:
     * - timestamps
     * - logs
     * - persisted metadata
     */
    [[nodiscard]] static time_point now() noexcept
    {
      return system_clock::now();
    }

    /**
     * @brief Returns current monotonic time.
     *
     * Use for:
     * - measuring durations
     * - retry backoff
     * - timeouts
     */
    [[nodiscard]] static steady_time_point monotonic_now() noexcept
    {
      return steady_clock::now();
    }
  };

} // namespace softadastra::core::time

#endif // SOFTADASTRA_DRIVE_CORE_CLOCK_HPP
