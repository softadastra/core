/**
 *
 *  @file OperationId.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_OPERATION_ID_HPP
#define SOFTADASTRA_DRIVE_CORE_OPERATION_ID_HPP

#include <softadastra/core/ids/Id.hpp>

namespace softadastra::core::ids
{

  /**
   * @brief Tag type for OperationId.
   *
   * Ensures strong typing and prevents mixing with other IDs.
   */
  struct OperationIdTag
  {
  };

  /**
   * @brief Strong identifier for operations.
   *
   * OperationId uniquely identifies an operation in Softadastra.
   *
   * It is primarily used for:
   * - WAL entries
   * - sync operations
   * - idempotency (avoiding duplicate execution)
   * - tracking distributed actions
   *
   * Properties:
   * - unique per operation
   * - stable across retries
   * - safe for serialization
   *
   * @code
   * OperationId op = OperationId::generate();
   *
   * if (op.is_valid())
   * {
   *   auto id = op.str();
   * }
   * @endcode
   */
  using OperationId = Id<OperationIdTag>;

} // namespace softadastra::core::ids

#endif // SOFTADASTRA_DRIVE_CORE_OPERATION_ID_HPP
