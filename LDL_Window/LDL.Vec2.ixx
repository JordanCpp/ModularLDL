// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

export module LDL.Vec2;

export namespace LDL
{
	template<class T>
	class Vec2
	{
	public:
		Vec2()
		{
			x = 0;
			y = 0;
		}

		Vec2(T v1, T v2)
		{
			x = v1;
			y = v2;
		}

		T x;
		T y;
	};
}