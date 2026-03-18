# Changelog - softadastra/core

All notable changes to the **core module** are documented in this file.

The `core` module provides **foundational primitives** used across all Softadastra systems.
It is designed to be **minimal, stable, deterministic, and dependency-free (internally)**.

---

## [0.1.0] - Initial Core Foundation

### Added

* Base type system:

  * Strong wrappers
  * Common utility types
* Strongly-typed identifiers:

  * `FileId`
  * `DeviceId`
  * `OperationId`
* Error handling framework:

  * Typed errors
  * Basic context support
* Time utilities:

  * Timestamps
  * Monotonic clock support
  * Duration helpers
* Hash utilities:

  * Basic file hashing
  * Content fingerprinting primitives
* Configuration primitives:

  * Structured config objects
  * Basic validation support

### Design

* No dependency on any internal module
* Designed as the foundation for all other modules
* Focus on determinism and portability

---

## [0.1.1] - Stability Improvements

### Improved

* Stronger typing for identifiers to prevent misuse
* More consistent error propagation model
* Safer time handling using monotonic clocks

### Fixed

* Edge cases in timestamp conversion
* Minor inconsistencies in hash output across platforms

---

## [0.2.0] - Robustness Upgrade

### Added

* Validation helpers for core data structures
* Safer constructors for critical types
* Default value handling in configuration primitives

### Improved

* Error system enriched with clearer context handling
* Hash utilities optimized for larger inputs

---

## [0.3.0] - Developer Experience

### Added

* Debug utilities:

  * String formatting helpers
  * Inspect utilities for core types
* Lightweight logging primitives (optional, non-invasive)

### Improved

* Clearer and more actionable error messages
* Naming consistency across modules

---

## [0.4.0] - Determinism & Consistency

### Added

* Deterministic hashing guarantees across platforms
* Consistent time normalization utilities

### Improved

* Cross-platform behavior consistency
* Reduced hidden assumptions in core primitives

---

## [0.5.0] - Performance Improvements

### Added

* Optimized hash computation paths
* Lightweight utility helpers for performance-critical code

### Improved

* Reduced overhead in common operations
* Faster ID generation

---

## [0.6.0] - API Stabilization

### Added

* Namespace stabilization (`softadastra::core`)
* Public API cleanup
* Documentation for all exposed types

### Improved

* Clear separation between internal and public interfaces
* Removal of unstable or experimental APIs

---

## [0.7.0] - Extraction Ready

### Added

* Final modular boundaries for extraction
* Compatibility considerations for SDK usage

### Improved

* Decoupling from application-specific assumptions
* Prepared for reuse in:

  * Softadastra Sync OS
  * SDK
  * Independent libraries

---

## Roadmap

### Planned

* Deterministic ID generation strategies
* Streaming hash utilities
* Structured logging system (JSON-ready)
* Platform abstraction layer (time, filesystem, env)

---

## Philosophy

The `core` module is the foundation of everything.

> If it is not stable here, it cannot be reliable anywhere.

---

## Rules

* No dependency on higher-level modules
* No business logic
* No side effects
* No breaking changes without strong justification

---

## Summary

The `core` module ensures:

* Stability
* Determinism
* Reusability
* Consistency across the system

It is the **foundation of Softadastra**.
