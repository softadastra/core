/*
 * Config.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_CONFIG_HPP
#define SOFTADASTRA_DRIVE_CORE_CONFIG_HPP

#include <string>
#include <unordered_map>

#include <softadastra/core/config/ConfigValue.hpp>

namespace softadastra::core::config
{
  class Config
  {
  public:
    using Map = std::unordered_map<std::string, ConfigValue>;

    Config() = default;

    void set(std::string key, ConfigValue value)
    {
      values_[std::move(key)] = std::move(value);
    }

    bool has(const std::string &key) const noexcept
    {
      return values_.find(key) != values_.end();
    }

    const ConfigValue *get(const std::string &key) const noexcept
    {
      auto it = values_.find(key);
      if (it == values_.end())
        return nullptr;
      return &it->second;
    }

    ConfigValue *get(const std::string &key) noexcept
    {
      auto it = values_.find(key);
      if (it == values_.end())
        return nullptr;
      return &it->second;
    }

    const Map &all() const noexcept
    {
      return values_;
    }

  private:
    Map values_;
  };

} // namespace softadastra::core::config

#endif
