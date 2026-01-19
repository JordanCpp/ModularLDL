// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

import Graphics;

using namespace Graphics;

int main()
{
    auto canvasResource = CanvasNew(800, 600, "Canvas SDL");

    if (!canvasResource)
    {
        return -1;
    }

    auto& canvas = *canvasResource;

    Events::Event event;

    while (canvas->GetEvent(event))
    {
        if (event.Type == Events::Event::IsQuit)
        {
            canvas->StopEvent();
        }
    }

    return 0;
}
