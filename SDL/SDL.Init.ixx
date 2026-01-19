// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

#include <cstdint>

export module SDL.Init;

import SDL.Types;

export
{
	const Uint32 SDL_INIT_TIMER = 0x00000001;
	const Uint32 SDL_INIT_AUDIO = 0x00000010;
	const Uint32 SDL_INIT_VIDEO = 0x00000020;
	const Uint32 SDL_INIT_CDROM = 0x00000100;
	const Uint32 SDL_INIT_JOYSTICK = 0x00000200;
	const Uint32 SDL_INIT_NOPARACHUTE = 0x00100000;
	const Uint32 SDL_INIT_EVENTTHREAD = 0x01000000;
	const Uint32 SDL_INIT_EVERYTHING = 0x0000FFFF;

	inline int(__cdecl* SDL_Init)(Uint32 flags) = nullptr;
	inline void(__cdecl* SDL_Quit)() = nullptr;
}