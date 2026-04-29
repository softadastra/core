/**
 *
 *  @file NonCopyable.hpp
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
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  Softadastra Drive
 *
 */

#ifndef SOFTADASTRA_DRIVE_CORE_NON_COPYABLE_HPP
#define SOFTADASTRA_DRIVE_CORE_NON_COPYABLE_HPP

namespace softadastra::core::types
{

  /**
   * @brief Utility base class to disable copy semantics.
   *
   * NonCopyable is intended to be inherited by classes that must not be copied.
   *
   * Typical use cases:
   * - resource owners (file handles, sockets, locks)
   * - single-instance components
   * - objects managing unique ownership
   *
   * Move semantics are still allowed.
   *
   * @code
   * class FileHandle : public NonCopyable
   * {
   * public:
   *   FileHandle();
   * };
   *
   * FileHandle a;
   * FileHandle b = a;            // ❌ compile error
   * FileHandle c = std::move(a); // ✅ allowed
   * @endcode
   */
  class NonCopyable
  {
  protected:
    /**
     * @brief Default constructor.
     */
    constexpr NonCopyable() = default;

    /**
     * @brief Default destructor.
     */
    ~NonCopyable() = default;

    /**
     * @brief Copy constructor deleted.
     */
    NonCopyable(const NonCopyable &) = delete;

    /**
     * @brief Copy assignment deleted.
     */
    NonCopyable &operator=(const NonCopyable &) = delete;

    /**
     * @brief Move constructor allowed.
     */
    NonCopyable(NonCopyable &&) = default;

    /**
     * @brief Move assignment allowed.
     */
    NonCopyable &operator=(NonCopyable &&) = default;
  };

} // namespace softadastra::core::types

#endif // SOFTADASTRA_DRIVE_CORE_NON_COPYABLE_HPP
