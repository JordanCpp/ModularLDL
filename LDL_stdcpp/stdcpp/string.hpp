// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <string.h>
#include <allocator>
#include <utility>

namespace std
{
	template <typename T, typename Allocator = std::allocator<T>>
	class basic_string
	{
	private:
		Allocator _alloc;
		size_t    _capacity;
		size_t    _size;
		T*        _data;

		constexpr void Destroy()
		{
			if (_data)
			{
				_alloc.deallocate(_data, _capacity);
			}
		}
	public:
		~basic_string()
		{
			Destroy();
		}

		constexpr basic_string() :
			_capacity(0),
			_size(0),
			_data(nullptr)
		{
		}

		constexpr basic_string(const T* source) :
			_capacity(0),
			_size(0),
			_data(nullptr)
		{
			size_t length = strlen(source);

			resize(length);

			for (size_t i = 0; i < length; i++)
			{
				_data[i] = source[i];
			}
		}

		constexpr basic_string(const basic_string& source) :
			_capacity(0), _size(0), _data(nullptr)
		{
			if (source._size > 0)
			{
				resize(source._size);

				for (size_t i = 0; i < source._size; i++)
				{
					_data[i] = source._data[i];
				}
			}
		}

		constexpr basic_string(basic_string&& other) noexcept :
			_alloc(std::move(other._alloc)),
			_capacity(other._capacity),
			_size(other._size),
			_data(other._data)
		{
			other._data = nullptr;
			other._size = 0;
			other._capacity = 0;
		}

		constexpr basic_string& operator=(const T& source)
		{
			if (&source != this)
			{
				size_t length = strlen(source);

				resize(length);

				for (size_t i = 0; i < length; i++)
				{
					_data[i] = source[i];
				}
			}

			return *this;
		}

		constexpr bool operator== (const basic_string<T>& source) const
		{
			if (_size != source.size())
			{
				return false;
			}

			if (!_data || !source.c_str())
			{
				return _size == source.size();
			}

			return (strcmp(_data, source.c_str()) == 0);
		}

		constexpr basic_string& operator=(const T* source)
		{
			size_t length = strlen(source);

			resize(length);

			for (size_t i = 0; i < length; i++)
			{
				_data[i] = source[i];
			}

			return *this;
		}

		constexpr basic_string<T>& operator+=(const basic_string<T>& source)
		{
			for (size_t i = 0; i < source.size(); i++)
			{
				push_back(source[i]);
			}

			return *this;
		}

		constexpr basic_string<T>& operator=(const basic_string<T>& source)
		{
			if (&source != this)
			{
				size_t length = source.size();

				resize(length);

				for (size_t i = 0; i < length; i++)
				{
					_data[i] = source[i];
				}
			}

			return *this;
		}

		constexpr size_t capacity() const
		{
			return _capacity;
		}

		[[nodiscard]]
		constexpr size_t size() const
		{
			return _size;
		}

		[[nodiscard]]
		constexpr const T* c_str() const
		{
			return _data ? _data : "";
		}

		constexpr T* allocate(size_t count)
		{
			return new T[count];
		}

		constexpr void reserve(size_t count)
		{
			if (count <= _capacity)
			{
				return;
			}

			size_t total = count + 1;
			T* p = _alloc.allocate(total);

			if (_data)
			{
				for (size_t i = 0; i < _size; i++)
				{
					p[i] = _data[i];
				}

				_alloc.deallocate(_data, _capacity);
			}

			_data = p;
			_capacity = total;

			if (_data && _size == 0)
			{
				_data[0] = '\0';
			}
		}

		constexpr void resize(size_t count)
		{
			if (_capacity < count)
			{
				reserve(count);
			}

			_size = count;
			_data[_size] = '\0';
		}

		constexpr void push_back(const T& element)
		{
			if (_capacity == 0)
			{
				reserve(2);
			}
			else if (_size + 1 >= _capacity)
			{
				reserve(_capacity * 2);
			}

			_data[_size] = element;
			_size++;
			_data[_size] = '\0';
		}

		constexpr const T& at(size_t index) const
		{
			return _data[index];
		}

		constexpr T& at(size_t index)
		{
			return _data[index];
		}

		constexpr const T& operator[] (size_t index) const
		{
			return _data[index];
		}

		constexpr T& operator[] (size_t index)
		{
			return _data[index];
		}
	};

	using string = basic_string<char>;
}