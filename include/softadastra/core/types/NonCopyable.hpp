/*
 * NonCopyable.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_NON_COPYABLE_HPP
#define SOFTADASTRA_DRIVE_CORE_NON_COPYABLE_HPP

namespace softadastra::core::types
{
  class NonCopyable
  {
  protected:
    constexpr NonCopyable() = default;
    ~NonCopyable() = default;

    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;

    NonCopyable(NonCopyable &&) = default;
    NonCopyable &operator=(NonCopyable &&) = default;
  };

} // namespace softadastra::core::types

#endif
