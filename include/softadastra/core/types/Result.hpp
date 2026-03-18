/*
 * Result.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_RESULT_HPP
#define SOFTADASTRA_DRIVE_CORE_RESULT_HPP

#include <utility>

namespace softadastra::core::types
{
  template <typename T, typename E>
  class Result
  {
  public:
    // Success
    static Result ok(T value)
    {
      return Result(std::move(value));
    }

    // Failure
    static Result err(E error)
    {
      return Result(std::move(error), false);
    }

    bool is_ok() const noexcept
    {
      return ok_;
    }

    bool is_err() const noexcept
    {
      return !ok_;
    }

    const T &value() const
    {
      return value_;
    }

    T &value()
    {
      return value_;
    }

    const E &error() const
    {
      return error_;
    }

    E &error()
    {
      return error_;
    }

  private:
    // Success constructor
    explicit Result(T value)
        : value_(std::move(value)), ok_(true)
    {
    }

    // Error constructor
    Result(E error, bool ok)
        : error_(std::move(error)), ok_(ok)
    {
    }

  private:
    T value_{};
    E error_{};
    bool ok_{false};
  };

} // namespace softadastra::core::types

#endif
