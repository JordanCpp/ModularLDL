// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

#include <cstdint>

export module SDL.Mod;

export
{
	typedef enum 
	{
		KMOD_NONE = 0x0000,
		KMOD_LSHIFT = 0x0001,
		KMOD_RSHIFT = 0x0002,
		KMOD_LCTRL = 0x0040,
		KMOD_RCTRL = 0x0080,
		KMOD_LALT = 0x0100,
		KMOD_RALT = 0x0200,
		KMOD_LMETA = 0x0400,
		KMOD_RMETA = 0x0800,
		KMOD_NUM = 0x1000,
		KMOD_CAPS = 0x2000,
		KMOD_MODE = 0x4000,
		KMOD_RESERVED = 0x8000
	} SDLMod;
}