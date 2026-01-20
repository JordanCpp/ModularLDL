// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

#include <string>
#include <iostream>

int main()
{
	std::string s1 = "Hello ";
	s1 += "World!";

	std::cout << s1 << std::endl;

	return 0;
}