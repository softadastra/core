# softadastra/core

> Foundational primitives for Softadastra systems.

The `core` module provides the fundamental building blocks used across all Softadastra modules.

It is designed to be:

- Minimal
- Stable
- Deterministic
- Fully reusable

## Purpose

The goal of `softadastra/core` is simple:

> Provide a clean, dependency-free foundation for all higher-level modules.

Everything in Softadastra depends on this module.

## Core Principle

> *Build once. Reuse everywhere.*

The `core` module defines primitives that must remain:

- Generic
- Independent
- Long-term stable

## Responsibilities

The `core` module provides:

- Shared types (`Result`, `StrongType`, etc.)
- Error system (`Error`, `ErrorCode`, `Severity`)
- Strongly-typed identifiers (`FileId`, `DeviceId`, `OperationId`)
- Time utilities (`Timestamp`, `Duration`, `Clock`)
- Hash primitives (`Hash`, `Hasher`, `HashAlgorithm`)
- Configuration primitives (`Config`, `ConfigValue`, `ConfigValidator`)
- Low-level utilities (`Assert`, `ScopeGuard`, `StringUtils`)

## What this module does NOT do

- No sync logic
- No filesystem logic
- No network logic
- No storage logic

> 👉 It defines primitives, not behavior.

## Design Principles

### 1. Independence

`core` must not depend on any other internal module.

### 2. Stability

Changes in `core` affect the entire system. It must evolve slowly and carefully.

### 3. Determinism

All primitives must behave consistently across platforms, machines, and time.

### 4. Reusability

Designed to be reusable in Softadastra Core, SDKs, and external systems.

## Module Structure

```
modules/core/
├── include/softadastra/core/
│   ├── config/
│   ├── errors/
│   ├── hash/
│   ├── ids/
│   ├── time/
│   ├── types/
│   ├── utils/
│   └── Core.hpp
└── src/
```

## Core Components

### Types

Reusable generic primitives:

- `Result<T, E>`
- `StrongType<T, Tag>`
- `NonCopyable`

### Errors

Structured error system:

- `Error`
- `ErrorCode`
- `Severity`
- `ErrorContext`

> 👉 Designed for explicit error handling (no exceptions required)

### Identifiers (IDs)

Strongly-typed identifiers:

- `FileId`
- `DeviceId`
- `OperationId`

> 👉 Prevents misuse of raw primitives (e.g. mixing IDs)

### Time

Time-related utilities:

- `Timestamp` (persistent time)
- `Duration` (time intervals)
- `Clock` (wall + monotonic)

### Hash

Hashing primitives:

- `Hash`
- `HashAlgorithm`
- `Hasher` (interface)

### Config

Configuration system:

- `Config`
- `ConfigValue`
- `ConfigValidator`

### Utils

Low-level helpers:

- `Assert`
- `ScopeGuard`
- `StringUtils`

## Example Usage

```cpp
#include <softadastra/core/Core.hpp>

using namespace softadastra::core;

int main()
{
    auto fileId = ids::FileId::generate();
    auto now    = time::Timestamp::now();

    if (!fileId.is_valid())
    {
        auto err = errors::Error::make(
            errors::ErrorCode::InvalidArgument,
            "invalid file id");

        std::cout << err.message() << "\n";
        return 1;
    }

    std::cout << "FileId: "    << fileId.str()    << "\n";
    std::cout << "Now (ms): "  << now.millis()    << "\n";

    return 0;
}
```

## Public API

Include everything via:

```cpp
#include <softadastra/core/Core.hpp>
```

## Dependencies

**Internal:** none.

**External:** C++20 standard library only.

## Integration

Used by all modules:

- `fs`
- `wal`
- `metadata`
- `discovery`
- `transport`
- `sync`
- `store`

## Rules

- No dependency on higher-level modules
- No business logic
- No side effects
- No hidden behavior

## When to modify this module

Only if:

- A primitive is needed by multiple modules
- The abstraction is fundamental
- It does not introduce coupling

**Do not add:**

- Sync logic
- Network logic
- Filesystem logic
- Application-specific code

## Roadmap

- [ ] Deterministic ID generation strategies
- [ ] Streaming hash utilities
- [ ] Structured logging primitives
- [ ] Platform abstraction layer

## Philosophy

> The `core` module is the foundation.
> If core is clean, everything built on top stays clean.

## Summary

- Lowest-level module
- No internal dependencies
- Used everywhere
- Designed for long-term stability

## Installation

```bash
vix add @softadastra/core
```

## License

Licensed under the Apache License, Version 2.0.
