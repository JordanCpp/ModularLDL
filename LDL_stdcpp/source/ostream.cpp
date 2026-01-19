// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <ostream.hpp>
#include <system.hpp>

using namespace std;

ostream& ostream::operator<< (const string & str)
{
    write(str.c_str(), str.size());

    return *this;
}

ostream& ostream::operator<<(const char* str)
{
    write(str, strlen(str));

    return *this;
}

ostream& ostream::operator<<(char c)
{
    write(&c, 1);

    return *this;
}

ostream& ostream::operator<<(ostream& (*pf)(ostream&))
{
    return pf(*this);
}

ostream& std::endl(ostream& os)
{
    os << '\n';

    return os;
}