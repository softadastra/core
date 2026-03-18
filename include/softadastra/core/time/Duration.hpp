/*
 * Duration.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_DURATION_HPP
#define SOFTADASTRA_DRIVE_CORE_DURATION_HPP

#include <cstdint>
#include <chrono>

namespace softadastra::core::time
{
  class Duration
  {
  public:
    using rep = std::int64_t;

    Duration() = default;

    explicit Duration(rep millis)
        : millis_(millis)
    {
    }

    static Duration from_millis(rep millis) noexcept
    {
      return Duration(millis);
    }

    static Duration from_seconds(rep seconds) noexcept
    {
      return Duration(seconds * 1000);
    }

    template <typename Rep, typename Period>
    static Duration from_chrono(std::chrono::duration<Rep, Period> d) noexcept
    {
      auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(d);
      return Duration(ms.count());
    }

    rep millis() const noexcept
    {
      return millis_;
    }

    bool is_zero() const noexcept
    {
      return millis_ == 0;
    }

    // Comparisons
    friend bool operator==(const Duration &a, const Duration &b)
    {
      return a.millis_ == b.millis_;
    }

    friend bool operator!=(const Duration &a, const Duration &b)
    {
      return !(a == b);
    }

    friend bool operator<(const Duration &a, const Duration &b)
    {
      return a.millis_ < b.millis_;
    }

  private:
    rep millis_{0};
  };

} // namespace softadastra::core::time

#endif
