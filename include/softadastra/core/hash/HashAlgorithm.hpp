/*
 * HashAlgorithm.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_HASH_ALGORITHM_HPP
#define SOFTADASTRA_DRIVE_CORE_HASH_ALGORITHM_HPP

namespace softadastra::core::hash
{
  enum class HashAlgorithm
  {
    None = 0,

    // Fast (non-cryptographic)
    XXHash,
    MurmurHash,

    // Cryptographic
    SHA256,
    SHA512
  };

} // namespace softadastra::core::hash

#endif
