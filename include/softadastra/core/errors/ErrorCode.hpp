/*
 * ErrorCode.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_ERROR_CODE_HPP
#define SOFTADASTRA_DRIVE_CORE_ERROR_CODE_HPP

namespace softadastra::core::errors
{
  enum class ErrorCode
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

} // namespace softadastra::core::errors

#endif
