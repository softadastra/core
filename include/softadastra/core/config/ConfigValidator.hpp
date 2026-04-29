/**
 *
 *  @file ConfigValidator.hpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2026, Softadastra.
 *  All rights reserved.
 *  https://github.com/softadastra/softadastra
 *
 *  Licensed under the Apache License, Version 2.0.
 *
 *  Softadastra Drive
 *
 */

#ifndef SOFTADASTRA_DRIVE_CORE_CONFIG_VALIDATOR_HPP
#define SOFTADASTRA_DRIVE_CORE_CONFIG_VALIDATOR_HPP

#include <string>

#include <softadastra/core/config/ConfigValue.hpp>
#include <softadastra/core/types/Result.hpp>
#include <softadastra/core/errors/Error.hpp>

namespace softadastra::core::config
{

  /**
   * @brief Utility class for validating configuration values.
   *
   * ConfigValidator provides simple, reusable validation helpers
   * returning Result<T, Error>.
   */
  class ConfigValidator
  {
  public:
    /**
     * @brief Ensures a config value has the expected type.
     */
    template <typename T>
    static types::Result<T, errors::Error>
    require(const ConfigValue &value, const std::string &name)
    {
      if (!value.is<T>())
      {
        return types::Result<T, errors::Error>::err(
            errors::Error::make(
                errors::ErrorCode::ConfigInvalid,
                "invalid type for config: " + name,
                errors::ErrorContext("expected type mismatch")));
      }

      return types::Result<T, errors::Error>::ok(value.get<T>());
    }

    /**
     * @brief Ensures a string config value is not empty.
     */
    static types::Result<std::string, errors::Error>
    require_non_empty(const ConfigValue &value, const std::string &name)
    {
      if (!value.is<std::string>())
      {
        return types::Result<std::string, errors::Error>::err(
            errors::Error::make(
                errors::ErrorCode::ConfigInvalid,
                "invalid type for config: " + name,
                errors::ErrorContext("expected string")));
      }

      const auto &str = value.get<std::string>();

      if (str.empty())
      {
        return types::Result<std::string, errors::Error>::err(
            errors::Error::make(
                errors::ErrorCode::ConfigInvalid,
                "config value is empty: " + name));
      }

      return types::Result<std::string, errors::Error>::ok(str);
    }
  };

} // namespace softadastra::core::config

#endif
