/*
 * OperationId.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_OPERATION_ID_HPP
#define SOFTADASTRA_DRIVE_CORE_OPERATION_ID_HPP

#include <softadastra/core/ids/Id.hpp>

namespace softadastra::core::ids
{

  struct OperationIdTag
  {
  };

  using OperationId = Id<OperationIdTag>;

} // namespace softadastra::core::ids

#endif
