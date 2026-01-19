// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <cstddef>
#include <string>
#include <memory>
#include <expected>

export module LDL.IWindow;

import LDL.Vec2u;
import LDL.Events;
import LDL.Result;
import LDL.Context;

export namespace LDL
{
	class IWindow
	{
	public:
		virtual ~IWindow() {};
		virtual bool Running() = 0;
		virtual void Present() = 0;
		virtual void Present(std::uint8_t* pixels, std::uint8_t bytesPerPixel) = 0;
		virtual void PollEvents() = 0;
		virtual bool GetEvent(Event& event) = 0;
		virtual bool WaitEvent(Event& event) = 0;
		virtual void StopEvent() = 0;
		virtual void Title(const std::string& title) = 0;
		virtual const std::string& Title() = 0;
		virtual const Vec2u& Size() = 0;
		virtual const Vec2u& Pos() = 0;
		virtual void* NativeHandle() = 0;
	};
	
	std::expected<std::unique_ptr<IWindow>, std::string> CreateWindow(Result& result, Context& renderContext, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode);
}