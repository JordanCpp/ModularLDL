// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <string>
#include <Windows.h>

export module LDL.WindowSoftware;

import LDL.Result;
import LDL.MainWindow;
import LDL.IWindow;
import LDL.Enums;
import LDL.Events;
import LDL.Vec2u;

export namespace LDL
{
	class WindowSoftware : public IWindow
	{
	public:
        WindowSoftware(Result& result, const Vec2u& pos, const Vec2u& size, const std::string& title, std::size_t mode) :
            _result(result),
            _mainWindow(_result, pos, size, title, mode)
        {
            std::memset(&_bitmapInfo, 0, sizeof(_bitmapInfo));
        }

        ~WindowSoftware()
        {
        }

        void Present(std::uint8_t* pixels, std::uint8_t bytesPerPixel)
        {
            _bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
            _bitmapInfo.bmiHeader.biWidth = (LONG)_mainWindow.Size().x;
            _bitmapInfo.bmiHeader.biHeight = -(LONG)_mainWindow.Size().y;
            _bitmapInfo.bmiHeader.biPlanes = 1;
            _bitmapInfo.bmiHeader.biBitCount = bytesPerPixel * 8;
            _bitmapInfo.bmiHeader.biCompression = BI_RGB;

            int result = SetDIBitsToDevice(_mainWindow.GetHdc(), 0, 0, (DWORD)_mainWindow.Size().x, (DWORD)_mainWindow.Size().y, 0, 0, 0, (UINT)_mainWindow.Size().y, pixels, &_bitmapInfo, DIB_RGB_COLORS);
        }

        void Present()
        {
        }

        const Vec2u& Size()
        {
            return _mainWindow.Size();
        }

        const Vec2u& Pos()
        {
            return _mainWindow.Pos();
        }

        bool Running()
        {
            return _mainWindow.Running();
        }

        void PollEvents()
        {
            _mainWindow.PollEvents();
        }

        bool GetEvent(Event& event)
        {
            return _mainWindow.GetEvent(event);
        }

        bool WaitEvent(Event& event)
        {
            return _mainWindow.WaitEvent(event);
        }

        void StopEvent()
        {
            _mainWindow.StopEvent();
        }

        const std::string& Title()
        {
            return _mainWindow.Title();
        }

        void Title(const std::string& title)
        {
            _mainWindow.Title(title);
        }

        void* NativeHandle()
        {
            return _mainWindow.GetHwnd();
        }
	private:
		Result&     _result;
		MainWindow  _mainWindow;
		BITMAPINFO  _bitmapInfo;
	};
}