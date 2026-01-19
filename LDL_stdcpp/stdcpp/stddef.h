// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace std
{
    using size_t    = decltype(sizeof(0));
    using ptrdiff_t = decltype((char*)0 - (char*)0);
    using nullptr_t = decltype(nullptr);
}