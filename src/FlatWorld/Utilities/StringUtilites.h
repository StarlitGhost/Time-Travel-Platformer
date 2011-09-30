// A header with some basic string functions that will probably be needed quite frequently.

#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

// 'Universal' toString, like C#'s. Converts any type with a streaming out operator into it's string representation.
template<typename T>
static inline std::string ToString(const T& v)
{
	std::ostringstream stream;
	stream << v;
	return stream.str();
}

template<>
static inline std::string ToString(const float& v)
{
	std::ostringstream stream;
	stream << std::fixed;
	stream << std::setprecision(3);
	stream << v;
	return stream.str();
}

// 'Universal' String-to-Type converter. Converts any type with a streaming in operator that accepts a string.
template<typename T>
static inline T StringToType(const std::string& text, const T& defaultVal)
{
	std::stringstream stream(text);
	T result;
	return stream >> result ? result : defaultVal;
}