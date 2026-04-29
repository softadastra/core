/**
 *
 *  @file Hasher.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_HASHER_HPP
#define SOFTADASTRA_DRIVE_CORE_HASHER_HPP

#include <cstdint>
#include <vector>

#include <softadastra/core/hash/Hash.hpp>
#include <softadastra/core/hash/HashAlgorithm.hpp>

namespace softadastra::core::hash
{
  /**
   * @brief Abstract hashing interface.
   *
   * Hasher defines the common contract for hashing algorithms.
   *
   * The core module only defines the interface. Concrete algorithms such as
   * SHA256, SHA512, XXHash, or MurmurHash must be implemented in dedicated
   * modules.
   */
  class Hasher
  {
  public:
    using byte = std::uint8_t;
    using Buffer = std::vector<byte>;

    /**
     * @brief Creates a hasher for a specific algorithm.
     *
     * @param algo Hashing algorithm implemented by this hasher.
     */
    explicit Hasher(HashAlgorithm algo) noexcept
        : algo_(algo)
    {
    }

    /**
     * @brief Default virtual destructor.
     */
    virtual ~Hasher() = default;

    Hasher(const Hasher &) = default;
    Hasher &operator=(const Hasher &) = default;

    Hasher(Hasher &&) noexcept = default;
    Hasher &operator=(Hasher &&) noexcept = default;

    /**
     * @brief Returns the hashing algorithm implemented by this hasher.
     */
    [[nodiscard]] HashAlgorithm algorithm() const noexcept
    {
      return algo_;
    }

    /**
     * @brief Computes a hash for the given binary data.
     *
     * @param data Input bytes.
     * @return Hash containing the algorithm and digest bytes.
     */
    [[nodiscard]] virtual Hash hash(const Buffer &data) const = 0;

  private:
    HashAlgorithm algo_{HashAlgorithm::None};
  };

} // namespace softadastra::core::hash

#endif // SOFTADASTRA_DRIVE_CORE_HASHER_HPP
