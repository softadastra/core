/*
 * Assert.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_ASSERT_HPP
#define SOFTADASTRA_DRIVE_CORE_ASSERT_HPP

#include <cstdlib>

namespace softadastra::core::utils
{
  inline void assert_true(bool condition)
  {
    if (!condition)
    {
      std::abort();
    }
  }

} // namespace softadastra::core::utils

#endif
