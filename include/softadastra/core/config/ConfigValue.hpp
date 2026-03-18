/*
 * ConfigValue.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_CONFIG_VALUE_HPP
#define SOFTADASTRA_DRIVE_CORE_CONFIG_VALUE_HPP

#include <variant>
#include <string>
#include <cstdint>

namespace softadastra::core::config
{
  class ConfigValue
  {
  public:
    using Value = std::variant<
        std::monostate,
        bool,
        std::int64_t,
        double,
        std::string>;

    ConfigValue() = default;

    template <typename T>
    explicit ConfigValue(T value)
        : value_(std::move(value))
    {
    }

    bool is_null() const noexcept
    {
      return std::holds_alternative<std::monostate>(value_);
    }

    template <typename T>
    bool is() const noexcept
    {
      return std::holds_alternative<T>(value_);
    }

    template <typename T>
    const T &get() const
    {
      return std::get<T>(value_);
    }

    template <typename T>
    T &get()
    {
      return std::get<T>(value_);
    }

  private:
    Value value_;
  };

} // namespace softadastra::core::config

#endif
