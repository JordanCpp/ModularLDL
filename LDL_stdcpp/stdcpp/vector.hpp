// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <memory>
#include <allocator>
#include <utility>

namespace std
{
    template <typename T, typename Allocator = allocator<T>>
    class vector
    {
    private:
        Allocator _alloc;
        T*        _data;
        size_t    _size;
        size_t    _capacity;

        constexpr void Destroy()
        {
            if (_data)
            {
                for (size_t i = 0; i < _size; ++i)
                {
                    _data[i].~T();
                }

                _alloc.deallocate(_data, _capacity);
            }
        }
    public:
        using value_type = T;
        using iterator = T*;

        constexpr vector() :
            _data(nullptr),
            _size(0),
            _capacity(0)
        {
        }

        ~vector()
        {
            Destroy();
        }

        vector(const vector&) = delete;
        vector& operator=(const vector&) = delete;

        constexpr vector(vector&& other) noexcept :
            _data(other._data),
            _size(other._size),
            _capacity(other._capacity)
        {
            other._data = nullptr;
            other._size = 0;
            other._capacity = 0;
        }

        constexpr void reserve(size_t new_cap)
        {
            if (new_cap <= _capacity)
            {
                return;
            }

            T* new_data = _alloc.allocate(new_cap);

            for (size_t i = 0; i < _size; ++i)
            {
                new (new_data + i) T(std::move(_data[i]));
                _data[i].~T();
            }

            if (_data)
            {
                _alloc.deallocate(_data, _capacity);
            }

            _data = new_data;
            _capacity = new_cap;
        }

        constexpr void push_back(const T& value)
        {
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            }

            new (_data + _size) T(value);
            _size++;
        }

        constexpr void push_back(T&& value)
        {
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            }

            new (_data + _size) T(std::move(value));
            _size++;
        }

        constexpr void pop_back()
        {
            if (_size > 0)
            {
                _size--;
                _data[_size].~T();
            }
        }

        constexpr size_t size() const
        {
            return _size;
        }

        constexpr size_t capacity() const
        {
            return _capacity;
        }

        constexpr bool empty() const
        {
            return _size == 0;
        }

        constexpr T& operator[](size_t index)
        {
            return _data[index];
        }

        constexpr const T& operator[](size_t index) const
        {
            return _data[index];
        }

        constexpr iterator begin()
        {
            return _data;
        }

        constexpr iterator end()
        {
            return _data + _size;
        }
    };
}