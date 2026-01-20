// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

export module LDL.WinAPI.Structs;

import LDL.WinAPI.Types;

export import LDL.WinAPI.Types;

extern "C" 
{
    /********************************************************************************************************************
                                                             Types
    ********************************************************************************************************************/

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

    using WCHAR   = unsigned short;
    using LPCWSTR = const WCHAR*;

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

     struct POINT
     {
         LONG  x;
         LONG  y;
     };

     struct RECT
     {
         LONG    left;
         LONG    top;
         LONG    right;
         LONG    bottom;
     };

     struct MSG 
     {
         HWND        hwnd;
         UINT        message;
         WPARAM      wParam;
         LPARAM      lParam;
         DWORD       time;
         POINT       pt;
     };

     using LPMSG = MSG*;

     const int GWL_USERDATA  = (-21);
     const int GWLP_USERDATA = (-21);

     const UINT CS_VREDRAW = 0x0001;
     const UINT CS_HREDRAW = 0x0002;
     const UINT CS_DBLCLKS = 0x0008;
     const UINT CS_OWNDC = 0x0020;
     const UINT CS_CLASSDC = 0x0040;
     const UINT CS_PARENTDC = 0x0080;
     const UINT CS_NOCLOSE = 0x0200;
     const UINT CS_SAVEBITS = 0x0800;
     const UINT CS_BYTEALIGNCLIENT = 0x1000;
     const UINT CS_BYTEALIGNWINDOW = 0x2000;
     const UINT CS_GLOBALCLASS = 0x4000;

     const int WHITE_BRUSH = 0;
     const int LTGRAY_BRUSH = 1;
     const int GRAY_BRUSH = 2;
     const int DKGRAY_BRUSH = 3;
     const int BLACK_BRUSH = 4;
     const int NULL_BRUSH = 5;
     const int HOLLOW_BRUSH = NULL_BRUSH;
     const int WHITE_PEN = 6;
     const int BLACK_PEN = 7;
     const int NULL_PEN = 8;
     const int OEM_FIXED_FONT = 10;
     const int ANSI_FIXED_FONT = 11;
     const int ANSI_VAR_FONT = 12;
     const int SYSTEM_FONT = 13;
     const int DEVICE_DEFAULT_FONT = 14;
     const int DEFAULT_PALETTE = 15;
     const int SYSTEM_FIXED_FONT = 16;

     inline WORD LOWORD(LPARAM l)
     {
         return  ((WORD)(((DWORD_PTR)(l)) & 0xffff));
     }

     inline WORD HIWORD(LPARAM l)
     {
         return ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff));
     }

     inline LPSTR MAKEINTRESOURCEA(WORD i)
     {
         return ((LPSTR)((ULONG_PTR)((WORD)(i))));
     }

     const LPSTR IDI_APPLICATION = MAKEINTRESOURCEA(32512);
     const LPSTR IDI_HAND        = MAKEINTRESOURCEA(32513);
     const LPSTR IDI_QUESTION    = MAKEINTRESOURCEA(32514);
     const LPSTR IDI_EXCLAMATION = MAKEINTRESOURCEA(32515);
     const LPSTR IDI_ASTERISK    = MAKEINTRESOURCEA(32516);

     const LPSTR IDC_ARROW    = MAKEINTRESOURCEA(32512);
     const LPSTR IDC_IBEAM    = MAKEINTRESOURCEA(32513);
     const LPSTR IDC_WAIT     = MAKEINTRESOURCEA(32514);
     const LPSTR IDC_CROSS    = MAKEINTRESOURCEA(32515);
     const LPSTR IDC_UPARROW  = MAKEINTRESOURCEA(32516);
     const LPSTR IDC_SIZE     = MAKEINTRESOURCEA(32640);
     const LPSTR IDC_ICON     = MAKEINTRESOURCEA(32641);
     const LPSTR IDC_SIZENWSE = MAKEINTRESOURCEA(32642);
     const LPSTR IDC_SIZENESW = MAKEINTRESOURCEA(32643);
     const LPSTR IDC_SIZEWE   = MAKEINTRESOURCEA(32644);
     const LPSTR IDC_SIZENS   = MAKEINTRESOURCEA(32645);
     const LPSTR IDC_SIZEALL  = MAKEINTRESOURCEA(32646);
     const LPSTR IDC_NO       = MAKEINTRESOURCEA(32648);

     struct CREATESTRUCTA 
     {
         LPVOID      lpCreateParams;
         HINSTANCE   hInstance;
         HMENU       hMenu;
         HWND        hwndParent;
         int         cy;
         int         cx;
         int         y;
         int         x;
         LONG        style;
         LPCSTR      lpszName;
         LPCSTR      lpszClass;
         DWORD       dwExStyle;
     };

     const ATOM INVALID_ATOM = ((ATOM)0);

     const DWORD WS_OVERLAPPED = 0x00000000L;
     const DWORD WS_POPUP = 0x80000000L;
     const DWORD WS_CHILD = 0x40000000L;
     const DWORD WS_MINIMIZE = 0x20000000L;
     const DWORD WS_VISIBLE = 0x10000000L;
     const DWORD WS_DISABLED = 0x08000000L;
     const DWORD WS_CLIPSIBLINGS = 0x04000000L;
     const DWORD WS_CLIPCHILDREN = 0x02000000L;
     const DWORD WS_MAXIMIZE = 0x01000000L;
     const DWORD WS_CAPTION = 0x00C00000L;
     const DWORD WS_BORDER = 0x00800000L;
     const DWORD WS_DLGFRAME = 0x00400000L;
     const DWORD WS_VSCROLL = 0x00200000L;
     const DWORD WS_HSCROLL = 0x00100000L;
     const DWORD WS_SYSMENU = 0x00080000L;
     const DWORD WS_THICKFRAME = 0x00040000L;
     const DWORD WS_GROUP = 0x00020000L;
     const DWORD WS_TABSTOP = 0x00010000L;
     const DWORD WS_MINIMIZEBOX = 0x00020000L;
     const DWORD WS_MAXIMIZEBOX = 0x00010000L;

     const DWORD WS_OVERLAPPEDWINDOW = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);

     const DWORD STD_INPUT_HANDLE  = ((DWORD)-10);
     const DWORD STD_OUTPUT_HANDLE = ((DWORD)-11);
     const DWORD STD_ERROR_HANDLE  = ((DWORD)-12);

     const UINT WM_NCCREATE = 0x0081;
     const UINT WM_NULL = 0x0000;
     const UINT WM_CREATE = 0x0001;
     const UINT WM_MOVE = 0x0003;
     const UINT WM_ACTIVATE = 0x0006;
     const UINT WM_PAINT = 0x000F;
     const UINT WM_DESTROY = 0x0002;
     const UINT WM_MOUSEMOVE = 0x0200;
     const UINT WM_LBUTTONDOWN = 0x0201;
     const UINT WM_LBUTTONUP = 0x0202;
     const UINT WM_RBUTTONDOWN = 0x0204;
     const UINT WM_RBUTTONUP = 0x0205;
     const UINT WM_MBUTTONDOWN = 0x0207;
     const UINT WM_MBUTTONUP = 0x0208;
     const UINT WM_SIZE = 0x0005;
     const UINT WM_CLOSE = 0x0010;
     const UINT WM_KEYDOWN = 0x0100;
     const UINT WM_SYSKEYDOWN = 0x0104;
     const UINT WM_KEYUP = 0x0101;
     const UINT WM_SYSKEYUP = 0x0105;
     const UINT WM_SETFOCUS = 0x0007;
     const UINT WM_KILLFOCUS = 0x0008;
     const UINT WM_MOUSEWHEEL = 0x020A;
     const UINT WM_MOUSEHWHEEL = 0x020E;

     using LPCVOID = const void*;
     using PVOID = void*;

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

    /********************************************************************************************************************
                                                             Window
    ********************************************************************************************************************/
    __declspec(dllimport) void*   __stdcall GetActiveWindow();
    __declspec(dllimport) int     __stdcall MessageBoxA(HWND hWnd, const char* lpText, const char* lpCaption, unsigned int uType);
    __declspec(dllimport) LRESULT __stdcall DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
    __declspec(dllimport) LRESULT __stdcall DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
    __declspec(dllimport) LONG    __stdcall GetWindowLongA(HWND hWnd, int nIndex);
    __declspec(dllimport) HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName);
    __declspec(dllimport) HMODULE __stdcall GetModuleHandleW(LPCWSTR lpModuleName);
    __declspec(dllimport) LONG    __stdcall SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong);
    __declspec(dllimport) ATOM    __stdcall RegisterClassA(const WNDCLASSA* lpWndClass);
    __declspec(dllimport) ATOM    __stdcall RegisterClassW(const WNDCLASSEXW* lpWndClass);
    __declspec(dllimport) HWND    __stdcall CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
    __declspec(dllimport) BOOL    __stdcall PeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
    __declspec(dllimport) BOOL    __stdcall PeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
    __declspec(dllimport) BOOL    __stdcall TranslateMessage(const MSG* lpMsg);
    __declspec(dllimport) LRESULT __stdcall DispatchMessageA(const MSG* lpMsg);
    __declspec(dllimport) LRESULT __stdcall DispatchMessageW(const MSG* lpMsg);
    __declspec(dllimport) BOOL    __stdcall GetMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
    __declspec(dllimport) BOOL    __stdcall GetMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
    __declspec(dllimport) void    __stdcall PostQuitMessage(int nExitCode);

    __declspec(dllimport) MMRESULT __stdcall timeBeginPeriod(UINT uPeriod);
    __declspec(dllimport) MMRESULT __stdcall timeEndPeriod(UINT uPeriod);
    /********************************************************************************************************************
                                                            Library
    ********************************************************************************************************************/
    __declspec(dllimport) HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName);
    __declspec(dllimport) BOOL    __stdcall FreeLibrary(HMODULE hLibModule);
    __declspec(dllimport) PROC    __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
    /********************************************************************************************************************
                                                             GDI
    ********************************************************************************************************************/
    __declspec(dllimport) HGDIOBJ __stdcall GetStockObject(int i);
    
    __declspec(dllimport) HICON   __stdcall LoadIconA(HINSTANCE hInstance, LPCSTR lpIconName);
    __declspec(dllimport) HICON   __stdcall LoadIconW(HINSTANCE hInstance, LPCWSTR lpIconName);

    __declspec(dllimport) HCURSOR __stdcall LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName);
    __declspec(dllimport) HCURSOR __stdcall LoadCursorW(HINSTANCE hInstance, LPCWSTR lpCursorName);

    __declspec(dllimport) BOOL    __stdcall WriteConsoleA(HANDLE hConsoleOutput, const void* lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved);

    __declspec(dllimport) HANDLE __stdcall GetStdHandle(DWORD nStdHandle);

    __declspec(dllimport) BOOL __stdcall WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
}
