/**
 *
 *  @file HashAlgorithm.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_HASH_ALGORITHM_HPP
#define SOFTADASTRA_DRIVE_CORE_HASH_ALGORITHM_HPP

#include <cstdint>
#include <string_view>

namespace softadastra::core::hash
{

  /**
   * @brief Supported hashing algorithms in Softadastra.
   *
   * HashAlgorithm defines the algorithm used to compute hashes
   * for data integrity, deduplication, and content addressing.
   *
   * Categories:
   * - Fast (non-cryptographic): for performance and internal indexing
   * - Cryptographic: for integrity verification and security
   *
   * Rules:
   * - Must remain stable (do not reorder)
   * - Must be serializable (WAL, network)
   */
  enum class HashAlgorithm : std::uint8_t
  {
    None = 0,

    // Fast (non-cryptographic)
    XXHash,
    MurmurHash,

    // Cryptographic
    SHA256,
    SHA512
  };

  /**
   * @brief Returns a short string representation of HashAlgorithm.
   *
   * Notes:
   * - Not localized
   * - Not UI text
   * - Used for logs and serialization
   */
  [[nodiscard]] constexpr std::string_view
  to_string(HashAlgorithm algo) noexcept
  {
    switch (algo)
    {
    case HashAlgorithm::None:
      return "none";

    case HashAlgorithm::XXHash:
      return "xxhash";

    case HashAlgorithm::MurmurHash:
      return "murmurhash";

    case HashAlgorithm::SHA256:
      return "sha256";

    case HashAlgorithm::SHA512:
      return "sha512";

    default:
      return "unknown";
    }
  }

} // namespace softadastra::core::hash

#endif // SOFTADASTRA_DRIVE_CORE_HASH_ALGORITHM_HPP
