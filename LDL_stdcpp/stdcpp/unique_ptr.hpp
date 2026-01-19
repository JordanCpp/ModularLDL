// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <utility>

namespace std
{
	template<typename T>
	struct default_delete
	{
		void operator()(T* ptr) const
		{
			delete ptr;
		}
	};

	template<typename T>
	struct default_delete<T[]>
	{
		void operator()(T* ptr) const
		{
			delete[] ptr;
		}
	};

	template<typename T, typename Deleter = default_delete<T>>
	class unique_ptr
	{
	private:
		T* _ptr = nullptr;
		Deleter _deleter;
	public:
		constexpr unique_ptr() noexcept :
			_ptr(nullptr)
		{
		}

		constexpr unique_ptr(nullptr_t) noexcept :
			_ptr(nullptr)
		{
		}

		constexpr unique_ptr(T* ptr) noexcept :
			_ptr(ptr)
		{
		}

		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;

		unique_ptr(unique_ptr&& other) noexcept :
			_ptr(other.release())
		{
		}

		unique_ptr& operator=(unique_ptr&& other) noexcept
		{
			reset(other.release());

			return *this;
		}

		~unique_ptr()
		{
			reset();
		}

		constexpr unique_ptr& operator=(nullptr_t) noexcept
		{
			reset();

			return *this;
		}

		constexpr T* release() noexcept
		{
			T* temp = _ptr;
			_ptr = nullptr;

			return temp;
		}

		constexpr void reset(T* ptr = nullptr) noexcept
		{
			T* oldPtr = _ptr;
			_ptr = ptr;

			if (oldPtr)
			{
				_deleter(oldPtr);
			}
		}

		constexpr T* get() const noexcept
		{
			return _ptr;
		}

		explicit operator bool() const noexcept
		{
			return _ptr != nullptr;
		}

		constexpr T& operator*() const
		{
			return *_ptr;
		}

		constexpr T* operator->() const noexcept
		{
			return _ptr;
		}
	};

	template<typename T, typename... Args>
	unique_ptr<T> make_unique(Args&&... args)
	{
		return unique_ptr<T>(new T(std::forward<Args>(args)...));
	}
}