// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

export module SDL.Palette;

import SDL.Color;

export
{
	struct SDL_Palette
	{
		int        ncolors;
		SDL_Color* colors;
	};
}