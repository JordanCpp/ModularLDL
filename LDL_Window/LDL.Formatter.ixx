// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <cstdio>
#include <cstdarg>
#include <cstring>

export module LDL.Formatter;

export namespace LDL
{
	class Formatter
	{
	public:
		enum
		{
			Max = 512
		};

		Formatter()
		{
			Clear();
		}

		void Clear()
		{
			std::memset(&_buffer, 0, sizeof(_buffer));
		}

		char* Data()
		{
			return _buffer;
		}

		const char* Data() const
		{
			return _buffer;
		}

		const char* Format(const char* format, ...)
		{
			va_list args;
			va_start(args, format);
			std::vsprintf(_buffer, format, args);
			va_end(args);

			return _buffer;
		}
	private:
		char _buffer[Max];
	};
}