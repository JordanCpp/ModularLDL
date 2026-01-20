// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

export module LDL.WinAPI.Types;

extern "C" 
{
    using LPVOID    = void*;
    using HANDLE    = LPVOID;
    using HWND      = HANDLE;
    using HDC       = HANDLE;
    using HMODULE   = HANDLE;
    using HINSTANCE = HANDLE;
    using HICON     = HANDLE;
    using HCURSOR   = HANDLE;
    using HBRUSH    = HANDLE;
    using HGDIOBJ   = HANDLE;
    using HMENU     = HANDLE;
    using BOOL      = int;
    using CHAR      = char;
    using LPCSTR    = const CHAR*;
    using LPSTR     = CHAR*;
    using PROC      = int(__stdcall*)();
    using UINT_PTR  = unsigned int;
    using LONG_PTR  = signed int;
    using WPARAM    = UINT_PTR;
    using LPARAM    = LONG_PTR;
    using LRESULT   = LONG_PTR;
    using UINT      = unsigned int;
    using LONG      = long;
    using DWORD     = unsigned long;
    using WORD      = unsigned short;
    using LPDWORD   = DWORD*;
    using ULONG_PTR = unsigned long;
    using DWORD_PTR = ULONG_PTR;
    using ATOM      = WORD;
    using WNDPROC   = LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM);
    using MMRESULT  = UINT;
    using WCHAR     = unsigned short;
    using LPCWSTR   = const WCHAR*;
    using LPCVOID   = const void*;
    using PVOID     = void*;
}