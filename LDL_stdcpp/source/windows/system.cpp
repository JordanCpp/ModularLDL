// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <windows/winapi.hpp>

extern "C" int main();

extern "C" void EntryPoint()
{
	int result = main();

	ExitProcess(result);
}

static HANDLE GetHeap() noexcept
{
	static HANDLE h = GetProcessHeap();

	return h;
}

static HANDLE GetOutput() noexcept
{
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	return h;
}

void write(const char* source, size_t length) noexcept
{
	if (source)
	{
		DWORD  written = 0;

		WriteFile(GetOutput(), source, length, &written, nullptr);
	}
}

void* malloc(size_t size) noexcept
{
	return HeapAlloc(GetHeap(), 0, size);
}

void free(void* ptr) noexcept
{
	if (ptr)
	{
		HeapFree(GetHeap(), 0, ptr);
	}
}