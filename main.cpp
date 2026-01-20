// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::vector<std::string> vec;

    vec.push_back("1");
    vec.push_back("2");

    for (auto i : vec)
    {
        std::cout << i << std::endl;
    }

    std::string message = "Crazy programming!";

    std::cout << message << std::endl;

    return 0;
}