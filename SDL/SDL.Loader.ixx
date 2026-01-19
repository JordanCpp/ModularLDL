// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

export module SDL.Loader;

import LDL.WinAPI;
import SDL.Init;
import SDL.Error;
import SDL.Events;
import SDL.Surface;

export
{
	class SDL_Loader
	{
	public:
		static void Init()
		{
			_load = LoadLibraryA("SDL.dll");

			if (_load)
			{
				Bind(SDL_Init, "SDL_Init");
				Bind(SDL_Quit, "SDL_Quit");
				Bind(SDL_SetVideoMode, "SDL_SetVideoMode");
				Bind(SDL_PollEvent, "SDL_PollEvent");
				Bind(SDL_GetError, "SDL_GetError");
				Bind(SDL_WM_SetCaption, "SDL_WM_SetCaption");
			}
		}

		~SDL_Loader()
		{
			if (_load)
			{
				FreeLibrary(_load);
			}
		}
	private:
		template<typename T>
		static void Bind(T& funcPtr, const char* name)
		{
			funcPtr = reinterpret_cast<T>(GetProcAddress(_load, name));
		}

		inline static HMODULE _load = nullptr;
	};
}