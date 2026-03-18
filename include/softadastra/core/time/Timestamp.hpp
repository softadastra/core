/*
 * Timestamp.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_TIMESTAMP_HPP
#define SOFTADASTRA_DRIVE_CORE_TIMESTAMP_HPP

#include <cstdint>
#include <chrono>

#include <softadastra/core/time/Clock.hpp>

namespace softadastra::core::time
{
  class Timestamp
  {
  public:
    using rep = std::int64_t;

    Timestamp() = default;

    explicit Timestamp(rep value)
        : value_(value)
    {
    }

    static Timestamp now() noexcept
    {
      return from_time_point(Clock::now());
    }

    static Timestamp from_time_point(Clock::time_point tp) noexcept
    {
      auto duration = tp.time_since_epoch();
      auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
      return Timestamp(millis.count());
    }

    rep value() const noexcept
    {
      return value_;
    }

    bool is_valid() const noexcept
    {
      return value_ > 0;
    }

    // Comparisons
    friend bool operator==(const Timestamp &a, const Timestamp &b)
    {
      return a.value_ == b.value_;
    }

    friend bool operator!=(const Timestamp &a, const Timestamp &b)
    {
      return !(a == b);
    }

    friend bool operator<(const Timestamp &a, const Timestamp &b)
    {
      return a.value_ < b.value_;
    }

  private:
    rep value_{0};
  };

} // namespace softadastra::core::time

#endif
