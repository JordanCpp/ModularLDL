// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <Windows.h>

export module LDL.WindowError;

import LDL.Formatter;

export namespace LDL
{
    const DWORD formatMessage = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS;
    const DWORD defaultLangId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT);

	class WindowError
	{
	public:
        WindowError()
        {
            Clear();
        }

        void Clear()
        {
            _formatter.Clear();
        }

        const char* GetErrorMessage()
        {
            DWORD lastError = GetLastError();

            if (lastError == 0)
            {
                return _formatter.Format("No error");
            }

            Clear();

            DWORD size = FormatMessageA(formatMessage, NULL, lastError, defaultLangId, _formatter.Data(), (DWORD)Formatter::Max, NULL);

            if (size == 0)
            {
                _formatter.Format("Unknown error: 0x%08X", lastError);
            }

            return _formatter.Data();
        }
	private:
		Formatter _formatter;
	};
}