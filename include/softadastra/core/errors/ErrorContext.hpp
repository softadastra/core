/**
 *
 *  @file ErrorContext.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_ERROR_CONTEXT_HPP
#define SOFTADASTRA_DRIVE_CORE_ERROR_CONTEXT_HPP

#include <string>
#include <utility>

namespace softadastra::core::errors
{

  /**
   * @brief Optional contextual information attached to an error.
   *
   * ErrorContext carries human-readable diagnostic information
   * to complement ErrorCode.
   *
   * It is intended for:
   * - logs
   * - debugging
   * - tracing
   *
   * It must NOT:
   * - be relied upon for program logic
   * - replace ErrorCode
   *
   * @code
   * ErrorContext ctx("failed to open file: config.json");
   * @endcode
   */
  class ErrorContext
  {
  public:
    /**
     * @brief Creates an empty context.
     */
    ErrorContext() = default;

    /**
     * @brief Creates a context with a message.
     *
     * @param message Diagnostic message.
     */
    explicit ErrorContext(std::string message)
        : message_(std::move(message))
    {
    }

    /**
     * @brief Returns the diagnostic message.
     */
    [[nodiscard]] const std::string &message() const noexcept
    {
      return message_;
    }

    /**
     * @brief Returns true if no message is stored.
     */
    [[nodiscard]] bool empty() const noexcept
    {
      return message_.empty();
    }

  private:
    std::string message_;
  };

} // namespace softadastra::core::errors

#endif // SOFTADASTRA_DRIVE_CORE_ERROR_CONTEXT_HPP
