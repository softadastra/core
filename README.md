# softadastra/core

> Core C++20 primitives for reliable Softadastra products.

`softadastra/core` is the foundation layer of the Softadastra C++ stack.

Softadastra builds reliability-first products for local-first, offline-first, and distributed applications. This module provides the low-level primitives used across Softadastra products, SDKs, and infrastructure components.

## Purpose

`softadastra/core` exists to provide a stable foundation for higher-level modules such as WAL, Store, Sync, Transport, Metadata, Discovery, SDKs, and product infrastructure.

It is designed to be:

- Minimal
- Stable
- Deterministic
- Reusable
- Product-ready

## What it provides

This module provides foundational primitives such as:

- Result types
- Strong types
- Error types
- Severity levels
- Strongly typed identifiers
- Time primitives
- Hash primitives
- Configuration primitives
- Low-level utilities

## What it does not do

`softadastra/core` does not contain:

- Sync logic
- Storage engines
- Network transport
- Filesystem behavior
- Product-specific logic

It defines primitives, not product behavior.

## Where it fits

```txt
Softadastra products
        |
SDKs and product APIs
        |
Sync, WAL, Store, Transport
        |
softadastra/core
```

`softadastra/core` is the lowest-level shared module. Higher-level modules may depend on it, but it must not depend on higher-level modules.

## Installation

```bash
vix add @softadastra/core
```

## Usage

```cpp
#include <softadastra/core/Core.hpp>
```

## Example

```cpp
#include <softadastra/core/Core.hpp>
#include <iostream>

int main()
{
    auto id = softadastra::core::ids::FileId::generate();

    if (!id.is_valid())
    {
        auto error = softadastra::core::errors::Error::make(
            softadastra::core::errors::ErrorCode::InvalidArgument,
            "invalid file id"
        );

        std::cout << error.message() << "\n";
        return 1;
    }

    std::cout << "FileId: " << id.str() << "\n";
    return 0;
}
```

## Requirements

- C++20
- Standard library only
- No internal Softadastra dependency

## Documentation

For the full documentation, visit [docs.softadastra.com](https://docs.softadastra.com).

## License

Licensed under the Apache License, Version 2.0.
