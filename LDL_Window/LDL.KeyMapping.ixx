// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <cstddef>
#include <vector>

export module LDL.KeyMapping;

import LDL.KeyMap;
import LDL.Enums;

export namespace LDL
{
	class KeyMapping
	{
	public:
		enum
		{
			DefaultCount = 256
		};

		KeyMapping()
		{
			_table.reserve(DefaultCount);
		}

		void Add(const KeyMap& keyMap)
		{
			_table.push_back(keyMap);
		}

		KeyboardKey FindKey(std::size_t key)
		{
			for (std::size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i].GetCode() == key)
				{
					return _table[i].GetKey();
				}
			}

			return KeyboardKey::Unknown;
		}
	private:
		std::vector<KeyMap> _table;
	};
}