// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

export module LDL.WinAPI.User32;

import LDL.WinAPI.Types;

extern "C"
{
    struct WNDCLASSA
    {
        UINT        style;
        WNDPROC     lpfnWndProc;
        int         cbClsExtra;
        int         cbWndExtra;
        HINSTANCE   hInstance;
        HICON       hIcon;
        HCURSOR     hCursor;
        HBRUSH      hbrBackground;
        LPCSTR      lpszMenuName;
        LPCSTR      lpszClassName;
    };

    struct WNDCLASSEXW
    {
        UINT        cbSize;
        UINT        style;
        WNDPROC     lpfnWndProc;
        int         cbClsExtra;
        int         cbWndExtra;
        HINSTANCE   hInstance;
        HICON       hIcon;
        HCURSOR     hCursor;
        HBRUSH      hbrBackground;
        LPCWSTR     lpszMenuName;
        LPCWSTR     lpszClassName;
        HICON       hIconSm;
    };
}