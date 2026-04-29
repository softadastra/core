/**
 *
 *  @file Hash.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_HASH_HPP
#define SOFTADASTRA_DRIVE_CORE_HASH_HPP

#include <cstdint>
#include <string>
#include <vector>

#include <softadastra/core/hash/HashAlgorithm.hpp>

namespace softadastra::core::hash
{

  /**
   * @brief Binary hash with associated algorithm.
   *
   * Hash represents a computed digest of data along with the algorithm used.
   *
   * It is used for:
   * - content integrity
   * - deduplication
   * - content addressing
   * - WAL verification
   *
   * Rules:
   * - A hash is valid only if both algorithm and data are set
   * - Two hashes are equal only if algorithm AND bytes match
   */
  class Hash
  {
  public:
    using byte = std::uint8_t;

    /**
     * @brief Creates an empty hash.
     */
    Hash() = default;

    /**
     * @brief Creates a hash from algorithm + raw bytes.
     */
    Hash(HashAlgorithm algo, std::vector<byte> data)
        : algo_(algo), data_(std::move(data))
    {
    }

    /**
     * @brief Returns the hash algorithm.
     */
    [[nodiscard]] HashAlgorithm algorithm() const noexcept
    {
      return algo_;
    }

    /**
     * @brief Returns raw hash bytes.
     */
    [[nodiscard]] const std::vector<byte> &bytes() const noexcept
    {
      return data_;
    }

    /**
     * @brief Returns true if hash has no data.
     */
    [[nodiscard]] bool empty() const noexcept
    {
      return data_.empty();
    }

    /**
     * @brief Returns true if hash is valid.
     */
    [[nodiscard]] bool is_valid() const noexcept
    {
      return algo_ != HashAlgorithm::None && !data_.empty();
    }

    /**
     * @brief Converts hash to hexadecimal string.
     */
    [[nodiscard]] std::string to_hex() const
    {
      static constexpr char hex[] = "0123456789abcdef";

      std::string out;
      out.reserve(data_.size() * 2);

      for (auto b : data_)
      {
        out.push_back(hex[(b >> 4) & 0xF]);
        out.push_back(hex[b & 0xF]);
      }

      return out;
    }

    /**
     * @brief Equality comparison (algo + bytes).
     */
    [[nodiscard]] friend bool operator==(const Hash &a, const Hash &b)
    {
      return a.algo_ == b.algo_ && a.data_ == b.data_;
    }

    [[nodiscard]] friend bool operator!=(const Hash &a, const Hash &b)
    {
      return !(a == b);
    }

  private:
    HashAlgorithm algo_{HashAlgorithm::None};
    std::vector<byte> data_;
  };

} // namespace softadastra::core::hash

#endif // SOFTADASTRA_DRIVE_CORE_HASH_HPP
