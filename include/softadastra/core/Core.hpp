/**
 *
 *  @file Core.hpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2026, Softadastra.
 *  All rights reserved.
 *  https://github.com/softadastra/softadastra
 *
 *  Licensed under the Apache License, Version 2.0.
 *
 *  Softadastra Core
 *
 */

#ifndef SOFTADASTRA_CORE_CORE_HPP
#define SOFTADASTRA_CORE_CORE_HPP

// Config
#include <softadastra/core/config/Config.hpp>
#include <softadastra/core/config/ConfigValidator.hpp>
#include <softadastra/core/config/ConfigValue.hpp>

// Errors
#include <softadastra/core/errors/Error.hpp>
#include <softadastra/core/errors/ErrorCode.hpp>
#include <softadastra/core/errors/ErrorContext.hpp>
#include <softadastra/core/errors/Severity.hpp>

// Hash
#include <softadastra/core/hash/Hash.hpp>
#include <softadastra/core/hash/HashAlgorithm.hpp>
#include <softadastra/core/hash/Hasher.hpp>

// IDs
#include <softadastra/core/ids/DeviceId.hpp>
#include <softadastra/core/ids/FileId.hpp>
#include <softadastra/core/ids/Id.hpp>
#include <softadastra/core/ids/OperationId.hpp>

// Time
#include <softadastra/core/time/Clock.hpp>
#include <softadastra/core/time/Duration.hpp>
#include <softadastra/core/time/Timestamp.hpp>

// Types
#include <softadastra/core/types/NonCopyable.hpp>
#include <softadastra/core/types/Result.hpp>
#include <softadastra/core/types/StrongType.hpp>

// Utils
#include <softadastra/core/utils/Assert.hpp>
#include <softadastra/core/utils/ScopeGuard.hpp>
#include <softadastra/core/utils/StringUtils.hpp>

#endif // SOFTADASTRA_CORE_CORE_HPP
