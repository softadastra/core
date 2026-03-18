/*
 * test_ids.cpp
 */

#include <cstdlib>

#include <softadastra/core/ids/FileId.hpp>
#include <softadastra/core/ids/DeviceId.hpp>
#include <softadastra/core/ids/OperationId.hpp>

using namespace softadastra::core::ids;

static int test_generate_and_valid()
{
  FileId id = FileId::generate();

  if (!id.is_valid())
    return 1;

  if (id.str().empty())
    return 2;

  return 0;
}

static int test_uniqueness()
{
  FileId a = FileId::generate();
  FileId b = FileId::generate();

  if (a == b)
    return 1;

  return 0;
}

static int test_different_types()
{
  FileId f = FileId::generate();
  DeviceId d = DeviceId::generate();

  if (!f.is_valid() || !d.is_valid())
    return 1;

  return 0;
}

static int test_operation_id()
{
  OperationId op = OperationId::generate();

  if (!op.is_valid())
    return 1;

  return 0;
}

int main()
{
  if (int r = test_generate_and_valid(); r != 0)
    return r;
  if (int r = test_uniqueness(); r != 0)
    return r;
  if (int r = test_different_types(); r != 0)
    return r;
  if (int r = test_operation_id(); r != 0)
    return r;

  return 0;
}
