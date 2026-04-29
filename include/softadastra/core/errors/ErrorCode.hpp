/**
 *
 *  @file ErrorCode.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_ERROR_CODE_HPP
#define SOFTADASTRA_DRIVE_CORE_ERROR_CODE_HPP

#include <cstdint>
#include <string_view>

namespace softadastra::core::errors
{

  /**
   * @brief Canonical error codes for Softadastra.
   *
   * ErrorCode defines a stable, low-level set of error identifiers used across:
   * - Result<T, Error>
   * - WAL
   * - sync engine
   * - API responses
   *
   * Rules:
   * - Must remain stable over time (do not reorder/remove)
   * - Must not contain user-facing messages
   * - Must be lightweight and serializable
   */
  enum class ErrorCode : std::uint16_t
  {
    None = 0,

    // Generic
    Unknown,
    InvalidArgument,
    InvalidState,
    NotFound,
    AlreadyExists,

    // IO / File
    FileNotFound,
    FileAlreadyExists,
    FileReadError,
    FileWriteError,
    PermissionDenied,

    // Config
    ConfigInvalid,
    ConfigMissing,

    // Hash
    HashError,

    // Time
    TimeError,

    // Internal
    InternalError
  };

  /**
   * @brief Returns a short, stable string representation of ErrorCode.
   *
   * Notes:
   * - Not localized
   * - Not intended for UI
   * - Used for logs, debugging, and serialization
   */
  [[nodiscard]] constexpr std::string_view
  to_string(ErrorCode code) noexcept
  {
    switch (code)
    {
    case ErrorCode::None:
      return "no error";

    case ErrorCode::Unknown:
      return "unknown";

    case ErrorCode::InvalidArgument:
      return "invalid argument";

    case ErrorCode::InvalidState:
      return "invalid state";

    case ErrorCode::NotFound:
      return "not found";

    case ErrorCode::AlreadyExists:
      return "already exists";

    case ErrorCode::FileNotFound:
      return "file not found";

    case ErrorCode::FileAlreadyExists:
      return "file already exists";

    case ErrorCode::FileReadError:
      return "file read error";

    case ErrorCode::FileWriteError:
      return "file write error";

    case ErrorCode::PermissionDenied:
      return "permission denied";

    case ErrorCode::ConfigInvalid:
      return "invalid config";

    case ErrorCode::ConfigMissing:
      return "missing config";

    case ErrorCode::HashError:
      return "hash error";

    case ErrorCode::TimeError:
      return "time error";

    case ErrorCode::InternalError:
      return "internal error";

    default:
      return "unknown error code";
    }
  }

} // namespace softadastra::core::errors

#endif // SOFTADASTRA_DRIVE_CORE_ERROR_CODE_HPP
