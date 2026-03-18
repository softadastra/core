/*
 * FileId.hpp
 */
#ifndef SOFTADASTRA_DRIVE_CORE_FILE_ID_HPP
#define SOFTADASTRA_DRIVE_CORE_FILE_ID_HPP

#include <softadastra/core/ids/Id.hpp>

namespace softadastra::core::ids
{
  struct FileIdTag
  {
  };

  using FileId = Id<FileIdTag>;

} // namespace softadastra::core::ids

#endif
