// Copyright 2025-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt) 

module;

#include <cstddef>
#include <string>

export module LDL.BaseWindow;

import LDL.Vec2u;
import LDL.WindowMode;

export namespace LDL
{
    class BaseWindow
    {
    public:
        BaseWindow(const Vec2u& pos, const Vec2u& size, const std::string& title, std::size_t mode) :
            _mode(mode),
            _pos(pos),
            _size(size),
            _title(title)
        {
        }

        bool HasMode(std::size_t mode) const
        {
            return (_mode & mode) != 0;
        }

        const Vec2u& Pos() const
        {
            return _pos;
        }

        void Pos(const Vec2u& pos)
        {
            _pos = pos;
        }

        const Vec2u& Size() const
        {
            return _size;
        }

        void Size(const Vec2u& size)
        {
            _size = size;
        }

        const std::string& Title() const
        {
            return _title;
        }

        void Title(const std::string& source)
        {
            _title = source;
        }

        bool IsFullScreen() const
        {
            return HasMode(WindowMode::FullScreen);
        }

        bool IsResized() const
        {
            return HasMode(WindowMode::Resized);
        }

        bool IsFixed() const
        {
            return HasMode(WindowMode::Fixed);
        }

        bool IsMinimized() const
        {
            return HasMode(WindowMode::Minimized);
        }

        bool IsMaximized() const
        {
            return HasMode(WindowMode::Maximized);
        }

        bool IsCentered() const
        {
            return HasMode(WindowMode::Centered);
        }
    private:
        std::size_t    _mode;
        Vec2u          _pos;
        Vec2u          _size;
        std::string    _title;
    };
}