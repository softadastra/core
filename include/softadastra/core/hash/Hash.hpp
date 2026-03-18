/*
 * Hash.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_HASH_HPP
#define SOFTADASTRA_DRIVE_CORE_HASH_HPP

#include <vector>
#include <cstdint>
#include <string>

namespace softadastra::core::hash
{
  class Hash
  {
  public:
    using byte = std::uint8_t;

    Hash() = default;

    explicit Hash(std::vector<byte> data)
        : data_(std::move(data))
    {
    }

    const std::vector<byte> &bytes() const noexcept
    {
      return data_;
    }

    bool empty() const noexcept
    {
      return data_.empty();
    }

    std::string to_hex() const
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

    // Comparisons
    friend bool operator==(const Hash &a, const Hash &b)
    {
      return a.data_ == b.data_;
    }

    friend bool operator!=(const Hash &a, const Hash &b)
    {
      return !(a == b);
    }

  private:
    std::vector<byte> data_;
  };

} // namespace softadastra::core::hash

#endif
