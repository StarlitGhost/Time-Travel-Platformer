#pragma once

#include <string>
#include <iostream>
#include <sstream>

namespace FlatWorld
{
	class StringUtils
	{
	public:
		template<typename T> static inline std::string to_string(const T& v)
		{
			std::ostringstream stream;
			stream << v;
			return stream.str();
		};
	};
}
