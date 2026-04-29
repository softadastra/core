/**
 *
 *  @file DeviceId.hpp
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

#ifndef SOFTADASTRA_DRIVE_CORE_DEVICE_ID_HPP
#define SOFTADASTRA_DRIVE_CORE_DEVICE_ID_HPP

#include <softadastra/core/ids/Id.hpp>

namespace softadastra::core::ids
{

  /**
   * @brief Tag type for DeviceId.
   *
   * Ensures strong typing and prevents mixing with other IDs.
   */
  struct DeviceIdTag
  {
  };

  /**
   * @brief Strong identifier for devices.
   *
   * DeviceId uniquely identifies a device participating in Softadastra.
   *
   * Typical use cases:
   * - identifying a client device
   * - associating data with a specific machine
   * - multi-device synchronization
   *
   * @code
   * DeviceId device = DeviceId::generate();
   *
   * if (device.is_valid())
   * {
   *   auto id = device.str();
   * }
   * @endcode
   */
  using DeviceId = Id<DeviceIdTag>;

} // namespace softadastra::core::ids

#endif // SOFTADASTRA_DRIVE_CORE_DEVICE_ID_HPP
