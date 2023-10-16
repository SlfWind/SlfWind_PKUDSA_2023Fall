#include"DSA_algorithms.h"
#include<iostream>

void test_kmp() {
	using namespace kmp;
	std::string source = "aabaabaabaab";
	std::string goal = "aab";
	int next = 0;
	int total = -1;
	while (next >= 0 && next < source.size()) {
		if (total == -1)
			std::cout << "Test_KMP begin:" << std::endl;
		else
			std::cout << "Substr " << total << ":begin at " << next << std::endl;
		++total;
		next = find_substr(source, goal, next);
		next += next >= 0;
	}
	std::cout << total << " substrs are found." << std::endl;
}

int main() {
	test_kmp();
}