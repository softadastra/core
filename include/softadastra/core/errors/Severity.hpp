/**
 *
 *  @file Severity.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_SEVERITY_HPP
#define SOFTADASTRA_DRIVE_CORE_SEVERITY_HPP

#include <cstdint>
#include <string_view>

namespace softadastra::core::errors
{

  /**
   * @brief Severity level of an error or log event.
   *
   * Severity defines how important or critical an event is.
   *
   * It is used for:
   * - logging systems
   * - monitoring / alerting
   * - filtering events
   *
   * Rules:
   * - Must remain stable (do not reorder)
   * - Independent from ErrorCode
   */
  enum class Severity : std::uint8_t
  {
    Debug = 0, ///< Detailed diagnostic information
    Info,      ///< Informational message
    Warning,   ///< Non-critical issue
    Error,     ///< Failure requiring attention
    Critical   ///< Severe failure (system-level impact)
  };

  /**
   * @brief Returns a short string representation of Severity.
   *
   * Notes:
   * - Not localized
   * - Not intended for UI
   * - Used for logs and serialization
   */
  [[nodiscard]] constexpr std::string_view
  to_string(Severity s) noexcept
  {
    switch (s)
    {
    case Severity::Debug:
      return "debug";
    case Severity::Info:
      return "info";
    case Severity::Warning:
      return "warning";
    case Severity::Error:
      return "error";
    case Severity::Critical:
      return "critical";
    default:
      return "unknown";
    }
  }

} // namespace softadastra::core::errors

#endif // SOFTADASTRA_DRIVE_CORE_SEVERITY_HPP
