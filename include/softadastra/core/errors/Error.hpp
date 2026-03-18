/*
 * Error.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_ERROR_HPP
#define SOFTADASTRA_DRIVE_CORE_ERROR_HPP

#include <string>

#include <softadastra/core/errors/ErrorCode.hpp>
#include <softadastra/core/errors/Severity.hpp>
#include <softadastra/core/errors/ErrorContext.hpp>

namespace softadastra::core::errors
{
  class Error
  {
  public:
    Error() = default;

    Error(ErrorCode code,
          Severity severity,
          std::string message = {},
          ErrorContext context = {})
        : code_(code),
          severity_(severity),
          message_(std::move(message)),
          context_(std::move(context))
    {
    }

    ErrorCode code() const noexcept
    {
      return code_;
    }

    Severity severity() const noexcept
    {
      return severity_;
    }

    const std::string &message() const noexcept
    {
      return message_;
    }

    const ErrorContext &context() const noexcept
    {
      return context_;
    }

    bool has_error() const noexcept
    {
      return code_ != ErrorCode::None;
    }

  private:
    ErrorCode code_{ErrorCode::None};
    Severity severity_{Severity::Error};
    std::string message_;
    ErrorContext context_;
  };

} // namespace softadastra::core::errors

#endif
