// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

#include <cstdint>

export module SDL.Types;

export
{
	using Sint8  = std::int8_t;
	using Uint8  = std::uint8_t;

	using Sint16 = std::int16_t;
	using Uint16 = std::uint16_t;

	using Sint32 = std::int32_t;
	using Uint32 = std::uint32_t;
}