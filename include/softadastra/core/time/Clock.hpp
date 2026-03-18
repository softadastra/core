/*
 * Clock.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_CLOCK_HPP
#define SOFTADASTRA_DRIVE_CORE_CLOCK_HPP

#include <chrono>

namespace softadastra::core::time
{
  class Clock
  {
  public:
    using system_clock = std::chrono::system_clock;
    using steady_clock = std::chrono::steady_clock;

    using time_point = system_clock::time_point;
    using steady_time_point = steady_clock::time_point;

    static time_point now() noexcept
    {
      return system_clock::now();
    }

    static steady_time_point monotonic_now() noexcept
    {
      return steady_clock::now();
    }
  };

} // namespace softadastra::core::time

#endif
