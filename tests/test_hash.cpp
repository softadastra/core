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

  if (h.is_valid())
    return 2;

  return 0;
}

static int test_hash_bytes()
{
  std::vector<std::uint8_t> data = {0xAB, 0xCD, 0x01};

  Hash h(HashAlgorithm::SHA256, data);

  if (h.empty())
    return 1;

  if (!h.is_valid())
    return 2;

  if (h.algorithm() != HashAlgorithm::SHA256)
    return 3;

  if (h.bytes().size() != 3)
    return 4;

  if (h.bytes()[0] != 0xAB)
    return 5;

  return 0;
}

static int test_to_hex()
{
  std::vector<std::uint8_t> data = {0x0F, 0xA0};

  Hash h(HashAlgorithm::SHA256, data);

  std::string hex = h.to_hex();

  if (hex != "0fa0")
    return 1;

  return 0;
}

static int test_comparison()
{
  Hash h1(HashAlgorithm::SHA256, std::vector<std::uint8_t>{0x01, 0x02});
  Hash h2(HashAlgorithm::SHA256, std::vector<std::uint8_t>{0x01, 0x02});
  Hash h3(HashAlgorithm::SHA256, std::vector<std::uint8_t>{0xFF});
  Hash h4(HashAlgorithm::SHA512, std::vector<std::uint8_t>{0x01, 0x02});

  if (!(h1 == h2))
    return 1;

  if (h1 != h2)
    return 2;

  if (h1 == h3)
    return 3;

  if (h1 == h4)
    return 4;

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
