// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <cstdint>

export module LDL.ContextMode;

export namespace LDL
{
	enum class ContextMode : std::uint8_t
	{
		Software = 1,
		OpenGL1,
		OpenGL3,
		Max
	};
}