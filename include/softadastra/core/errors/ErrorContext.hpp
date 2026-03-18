/*
 * ErrorContext.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_ERROR_CONTEXT_HPP
#define SOFTADASTRA_DRIVE_CORE_ERROR_CONTEXT_HPP

#include <string>

namespace softadastra::core::errors
{
  class ErrorContext
  {
  public:
    ErrorContext() = default;

    explicit ErrorContext(std::string message)
        : message_(std::move(message))
    {
    }

    const std::string &message() const noexcept
    {
      return message_;
    }

    bool empty() const noexcept
    {
      return message_.empty();
    }

  private:
    std::string message_;
  };

} // namespace softadastra::core::errors

#endif
