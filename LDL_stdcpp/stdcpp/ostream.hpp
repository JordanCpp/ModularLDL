// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <string>

namespace std
{
    class ostream
    {
    private:

    public:
        ostream& operator<<(const std::string& str);
        ostream& operator<<(const char* str);
        ostream& operator<<(char c);
        ostream& operator<<(ostream& (*pf)(ostream&));
    };

    ostream& endl(ostream& os);
}