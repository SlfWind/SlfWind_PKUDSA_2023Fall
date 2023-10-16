#ifndef DSA_ALGORITHMS
#define DSA_ALGIRUTHMS

#include <string>
#include <array>
#include <cassert>

//Author:SlfWind
//Email:xujq1442@163.com

namespace kmp {
	template<int size>
	void calculate_next(const std::string& str, std::array<int, size>& next);
	int find_substr(const std::string& source, const std::string& goal, const int begin_pos);
}





#endif
