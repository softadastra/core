# Core Module Guide

> Foundational primitives for all Softadastra systems.

The `core` module is the lowest-level building block of Softadastra. Everything else is built on top of it.

## Overview

The `core` module provides:

- Type-safe primitives
- Explicit error handling
- Deterministic time utilities
- Strong identifiers
- Hash abstractions
- Configuration system
- Low-level utilities

It is:

- Minimal
- Stable
- Deterministic
- Dependency-free

## Getting Started

```cpp
#include <softadastra/core/Core.hpp>
```

## Result & Error System

Softadastra uses explicit error handling. No exceptions required.

### Example

```cpp
using namespace softadastra::core;

types::Result<int, errors::Error> divide(int a, int b)
{
    if (b == 0)
    {
        return types::Result<int, errors::Error>::err(
            errors::Error::make(
                errors::ErrorCode::InvalidArgument,
                "division by zero"));
    }

    return types::Result<int, errors::Error>::ok(a / b);
}
```

### Usage

```cpp
auto res = divide(10, 2);

if (res.is_ok())
{
    std::cout << res.value();
}
else
{
    std::cout << res.error().message();
}
```

## Strong Types

Avoid primitive misuse using `StrongType`:

```cpp
struct UserIdTag {};
struct FileIdTag {};

using UserId = types::StrongType<std::string, UserIdTag>;
using FileId = types::StrongType<std::string, FileIdTag>;
```

## Identifiers

Softadastra provides built-in strong identifiers:

```cpp
using namespace softadastra::core::ids;

auto file   = FileId::generate();
auto device = DeviceId::generate();
```

## Time System

### Timestamp

Used for persistent time:

```cpp
auto now = time::Timestamp::now();
std::cout << now.millis();
```

### Duration

Used for time intervals:

```cpp
auto d = time::Duration::from_seconds(5);
```

### Clock

```cpp
auto now  = time::Clock::now();
auto mono = time::Clock::monotonic_now();
```

## Hash System

### Hash

```cpp
using namespace softadastra::core::hash;

Hash h(HashAlgorithm::SHA256, {0x12, 0x34});
```

### Hasher Interface

```cpp
class SHA256Hasher : public Hasher
{
public:
    Hash hash(const Buffer& data) const override;
};
```

## Configuration System

### Config

```cpp
config::Config cfg;

cfg.set("port",  config::ConfigValue(8080));
cfg.set("debug", config::ConfigValue(true));
```

### Validation

```cpp
auto port = config::ConfigValidator::require<std::int64_t>(
    cfg.get("port"), "port");

if (port.is_err())
{
    std::cout << port.error().message();
}
```

## Utilities

### ScopeGuard

```cpp
auto guard = utils::make_scope_guard([&] {
    rollback();
});

// success
guard.dismiss();
```

### Assert

```cpp
SA_ASSERT(x > 0);
SA_ASSERT_MSG(ptr != nullptr, "pointer must not be null");
```

### StringUtils

```cpp
auto trimmed = utils::StringUtils::trim("  hello  ");

auto parts = utils::StringUtils::split("a,b,c", ',');
```

## Design Rules

### 1. No dependencies
`core` must not depend on any other module.

### 2. No business logic
Only primitives.

### 3. Deterministic behavior
Same input → same output.

### 4. Stability first
Breaking changes are critical.

## When to Use Core

Use `core` when you need:

- Shared types across modules
- Safe error handling
- Deterministic primitives
- Cross-module abstractions

**Do NOT put in `core`:**

- Filesystem logic
- Networking
- Sync logic
- Storage engines

## Architecture Role

```
core       →  foundation
wal        →  durability
sync       →  convergence
transport  →  communication
```

## Best Practices

- Prefer `Result` over exceptions
- Use strong IDs instead of raw strings
- Use `Timestamp` for persistence
- Use `Duration` for time intervals
- Always attach context to errors

## Summary

- Core = foundation of Softadastra
- Zero dependencies
- Used everywhere
- Designed for long-term stability

## Next Steps

After `core`, explore:

- WAL module
- Sync engine
- Transport layer
