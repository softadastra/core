/**
 *
 *  @file FileId.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_FILE_ID_HPP
#define SOFTADASTRA_DRIVE_CORE_FILE_ID_HPP

#include <softadastra/core/ids/Id.hpp>

namespace softadastra::core::ids
{

  /**
   * @brief Tag type for FileId.
   *
   * Used to create a strong type distinct from other identifiers.
   */
  struct FileIdTag
  {
  };

  /**
   * @brief Strong identifier for files.
   *
   * FileId represents a unique identifier for files in Softadastra.
   *
   * It is type-safe and cannot be mixed with other identifiers
   * such as NodeId, PeerId, etc.
   *
   * @code
   * FileId id = FileId::generate();
   *
   * if (id.is_valid())
   * {
   *   auto value = id.str();
   * }
   * @endcode
   */
  using FileId = Id<FileIdTag>;

} // namespace softadastra::core::ids

#endif // SOFTADASTRA_DRIVE_CORE_FILE_ID_HPP
