/**
 *
 *  @file Error.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_ERROR_HPP
#define SOFTADASTRA_DRIVE_CORE_ERROR_HPP

#include <string>
#include <utility>

#include <softadastra/core/errors/ErrorCode.hpp>
#include <softadastra/core/errors/ErrorContext.hpp>
#include <softadastra/core/errors/Severity.hpp>

namespace softadastra::core::errors
{

  /**
   * @brief Structured error used across Softadastra.
   *
   * Error combines a machine-readable ErrorCode with severity,
   * a short message, and optional contextual diagnostic data.
   *
   * Rules:
   * - Use ErrorCode for program logic.
   * - Use message() for short developer-facing diagnostics.
   * - Use context() for additional debugging information.
   */
  class Error
  {
  public:
    /**
     * @brief Creates an empty success-like error object.
     */
    Error() = default;

    /**
     * @brief Creates a structured error.
     *
     * @param code Machine-readable error code.
     * @param severity Error severity.
     * @param message Short diagnostic message.
     * @param context Additional contextual information.
     */
    Error(
        ErrorCode code,
        Severity severity,
        std::string message = {},
        ErrorContext context = {})
        : code_(code),
          severity_(severity),
          message_(std::move(message)),
          context_(std::move(context))
    {
    }

    /**
     * @brief Creates a non-critical error with Severity::Error.
     */
    static Error make(
        ErrorCode code,
        std::string message = {},
        ErrorContext context = {})
    {
      return Error(
          code,
          Severity::Error,
          std::move(message),
          std::move(context));
    }

    /**
     * @brief Creates a warning error.
     */
    static Error warning(
        ErrorCode code,
        std::string message = {},
        ErrorContext context = {})
    {
      return Error(
          code,
          Severity::Warning,
          std::move(message),
          std::move(context));
    }

    /**
     * @brief Creates a critical error.
     */
    static Error critical(
        ErrorCode code,
        std::string message = {},
        ErrorContext context = {})
    {
      return Error(
          code,
          Severity::Critical,
          std::move(message),
          std::move(context));
    }

    /**
     * @brief Returns the machine-readable error code.
     */
    [[nodiscard]] ErrorCode code() const noexcept
    {
      return code_;
    }

    /**
     * @brief Returns the error severity.
     */
    [[nodiscard]] Severity severity() const noexcept
    {
      return severity_;
    }

    /**
     * @brief Returns the short diagnostic message.
     */
    [[nodiscard]] const std::string &message() const noexcept
    {
      return message_;
    }

    /**
     * @brief Returns optional contextual diagnostic information.
     */
    [[nodiscard]] const ErrorContext &context() const noexcept
    {
      return context_;
    }

    /**
     * @brief Returns true if this object represents an error.
     */
    [[nodiscard]] bool has_error() const noexcept
    {
      return code_ != ErrorCode::None;
    }

    /**
     * @brief Returns true if this object represents no error.
     */
    [[nodiscard]] bool ok() const noexcept
    {
      return code_ == ErrorCode::None;
    }

  private:
    ErrorCode code_{ErrorCode::None};
    Severity severity_{Severity::Error};
    std::string message_{};
    ErrorContext context_{};
  };

} // namespace softadastra::core::errors

#endif // SOFTADASTRA_DRIVE_CORE_ERROR_HPP
