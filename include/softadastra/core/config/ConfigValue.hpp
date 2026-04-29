/**
 *
 *  @file ConfigValue.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_CONFIG_VALUE_HPP
#define SOFTADASTRA_DRIVE_CORE_CONFIG_VALUE_HPP

#include <cstdint>
#include <string>
#include <utility>
#include <variant>

namespace softadastra::core::config
{

  /**
   * @brief Type-safe configuration value.
   *
   * ConfigValue stores one supported configuration value type.
   *
   * Supported types:
   * - null
   * - bool
   * - int64
   * - double
   * - string
   *
   * It is used by Config to store runtime settings without exposing
   * parsing or environment-loading logic.
   */
  class ConfigValue
  {
  public:
    /**
     * @brief Internal variant type.
     */
    using Value = std::variant<
        std::monostate,
        bool,
        std::int64_t,
        double,
        std::string>;

    /**
     * @brief Creates a null configuration value.
     */
    ConfigValue() = default;

    /**
     * @brief Creates a configuration value from a supported type.
     *
     * @tparam T Supported value type.
     * @param value Value to store.
     */
    template <typename T>
    explicit ConfigValue(T value)
        : value_(std::move(value))
    {
    }

    /**
     * @brief Returns true if the value is null.
     */
    [[nodiscard]] bool is_null() const noexcept
    {
      return std::holds_alternative<std::monostate>(value_);
    }

    /**
     * @brief Returns true if the value contains type T.
     */
    template <typename T>
    [[nodiscard]] bool is() const noexcept
    {
      return std::holds_alternative<T>(value_);
    }

    /**
     * @brief Returns the stored value as type T.
     *
     * @throws std::bad_variant_access if T is not the stored type.
     */
    template <typename T>
    [[nodiscard]] const T &get() const
    {
      return std::get<T>(value_);
    }

    /**
     * @brief Returns the stored value as type T.
     *
     * @throws std::bad_variant_access if T is not the stored type.
     */
    template <typename T>
    [[nodiscard]] T &get()
    {
      return std::get<T>(value_);
    }

    /**
     * @brief Returns the raw variant.
     */
    [[nodiscard]] const Value &raw() const noexcept
    {
      return value_;
    }

  private:
    Value value_{};
  };

} // namespace softadastra::core::config

#endif // SOFTADASTRA_DRIVE_CORE_CONFIG_VALUE_HPP
