/*
 * StrongType.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_STRONG_TYPE_HPP
#define SOFTADASTRA_DRIVE_CORE_STRONG_TYPE_HPP

#include <utility>
#include <type_traits>

namespace softadastra::core::types
{
  template <typename T, typename Tag>
  class StrongType
  {
  public:
    using value_type = T;

    constexpr StrongType()
      requires std::is_default_constructible_v<T>
    = default;

    explicit constexpr StrongType(const T &value)
        : value_(value)
    {
    }

    explicit constexpr StrongType(T &&value)
        : value_(std::move(value))
    {
    }

    constexpr const T &get() const noexcept
    {
      return value_;
    }

    constexpr T &get() noexcept
    {
      return value_;
    }

    // Comparisons
    friend constexpr bool operator==(const StrongType &a, const StrongType &b)
    {
      return a.value_ == b.value_;
    }

    friend constexpr bool operator!=(const StrongType &a, const StrongType &b)
    {
      return !(a == b);
    }

    friend constexpr bool operator<(const StrongType &a, const StrongType &b)
    {
      return a.value_ < b.value_;
    }

  private:
    T value_{};
  };

} // namespace softadastra::core::types

#endif
