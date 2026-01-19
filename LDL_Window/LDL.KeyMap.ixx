// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <cstdint>

export module LDL.KeyMap;

import LDL.Enums;

export namespace LDL
{
	class KeyMap
	{
	public:
		KeyMap() :
			_key(KeyboardKey::Unknown),
			_code(0)
		{
		}

		KeyMap(std::uint32_t code, KeyboardKey key) :
			_key(key),
			_code(code)
		{
		}

		std::uint32_t GetCode()
		{
			return _code;
		}

		KeyboardKey GetKey()
		{
			return _key;
		}
	private:
		KeyboardKey   _key;
		std::uint32_t _code;
	};
}