// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <cstdint>

export module LDL.Enums;

export namespace LDL
{
	enum class ButtonState : std::uint8_t
	{
		Pressed = 1,
		Released
	};

	enum class KeyboardKey : std::uint8_t
	{
		Unknown = 1,
		LSystem,
		RSystem,
		Menu,
		Semicolon,
		Slash,
		Equal,
		Hyphen,
		LBracket,
		RBracket,
		Comma,
		Period,
		Quote,
		Backslash,
		Tilde,
		Escape,
		Space,
		Enter,
		Backspace,
		Tab,
		PageUp,
		PageDown,
		End,
		Home,
		Insert,
		Delete,
		Add,
		Subtract,
		Multiply,
		Divide,
		Pause,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		F13,
		F14,
		F15,
		Left,
		Right,
		Up,
		Down,
		Numpad0,
		Numpad1,
		Numpad2,
		Numpad3,
		Numpad4,
		Numpad5,
		Numpad6,
		Numpad7,
		Numpad8,
		Numpad9,
		A,
		Z,
		E,
		R,
		T,
		Y,
		U,
		I,
		O,
		P,
		Q,
		S,
		D,
		F,
		G,
		H,
		J,
		K,
		L,
		M,
		W,
		X,
		C,
		V,
		B,
		N,
		Num0,
		Num1,
		Num2,
		Num3,
		Num4,
		Num5,
		Num6,
		Num7,
		Num8,
		Num9,
		Leftshift,
		RightShift,
		LeftControl,
		RightControl
	};

	enum class MouseButton : std::uint8_t
	{
		Left = 1,
		Right,
		Middle
	};

	enum class MouseScroll : std::uint8_t
	{
		Vertical = 1,
		Horizontal
	};
}