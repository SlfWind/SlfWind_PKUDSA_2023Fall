#include"DSA_algorithms.h"

template<int size>
void kmp::calculate_next(const std::string & str, std::array<int, size>&next) {
	int str_length = str.size();
	assert(size >= str_length);
	if (str_length == 0)
		return;
	if (str_length == 1) {
		next[0] = -1;
		return;
	}
	next[0] = -1;
	next[1] = 0;
	for (int i = 2; i < str_length; ++i) {
		int j = next[i - 1];
		while (j >= 0 && str[i - 1] != str[j])
			j = next[j];
		next[i] = j + 1;
	}
}

constexpr int array_size = 114514;

int kmp::find_substr(const std::string& source, const std::string& goal, const int begin_pos = 0) {
	const int source_length = source.size();
	const int goal_length = goal.size();
	if (source_length - begin_pos < goal_length)
		return -1;
	std::array<int, array_size> next;
	calculate_next(goal, next);
	using update_function = void(*)(int&, int&, std::array<int, array_size>&);
	update_function update[2]{ 
		[](int& i, int& j, std::array<int, array_size>& next) { j = next[j]; if (j < 0) ++i,++j; },
		[](int& i, int& j, std::array<int, array_size>& next) { ++i,++j; }
	};
	int update_condition;
	int i, j;
	for (i = begin_pos, j = 0; i < source_length && j != goal_length; update[update_condition](i, j, next))
		update_condition = int(source[i] == goal[j]);
	return j == goal_length ? (i - j) : -1;
}
