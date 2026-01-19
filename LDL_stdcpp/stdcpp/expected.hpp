// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace std
{
	template<typename E>
	class unexpect_t
	{
	public:
		explicit unexpect_t() = default;
	};

	constexpr unexpect_t<void> unexpect{};

	template<typename E>
	class unexpected
	{
		E _value;
	public:
		explicit unexpected(E e) :
			_value(e)
		{
		}

		E& value()
		{
			return _value;
		}

		const E& value() const
		{
			return _value;
		}
	};

	template<typename T, typename E>
	class expected
	{
	private:
		union
		{
			T _value;
			E _error;
		};

		bool _hasValue;

	public:
		expected(const T& val) :
			_value(val),
			_hasValue(true)
		{
		}

		expected(T&& val) :
			_value(static_cast<T&&>(val)),
			_hasValue(true)
		{
		}

		expected(unexpected<E>&& e) :
			_error(static_cast<E&&>(e.value())),
			_hasValue(false)
		{
		}

		~expected()
		{
			if (_hasValue)
			{
				_value.~T();
			}
			else
			{
				_error.~E();
			}
		}

		constexpr bool has_value() const noexcept
		{
			return _hasValue;
		}

		constexpr explicit operator bool() const noexcept
		{
			return _hasValue;
		}

		T& operator*()
		{
			return _value;
		}

		const T& operator*() const
		{
			return _value;
		}

		T* operator->()
		{
			return &_value;
		}

		E& error()
		{
			return _error;
		}

		const E& error() const
		{
			return _error;
		}

		template<typename U>
		constexpr T value_or(U&& default_value) const&
		{
			return _hasValue ? _value : static_cast<T>(default_value);
		}
	};
}