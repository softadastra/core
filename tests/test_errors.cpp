/*
 * test_errors.cpp
 */

#include <cstdlib>

#include <softadastra/core/errors/Error.hpp>
#include <softadastra/core/errors/ErrorCode.hpp>
#include <softadastra/core/errors/Severity.hpp>
#include <softadastra/core/errors/ErrorContext.hpp>

using namespace softadastra::core::errors;

static int test_basic_error()
{
  Error err(
      ErrorCode::InvalidArgument,
      Severity::Error,
      "invalid input");

  if (err.code() != ErrorCode::InvalidArgument)
    return 1;

  if (err.severity() != Severity::Error)
    return 2;

  if (err.message() != "invalid input")
    return 3;

  if (!err.has_error())
    return 4;

  return 0;
}

static int test_error_with_context()
{
  ErrorContext ctx("file: config.json");

  Error err(
      ErrorCode::ConfigInvalid,
      Severity::Critical,
      "bad config",
      ctx);

  if (err.context().empty())
    return 1;

  if (err.context().message() != "file: config.json")
    return 2;

  return 0;
}

static int test_default_error()
{
  Error err;

  if (err.has_error())
    return 1;

  if (err.code() != ErrorCode::None)
    return 2;

  return 0;
}

int main()
{
  if (int r = test_basic_error(); r != 0)
    return r;
  if (int r = test_error_with_context(); r != 0)
    return r;
  if (int r = test_default_error(); r != 0)
    return r;

  return 0;
}
