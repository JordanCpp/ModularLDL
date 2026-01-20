// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

#include <expected>
#include <memory>
#include <string>

export module Graphics;

import SDL;
import Events;

export namespace Graphics
{
    class Canvas
    {
    public:
        Canvas(SDL_Surface* screen) :
            _running(true),
            _screen(screen)
        {
        }

        ~Canvas()
        {
            SDL_Quit();
        }

        bool GetEvent(Events::Event& dest)
        {
            if (_running)
            {
                SDL_Event event = {};

                if (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        dest.Type = Events::Event::IsQuit;
                    }
                }
            }

            return _running;
        }

        void StopEvent()
        {
            _running = false;
        }

        void Update()
        {
            SDL_Flip(_screen);
        }
    private:
        bool         _running;
        SDL_Surface* _screen;
    };

    std::expected<std::unique_ptr<Canvas>, const char*> CanvasNew(int width, int height, const std::string& title)
    {
        SDL_Loader::Init();

        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            return std::unexpected(SDL_GetError());
        }

        auto screen = SDL_SetVideoMode(width, height, 24, SDL_HWSURFACE);

        if (!screen)
        {
            SDL_Quit();
            return std::unexpected(SDL_GetError());
        }

        SDL_WM_SetCaption(title.c_str(), nullptr);

        return std::make_unique<Canvas>(screen);
    }
}
