// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <cstddef>
#include <cstdint>

export module LDL.Events;

import LDL.Enums;

export namespace LDL
{
	class GainedFocus
	{
	public:
		std::uint8_t Type;
	};

	class Keyboard
	{
	public:
		std::uint8_t Type;
		ButtonState  State;
		KeyboardKey  Key;
	};

	class LostFocus
	{
	public:
		std::uint8_t Type;
	};

	class Mouse
	{
	public:
		std::uint8_t Type;
		std::size_t  PosX;
		std::size_t  PosY;
		std::size_t  PosRelX;
		std::size_t  PosRelY;
		ButtonState  State;
		MouseButton  Button;
		MouseScroll  Scroll;
		std::size_t  Delta;
	};

	class Quit
	{
	public:
		std::uint8_t Type;
	};

	class Resize
	{
	public:
		std::uint8_t Type;
		std::size_t  Width;
		std::size_t  Height;
	};

	enum
	{
		IsQuit = 1,
		IsMouseMove,
		IsMouseClick,
		IsResize,
		IsKeyboard,
		IsGainedFocus,
		IsLostFocus,
		IsMouseScroll
	};

	class Event
	{
	public:
		union
		{
			std::uint8_t Type;
			Quit         Quit;
			Mouse        Mouse;
			Resize       Resize;
			Keyboard     Keyboard;
			GainedFocus  GainedFocus;
			LostFocus    LostFocus;
		};

		bool IsKeyPressed(KeyboardKey key)
		{
			return (Type == IsKeyboard && Keyboard.Key == key && Keyboard.State == ButtonState::Pressed);
		}

		bool IsKeyReleased(KeyboardKey key)
		{
			return (Type == IsKeyboard && Keyboard.Key == key && Keyboard.State == ButtonState::Released);

		}

		bool IsMousePressed(MouseButton key)
		{
			return (Type == IsMouseClick && Mouse.Button == key && Mouse.State == ButtonState::Pressed);
		}

		bool IsMouseReleased(MouseButton key)
		{
			return (Type == IsMouseClick && Mouse.Button == key && Mouse.State == ButtonState::Released);
		}
	};
}