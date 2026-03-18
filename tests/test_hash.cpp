/*
 * test_hash.cpp
 */

#include <cstdlib>
#include <vector>
#include <cstdint>
#include <string>

#include <softadastra/core/hash/Hash.hpp>

using namespace softadastra::core::hash;

static int test_empty_hash()
{
  Hash h;

  if (!h.empty())
    return 1;

  return 0;
}

static int test_hash_bytes()
{
  std::vector<std::uint8_t> data = {0xAB, 0xCD, 0x01};

  Hash h(data);

  if (h.empty())
    return 1;

  if (h.bytes().size() != 3)
    return 2;

  if (h.bytes()[0] != 0xAB)
    return 3;

  return 0;
}

static int test_to_hex()
{
  std::vector<std::uint8_t> data = {0x0F, 0xA0};

  Hash h(data);

  std::string hex = h.to_hex();

  if (hex != "0fa0")
    return 1;

  return 0;
}

static int test_comparison()
{
  Hash h1(std::vector<std::uint8_t>{0x01, 0x02});
  Hash h2(std::vector<std::uint8_t>{0x01, 0x02});
  Hash h3(std::vector<std::uint8_t>{0xFF});

  if (!(h1 == h2))
    return 1;

  if (h1 != h2)
    return 2;

  if (h1 == h3)
    return 3;

  return 0;
}

int main()
{
  if (int r = test_empty_hash(); r != 0)
    return r;
  if (int r = test_hash_bytes(); r != 0)
    return r;
  if (int r = test_to_hex(); r != 0)
    return r;
  if (int r = test_comparison(); r != 0)
    return r;

  return 0;
}
