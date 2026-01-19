// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <stddef.h>

[[nodiscard]]
int strcmp(const char* s1, const char* s2);

[[nodiscard]]
size_t strlen(const char* src);

void* memcpy(void* dst, const void* src, size_t size);