/*
 * Result.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_RESULT_HPP
#define SOFTADASTRA_DRIVE_CORE_RESULT_HPP

#include <utility>

namespace softadastra::core::types
{
  // Generic Result<T, E>
  template <typename T, typename E>
  class Result
  {
  public:
    static Result ok(T value)
    {
      return Result(std::move(value));
    }

    static Result err(E error)
    {
      return Result(std::move(error), false);
    }

    bool is_ok() const noexcept { return ok_; }
    bool is_err() const noexcept { return !ok_; }

    const T &value() const { return value_; }
    T &value() { return value_; }

    const E &error() const { return error_; }
    E &error() { return error_; }

  private:
    explicit Result(T value)
        : value_(std::move(value)), ok_(true) {}

    Result(E error, bool ok)
        : error_(std::move(error)), ok_(ok) {}

  private:
    T value_{};
    E error_{};
    bool ok_{false};
  };

  // Specialization for void
  template <typename E>
  class Result<void, E>
  {
  public:
    static Result ok()
    {
      return Result(true);
    }

    static Result err(E error)
    {
      return Result(std::move(error), false);
    }

    bool is_ok() const noexcept { return ok_; }
    bool is_err() const noexcept { return !ok_; }

    const E &error() const { return error_; }
    E &error() { return error_; }

  private:
    explicit Result(bool ok)
        : ok_(ok) {}

    Result(E error, bool ok)
        : error_(std::move(error)), ok_(ok) {}

  private:
    E error_{};
    bool ok_{false};
  };

} // namespace softadastra::core::types

#endif
