// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#pragma once

extern "C"
{
	using LPVOID  = void*;
	using HANDLE  = LPVOID;
	using LPCVOID = const void*;
	using PVOID   = void*;
	using HMODULE = HANDLE;

	using BOOL      = int;
	using DWORD     = unsigned long;
	using LPDWORD   = DWORD*;
	using ULONG_PTR = unsigned long;
	using CHAR      = char;
	using LPCSTR    = const CHAR*;
	using LPSTR     = CHAR*;
	using PROC      = int(__stdcall*)();

	const DWORD STD_INPUT_HANDLE  = ((DWORD)-10);
	const DWORD STD_OUTPUT_HANDLE = ((DWORD)-11);
	const DWORD STD_ERROR_HANDLE  = ((DWORD)-12);

	struct OVERLAPPED
	{
		ULONG_PTR Internal;
		ULONG_PTR InternalHigh;
		union
		{
			struct
			{
				DWORD Offset;
				DWORD OffsetHigh;
			} DUMMYSTRUCTNAME;
			PVOID Pointer;
		} DUMMYUNIONNAME;
		HANDLE hEvent;
	};

	using LPOVERLAPPED = OVERLAPPED*;

	__declspec(dllimport) HANDLE __stdcall GetProcessHeap();
	__declspec(dllimport) void   __stdcall ExitProcess(unsigned int);
	__declspec(dllimport) HANDLE __stdcall GetStdHandle(DWORD nStdHandle);
	__declspec(dllimport) void* __stdcall HeapAlloc(HANDLE hHeap, unsigned int dwFlags, unsigned int dwBytes);
	__declspec(dllimport) int    __stdcall HeapFree(HANDLE hHeap, unsigned int dwFlags, void* lpMem);
	__declspec(dllimport) BOOL   __stdcall WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);

	__declspec(dllimport) HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName);
	__declspec(dllimport) BOOL    __stdcall FreeLibrary(HMODULE hLibModule);
	__declspec(dllimport) PROC    __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
}