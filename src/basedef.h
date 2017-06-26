#pragma once
#include <string>
#include <string_view>
namespace JSON{
	using uint32 = std::uint32_t;
	using string = std::wstring;
	using string_view = std::wstring_view;
	using jchar = wchar_t;
	using NumberType = std::int64_t;
}
