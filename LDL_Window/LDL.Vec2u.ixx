// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <cstdint>

export module LDL.Vec2u;

import LDL.Vec2;

export namespace LDL
{
	using Vec2u = Vec2<std::uint32_t>;
}