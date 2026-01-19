// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

export module LDL.Context;

import LDL.ContextMode;

export namespace LDL
{
	class Context
	{
	public:
		Context(ContextMode mode = ContextMode::Software) :
			_mode(mode)
		{
		}

		~Context()
		{
		}

		ContextMode Mode()
		{
			return _mode;
		}
	private:
		ContextMode _mode;
	};
}