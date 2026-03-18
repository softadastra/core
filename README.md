# softadastra/core

> Foundational primitives for Softadastra systems.

The `core` module provides the **fundamental building blocks** used across all Softadastra modules.

It is designed to be:

* Minimal
* Stable
* Deterministic
* Fully reusable

---

## Purpose

The goal of `softadastra/core` is simple:

> Provide a clean, dependency-free foundation for all higher-level modules.

Everything in Softadastra depends on this module.

---

## Core Principle

> Build once. Reuse everywhere.

The `core` module defines primitives that must remain:

* Generic
* Independent
* Long-term stable

---

## Responsibilities

The `core` module provides:

* Shared types
* Error system
* Strongly-typed identifiers
* Time utilities
* Hash utilities
* Configuration primitives

---

## What this module does NOT do

* No sync logic
* No filesystem logic
* No network logic
* No storage logic

👉 It defines primitives, not behavior.

---

## Design Principles

### 1. Independence

`core` must not depend on any other internal module.

---

### 2. Stability

Changes in `core` affect the entire system.

It must evolve slowly and carefully.

---

### 3. Determinism

All primitives must behave consistently across:

* Platforms
* Machines
* Time

---

### 4. Reusability

Designed to be extracted into:

* Softadastra Core
* SDK
* Other systems

---

## Module Structure

```id="c0r3x1"
modules/core/
├── include/softadastra/core/
│   ├── types/
│   ├── errors/
│   ├── ids/
│   ├── time/
│   ├── hash/
│   └── config/
└── src/
```

---

## Core Components

### Types

Common reusable types used across modules.

Examples:

* Strong wrappers
* Generic containers
* Utility structures

---

### Errors

Structured error handling system.

Features:

* Typed errors
* Severity levels
* Context support

---

### Identifiers (IDs)

Strongly-typed identifiers:

* `FileId`
* `DeviceId`
* `OperationId`

👉 Prevents misuse of raw primitives.

---

### Time

Time-related utilities:

* Timestamps
* Monotonic clocks
* Duration helpers

---

### Hash

Hashing utilities:

* File hashing
* Content fingerprinting
* Deterministic hashing

---

### Config

Configuration primitives:

* Structured config objects
* Validation
* Runtime-safe access

---

## Example Usage

```cpp id="ex8"
#include <softadastra/core/ids/FileId.hpp>
#include <softadastra/core/time/Timestamp.hpp>
#include <softadastra/core/errors/Error.hpp>

using namespace softadastra::core;

FileId fileId = FileId::generate();
auto now = Timestamp::now();

if (!fileId.isValid())
{
    throw Error("Invalid file id");
}
```

---

## Dependencies

### Internal

None.

### External

* C++20 standard library only

---

## Integration

Used by all modules:

* fs
* wal
* metadata
* discovery
* transport
* sync
* store

---

## Rules

* No dependency on higher-level modules
* No business logic
* No side effects
* No hidden behavior

---

## When to modify this module

Only if:

* A primitive is needed by multiple modules
* The abstraction is fundamental
* It does not introduce coupling

---

## When NOT to modify

Do not add:

* Sync logic
* Network logic
* Filesystem logic
* Application-specific code

---

## Roadmap

* Deterministic ID generation strategies
* Streaming hash utilities
* Structured logging primitives
* Platform abstraction layer

---

## Philosophy

The `core` module is the foundation.

> If core is clean, everything built on top stays clean.

---

## Summary

* Lowest-level module
* No internal dependencies
* Used everywhere
* Designed for long-term stability

---

## License

See root LICENSE file.
