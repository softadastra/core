/*
 * test_time.cpp
 */

#include <cstdlib>
#include <thread>
#include <chrono>

#include <softadastra/core/time/Clock.hpp>
#include <softadastra/core/time/Timestamp.hpp>
#include <softadastra/core/time/Duration.hpp>

using namespace softadastra::core::time;

static int test_timestamp_now()
{
  Timestamp t1 = Timestamp::now();
  Timestamp t2 = Timestamp::now();

  if (!t1.is_valid())
    return 1;

  if (!t2.is_valid())
    return 2;

  // t2 should be >= t1 (not strictly guaranteed but very likely)
  if (t2 < t1)
    return 3;

  return 0;
}

static int test_duration_basic()
{
  Duration d1 = Duration::from_millis(100);
  Duration d2 = Duration::from_seconds(1);

  if (d1.millis() != 100)
    return 1;

  if (d2.millis() != 1000)
    return 2;

  if (!(d1 < d2))
    return 3;

  return 0;
}

static int test_clock_monotonic()
{
  auto t1 = Clock::monotonic_now();

  std::this_thread::sleep_for(std::chrono::milliseconds(10));

  auto t2 = Clock::monotonic_now();

  if (t2 <= t1)
    return 1;

  return 0;
}

int main()
{
  if (int r = test_timestamp_now(); r != 0)
    return r;
  if (int r = test_duration_basic(); r != 0)
    return r;
  if (int r = test_clock_monotonic(); r != 0)
    return r;

  return 0;
}
