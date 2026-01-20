// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstddef>

[[nodiscard]]
void* operator new(size_t bytes);
void operator delete(void* ptr);

[[nodiscard]]
void* operator new[](size_t bytes);
void operator delete[](void* ptr);

[[nodiscard]]
void* operator new(size_t bytes, void* ptr);
void __cdecl operator delete(void* ptr, size_t size) noexcept;

[[nodiscard]]
void* operator new[](size_t bytes, void* ptr);
void __cdecl operator delete[](void* ptr, size_t size) noexcept;