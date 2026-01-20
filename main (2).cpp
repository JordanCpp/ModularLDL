// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

import LDL.Window;

using namespace LDL;

int main()
{
	Result result;
	Context context;

	auto windowResult = CreateWindow(result, context, Vec2u(0, 0), Vec2u(800, 600), "LDL Window!", WindowMode::Fixed);

	if (!windowResult)
	{
		return -1;
	}

	Event event;

	while (windowResult->get()->Running())
	{
		while (windowResult->get()->GetEvent(event))
		{
			if ((event.Type == IsQuit) || (event.IsKeyPressed(KeyboardKey::Escape)))
			{
				windowResult->get()->StopEvent();
			}
		}
	}

	return 0;
}