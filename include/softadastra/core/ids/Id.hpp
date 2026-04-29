/**
 *
 *  @file Id.hpp
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
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND.
 *
 *  Softadastra Drive
 *
 */

#ifndef SOFTADASTRA_DRIVE_CORE_ID_HPP
#define SOFTADASTRA_DRIVE_CORE_ID_HPP

#include <cstddef>
#include <random>
#include <string>

#include <softadastra/core/types/StrongType.hpp>

namespace softadastra::core::ids
{

  namespace detail
  {

    /**
     * @brief Generates a random hexadecimal string.
     *
     * This helper is intended for local identifiers where cryptographic
     * security is not required.
     *
     * @param length Number of hexadecimal characters to generate.
     * @return Random hexadecimal string.
     */
    [[nodiscard]] inline std::string generate_random_hex(std::size_t length = 16)
    {
      static thread_local std::mt19937_64 rng{std::random_device{}()};
      static constexpr char hex[] = "0123456789abcdef";

      std::string out;
      out.reserve(length);

      for (std::size_t i = 0; i < length; ++i)
      {
        out.push_back(hex[rng() % 16]);
      }

      return out;
    }

  } // namespace detail

  /**
   * @brief Strongly typed string identifier.
   *
   * Id wraps a string identifier and uses a tag type to prevent mixing
   * different identifier domains.
   *
   * @tparam Tag Unique tag used to distinguish identifier types.
   *
   * @code
   * struct FileIdTag {};
   * struct NodeIdTag {};
   *
   * using FileId = Id<FileIdTag>;
   * using NodeId = Id<NodeIdTag>;
   *
   * FileId file = FileId::generate();
   * NodeId node = NodeId::generate();
   *
   * // file == node; // compile error
   * @endcode
   */
  template <typename Tag>
  class Id : public types::StrongType<std::string, Tag>
  {
  public:
    /**
     * @brief Base strong type.
     */
    using Base = types::StrongType<std::string, Tag>;

    /**
     * @brief Inherit constructors from StrongType.
     */
    using Base::Base;

    /**
     * @brief Generates a random identifier.
     *
     * The default length is 16 hexadecimal characters.
     */
    [[nodiscard]] static Id generate()
    {
      return Id(detail::generate_random_hex());
    }

    /**
     * @brief Generates a random identifier with a custom hex length.
     *
     * @param length Number of hexadecimal characters.
     * @return Generated identifier.
     */
    [[nodiscard]] static Id generate(std::size_t length)
    {
      return Id(detail::generate_random_hex(length));
    }

    /**
     * @brief Returns true if the identifier is not empty.
     */
    [[nodiscard]] bool is_valid() const noexcept
    {
      return !this->get().empty();
    }

    /**
     * @brief Returns the identifier as a string.
     */
    [[nodiscard]] const std::string &str() const noexcept
    {
      return this->get();
    }
  };

} // namespace softadastra::core::ids

#endif // SOFTADASTRA_DRIVE_CORE_ID_HPP
