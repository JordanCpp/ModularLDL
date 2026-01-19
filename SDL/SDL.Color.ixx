// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

export module SDL.Color;

import SDL.Types;

export
{
	struct SDL_Color
	{
		Uint8 r;
		Uint8 g;
		Uint8 b;
		Uint8 unused;
	};
}