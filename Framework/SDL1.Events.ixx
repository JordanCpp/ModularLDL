// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

#include <cstdint>

export module Events;

import SDL;

export namespace Events
{
    class Quit
    {
    public:
        std::uint8_t Type;
    };

    class Event
    {
    public:
        enum
        {
            IsQuit = 1
        };

        union
        {
            std::uint8_t Type;
            Events::Quit Quit;
        };
    };

}
