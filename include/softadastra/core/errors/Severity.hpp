/*
 * Severity.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_SEVERITY_HPP
#define SOFTADASTRA_DRIVE_CORE_SEVERITY_HPP

namespace softadastra::core::errors
{
  enum class Severity
  {
    Debug = 0,
    Info,
    Warning,
    Error,
    Critical
  };

} // namespace softadastra::core::errors

#endif
