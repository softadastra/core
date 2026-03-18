/*
 * DeviceId.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_DEVICE_ID_HPP
#define SOFTADASTRA_DRIVE_CORE_DEVICE_ID_HPP

#include <softadastra/core/ids/Id.hpp>

namespace softadastra::core::ids
{

  struct DeviceIdTag
  {
  };

  using DeviceId = Id<DeviceIdTag>;

} // namespace softadastra::core::ids

#endif
