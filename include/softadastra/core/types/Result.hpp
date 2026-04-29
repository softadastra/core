/**
 *
 *  @file Result.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_RESULT_HPP
#define SOFTADASTRA_DRIVE_CORE_RESULT_HPP

#include <utility>
#include <variant>
#include <stdexcept>
#include <type_traits>

namespace softadastra::core::types
{
  /**
   * @brief Result type representing either a success (T) or an error (E).
   *
   * Explicit error handling primitive used across Softadastra.
   *
   * Inspired by Rust Result.
   *
   * @tparam T Success type
   * @tparam E Error type
   */
  template <typename T, typename E>
  class Result
  {
  public:
    /**
     * @brief Create a success result.
     */
    template <typename U = T>
    static Result ok(U &&value)
    {
      return Result(std::forward<U>(value));
    }

    /**
     * @brief Create an error result.
     */
    template <typename G = E>
    static Result err(G &&error)
    {
      return Result(std::forward<G>(error));
    }

    [[nodiscard]] bool is_ok() const noexcept
    {
      return std::holds_alternative<T>(data_);
    }

    [[nodiscard]] bool is_err() const noexcept
    {
      return std::holds_alternative<E>(data_);
    }

    /**
     * @brief Access value (throws if error).
     */
    [[nodiscard]] const T &value() const
    {
      if (!is_ok())
        throw std::logic_error("Result: no value");
      return std::get<T>(data_);
    }

    [[nodiscard]] T &value()
    {
      if (!is_ok())
        throw std::logic_error("Result: no value");
      return std::get<T>(data_);
    }

    /**
     * @brief Access error (throws if ok).
     */
    [[nodiscard]] const E &error() const
    {
      if (!is_err())
        throw std::logic_error("Result: no error");
      return std::get<E>(data_);
    }

    [[nodiscard]] E &error()
    {
      if (!is_err())
        throw std::logic_error("Result: no error");
      return std::get<E>(data_);
    }

    /**
     * @brief Returns value or fallback.
     */
    template <typename U>
    [[nodiscard]] T value_or(U &&fallback) const
    {
      if (is_ok())
        return std::get<T>(data_);
      return static_cast<T>(std::forward<U>(fallback));
    }

    /**
     * @brief Map success value.
     */
    template <typename F>
    auto map(F &&f) const -> Result<std::invoke_result_t<F, T>, E>
    {
      using R = std::invoke_result_t<F, T>;

      if (is_ok())
        return Result<R, E>::ok(f(std::get<T>(data_)));

      return Result<R, E>::err(std::get<E>(data_));
    }

    /**
     * @brief Map error value.
     */
    template <typename F>
    auto map_error(F &&f) const -> Result<T, std::invoke_result_t<F, E>>
    {
      using Err = std::invoke_result_t<F, E>;

      if (is_err())
        return Result<T, Err>::err(f(std::get<E>(data_)));

      return Result<T, Err>::ok(std::get<T>(data_));
    }

  private:
    explicit Result(T value)
        : data_(std::move(value)) {}

    explicit Result(E error)
        : data_(std::move(error)) {}

  private:
    std::variant<T, E> data_;
  };

  /**
   * @brief Specialization for Result<void, E>.
   */
  template <typename E>
  class Result<void, E>
  {
  public:
    static Result ok()
    {
      return Result(true);
    }

    template <typename G = E>
    static Result err(G &&error)
    {
      return Result(std::forward<G>(error));
    }

    [[nodiscard]] bool is_ok() const noexcept { return ok_; }
    [[nodiscard]] bool is_err() const noexcept { return !ok_; }

    [[nodiscard]] const E &error() const
    {
      if (ok_)
        throw std::logic_error("Result<void>: no error");
      return error_;
    }

    [[nodiscard]] E &error()
    {
      if (ok_)
        throw std::logic_error("Result<void>: no error");
      return error_;
    }

  private:
    explicit Result(bool ok) : ok_(ok) {}
    explicit Result(E error) : error_(std::move(error)), ok_(false) {}

  private:
    E error_{};
    bool ok_{false};
  };

} // namespace softadastra::core::types

#endif
