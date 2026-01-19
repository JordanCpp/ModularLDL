// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

import SDL;

int main()
{
	SDL_Loader::Init();

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return -1;
    }

    auto screen = SDL_SetVideoMode(800, 600, 24, SDL_SWSURFACE);

    if (!screen)
    {
        return -1;
    }

    bool running = true;

    while (running)
    {
        SDL_Event event = {};

        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
    }

    SDL_Quit();

	return 0;
}