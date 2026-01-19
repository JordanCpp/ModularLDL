// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

module;

#include <expected>
#include <string>
#include <memory>

export module LDL.CreateWindow;

import LDL.Vec2u;
import LDL.Result;
import LDL.IWindow;
import LDL.Context;
import LDL.WindowSoftware;

namespace LDL
{
    std::expected<std::unique_ptr<IWindow>, std::string> CreateWindow(Result& result, Context& renderContext, const Vec2u& pos, const Vec2u& size, const std::string& title, std::size_t mode)
    {
        return std::make_unique<WindowSoftware>(result, pos, size, title, mode);
    }
}