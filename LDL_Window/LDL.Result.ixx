// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <string>

export module LDL.Result;

export namespace LDL
{
	class Result
	{
	public:
		Result() :
			_ok(true)
		{
		}

		bool Ok()
		{
			return _ok;
		}

		void Message(const std::string& message)
		{
			_message = message;
		}

		void Message(const std::string& message, const std::string& detail)
		{
			_message = message;
			_message += detail;
		}

		const std::string& Message()
		{
			return _message;
		}

		void Clear()
		{
			_ok = false;
			_message.clear();
		}
	private:
		bool        _ok;
		std::string _message;
	};
}