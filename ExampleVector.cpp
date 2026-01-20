// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

#include <vector>

const size_t count = 1024;

int main()
{
    std::vector<int> vec;

    for (size_t i = 0; i < count; i++)
    {
        vec.push_back(i);
    }

	return 0;
}