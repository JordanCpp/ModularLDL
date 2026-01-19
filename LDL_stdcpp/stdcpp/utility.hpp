// Copyright 2026-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace std
{
	template <typename T>
	struct remove_reference
	{
		using type = T;
	};
	template <typename T>

	struct remove_reference<T&>
	{
		using type = T;
	};

	template <typename T>
	struct remove_reference<T&&>
	{
		using type = T;
	};

	template <typename T>
	using remove_reference_t = typename remove_reference<T>::type;


	template <typename T>
	[[nodiscard]] constexpr remove_reference_t<T>&& move(T&& t) noexcept
	{
		return static_cast<remove_reference_t<T>&&>(t);
	}

	template <typename T>
	[[nodiscard]] constexpr T&& forward(remove_reference_t<T>& t) noexcept
	{
		return static_cast<T&&>(t);
	}

	template <typename T>
	[[nodiscard]] constexpr T&& forward(remove_reference_t<T>&& t) noexcept
	{
		return static_cast<T&&>(t);
	}
}