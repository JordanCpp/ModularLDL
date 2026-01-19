// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

export module SDL.PixelFormat;

import SDL.Types;
import SDL.Color;
import SDL.Palette;

export
{
	struct SDL_PixelFormat
	{
		SDL_Palette* palette;
		Uint8  BitsPerPixel;
		Uint8  BytesPerPixel;
		Uint8  Rloss;
		Uint8  Gloss;
		Uint8  Bloss;
		Uint8  Aloss;
		Uint8  Rshift;
		Uint8  Gshift;
		Uint8  Bshift;
		Uint8  Ashift;
		Uint32 Rmask;
		Uint32 Gmask;
		Uint32 Bmask;
		Uint32 Amask;
		Uint32 colorkey;
		Uint8  alpha;
	};
}