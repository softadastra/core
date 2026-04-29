/**
 *
 *  @file Assert.hpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2026, Softadastra.
 *  All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0.
 *
 *  Softadastra Drive
 *
 */

#ifndef SOFTADASTRA_DRIVE_CORE_ASSERT_HPP
#define SOFTADASTRA_DRIVE_CORE_ASSERT_HPP

#include <cstdlib>
#include <iostream>

namespace softadastra::core::utils
{

  /**
   * @brief Internal assert handler.
   *
   * Prints diagnostic information before aborting.
   */
  inline void assert_fail(
      const char *expr,
      const char *file,
      int line,
      const char *message = nullptr)
  {
    std::cerr << "[softadastra::assert] failure\n";
    std::cerr << "  expression: " << expr << "\n";
    std::cerr << "  location  : " << file << ":" << line << "\n";

    if (message)
    {
      std::cerr << "  message   : " << message << "\n";
    }

    std::abort();
  }

} // namespace softadastra::core::utils

/**
 * @brief Asserts a condition.
 *
 * Example:
 * @code
 * SA_ASSERT(x > 0);
 * SA_ASSERT_MSG(ptr != nullptr, "pointer must not be null");
 * @endcode
 */
#define SA_ASSERT(cond) \
  ((cond) ? (void)0 : ::softadastra::core::utils::assert_fail(#cond, __FILE__, __LINE__))

#define SA_ASSERT_MSG(cond, msg) \
  ((cond) ? (void)0 : ::softadastra::core::utils::assert_fail(#cond, __FILE__, __LINE__, msg))

#endif // SOFTADASTRA_DRIVE_CORE_ASSERT_HPP
