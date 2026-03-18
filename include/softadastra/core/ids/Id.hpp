/*
 * Id.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_ID_HPP
#define SOFTADASTRA_DRIVE_CORE_ID_HPP

#include <string>
#include <random>

#include <softadastra/core/types/StrongType.hpp>

namespace softadastra::core::ids
{
  namespace detail
  {
    inline std::string generate_random_hex(std::size_t length = 16)
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
  }

  template <typename Tag>
  class Id : public types::StrongType<std::string, Tag>
  {
  public:
    using Base = types::StrongType<std::string, Tag>;
    using Base::Base;

    static Id generate()
    {
      return Id(detail::generate_random_hex());
    }

    bool is_valid() const noexcept
    {
      return !this->get().empty();
    }

    const std::string &str() const noexcept
    {
      return this->get();
    }
  };

} // namespace softadastra::core::ids

#endif
