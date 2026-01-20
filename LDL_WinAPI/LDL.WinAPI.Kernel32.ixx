// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

export module LDL.WinAPI.Kernel32;

import LDL.WinAPI.Types;

extern "C"
{
    /********************************************************************************************************************
                                                             Library
    ********************************************************************************************************************/
    __declspec(dllimport) HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName);
    __declspec(dllimport) BOOL    __stdcall FreeLibrary(HMODULE hLibModule);
    __declspec(dllimport) PROC    __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName);

    /********************************************************************************************************************
                                                             Process
    ********************************************************************************************************************/
    __declspec(dllimport) HANDLE __stdcall GetProcessHeap();
    __declspec(dllimport) void   __stdcall ExitProcess(unsigned int);

    /********************************************************************************************************************
                                                             Heap
    ********************************************************************************************************************/
    __declspec(dllimport) void* __stdcall HeapAlloc(HANDLE hHeap, unsigned int dwFlags, unsigned int dwBytes);
    __declspec(dllimport) int   __stdcall HeapFree(HANDLE hHeap, unsigned int dwFlags, void* lpMem);
}