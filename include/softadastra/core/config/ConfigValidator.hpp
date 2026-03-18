/*
 * ConfigValidator.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_CONFIG_VALIDATOR_HPP
#define SOFTADASTRA_DRIVE_CORE_CONFIG_VALIDATOR_HPP

#include <string>

#include <softadastra/core/config/ConfigValue.hpp>
#include <softadastra/core/types/Result.hpp>
#include <softadastra/core/errors/Error.hpp>
#include <softadastra/core/errors/ErrorCode.hpp>
#include <softadastra/core/errors/Severity.hpp>

namespace softadastra::core::config
{
  class ConfigValidator
  {
  public:
    template <typename T>
    static types::Result<T, errors::Error>
    require(const ConfigValue &value, const std::string &name)
    {
      if (!value.is<T>())
      {
        return types::Result<T, errors::Error>::err(
            errors::Error(
                errors::ErrorCode::ConfigInvalid,
                errors::Severity::Error,
                "Invalid type for config: " + name));
      }

      return types::Result<T, errors::Error>::ok(value.get<T>());
    }

    static types::Result<std::string, errors::Error>
    require_non_empty(const ConfigValue &value, const std::string &name)
    {
      if (!value.is<std::string>() || value.get<std::string>().empty())
      {
        return types::Result<std::string, errors::Error>::err(
            errors::Error(
                errors::ErrorCode::ConfigInvalid,
                errors::Severity::Error,
                "Config value is empty: " + name));
      }

      return types::Result<std::string, errors::Error>::ok(value.get<std::string>());
    }
  };

} // namespace softadastra::core::config

#endif
