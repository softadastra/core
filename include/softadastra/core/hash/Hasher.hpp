/*
 * Hasher.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_HASHER_HPP
#define SOFTADASTRA_DRIVE_CORE_HASHER_HPP

#include <cstdint>
#include <vector>

#include <softadastra/core/hash/HashAlgorithm.hpp>

namespace softadastra::core::hash
{

  class Hasher
  {
  public:
    explicit Hasher(HashAlgorithm algo)
        : algo_(algo)
    {
    }

    HashAlgorithm algorithm() const noexcept
    {
      return algo_;
    }

    // Stateless helper
    std::vector<std::uint8_t> hash(const std::vector<std::uint8_t> &data) const
    {
      // ⚠️ Placeholder (no real implementation yet)
      // Core does not implement algorithms
      (void)data;
      return {};
    }

  private:
    HashAlgorithm algo_{HashAlgorithm::None};
  };

} // namespace softadastra::core::hash

#endif
