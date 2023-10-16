#include"DSA_algorithms.h"
#include"DSA_data_structures.h"
#include<iostream>

void test_kmp(std::string source = "aabaabaabaab", std::string goal = "aab") {
	using namespace kmp;
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

void test_heap() {
	using namespace heap;
	int cases_number;
	std::cin >> cases_number;
	for (int i = 0; i < cases_number; ++i) {
		int operation_number;
		std::cin >> operation_number;
		Heap<int> heap([](const int& a, const int& b) {return a < b; });
		for (int j = 0; j < operation_number; ++j) {
			int operation_code;
			std::cin >> operation_code;
			if (operation_code == 1) {
				int to_insert;
				std::cin >> to_insert;
				int* ptr = new int(to_insert);
				heap.insert(ptr);
			}
			else
				std::cout << heap.pop_min() << std::endl;
		}
	}
}

int main() {
	test_heap();
}