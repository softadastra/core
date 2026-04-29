/**
 *
 *  @file Config.hpp
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
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  Softadastra Drive
 *
 */

#ifndef SOFTADASTRA_DRIVE_CORE_CONFIG_HPP
#define SOFTADASTRA_DRIVE_CORE_CONFIG_HPP

#include <string>
#include <unordered_map>
#include <utility>

#include <softadastra/core/config/ConfigValue.hpp>

namespace softadastra::core::config
{

  /**
   * @brief In-memory configuration container.
   *
   * Config stores named configuration values and provides a small,
   * predictable API for reading, writing, and inspecting runtime settings.
   *
   * It does not parse files, environment variables, or command-line arguments.
   * Those responsibilities belong to higher-level loaders.
   */
  class Config
  {
  public:
    /**
     * @brief Internal configuration map type.
     */
    using Map = std::unordered_map<std::string, ConfigValue>;

    /**
     * @brief Creates an empty configuration object.
     */
    Config() = default;

    /**
     * @brief Stores or replaces a configuration value.
     *
     * @param key Configuration key.
     * @param value Configuration value.
     */
    void set(std::string key, ConfigValue value)
    {
      values_[std::move(key)] = std::move(value);
    }

    /**
     * @brief Returns true if the configuration contains the given key.
     *
     * @param key Configuration key.
     * @return true if the key exists.
     */
    [[nodiscard]] bool has(const std::string &key) const noexcept
    {
      return values_.find(key) != values_.end();
    }

    /**
     * @brief Returns a const pointer to a configuration value.
     *
     * @param key Configuration key.
     * @return Pointer to the value, or nullptr if the key does not exist.
     */
    [[nodiscard]] const ConfigValue *get(const std::string &key) const noexcept
    {
      const auto it = values_.find(key);

      if (it == values_.end())
      {
        return nullptr;
      }

      return &it->second;
    }

    /**
     * @brief Returns a mutable pointer to a configuration value.
     *
     * @param key Configuration key.
     * @return Pointer to the value, or nullptr if the key does not exist.
     */
    [[nodiscard]] ConfigValue *get(const std::string &key) noexcept
    {
      const auto it = values_.find(key);

      if (it == values_.end())
      {
        return nullptr;
      }

      return &it->second;
    }

    /**
     * @brief Returns all stored configuration values.
     *
     * @return Read-only reference to the internal configuration map.
     */
    [[nodiscard]] const Map &all() const noexcept
    {
      return values_;
    }

    /**
     * @brief Returns true when no configuration value is stored.
     *
     * @return true if the configuration is empty.
     */
    [[nodiscard]] bool empty() const noexcept
    {
      return values_.empty();
    }

    /**
     * @brief Returns the number of stored configuration values.
     *
     * @return Number of configuration entries.
     */
    [[nodiscard]] std::size_t size() const noexcept
    {
      return values_.size();
    }

    /**
     * @brief Removes all configuration values.
     */
    void clear() noexcept
    {
      values_.clear();
    }

    /**
     * @brief Removes a configuration value.
     *
     * @param key Configuration key.
     * @return true if a value was removed.
     */
    bool remove(const std::string &key)
    {
      return values_.erase(key) > 0;
    }

  private:
    Map values_{};
  };

} // namespace softadastra::core::config

#endif // SOFTADASTRA_DRIVE_CORE_CONFIG_HPP
