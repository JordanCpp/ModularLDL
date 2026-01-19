// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <memory>

[[nodiscard]]
void* operator new(size_t bytes)
{
	return malloc(bytes);
}

void operator delete(void* ptr)
{
	return free(ptr);
}

[[nodiscard]]
void* operator new[](size_t bytes)
{
	return ::operator new(bytes);
}

void operator delete[](void* ptr)
{
	::operator delete(ptr);
}

[[nodiscard]]
void* operator new(size_t bytes, void* ptr)
{
	return ptr;
}

[[nodiscard]]
void* operator new[](size_t bytes, void* ptr)
{
	return ptr;
}

void __cdecl operator delete(void* ptr, size_t size) noexcept
{
	::operator delete(ptr);
}

void __cdecl operator delete[](void* ptr, size_t size) noexcept
{
	::operator delete[](ptr);
}