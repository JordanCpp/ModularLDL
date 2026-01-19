// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

export module LDL.WindowMode;

export namespace LDL
{
	class WindowMode
	{
	public:
		enum
		{
			FullScreen = 1 << 1,
			Resized    = 1 << 2,
			Fixed      = 1 << 3,
			Minimized  = 1 << 4,
			Maximized  = 1 << 5,
			Centered   = 1 << 6
		};
	};
}