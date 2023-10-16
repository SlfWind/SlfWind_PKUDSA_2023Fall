#ifndef DSA_DATA_STRUCTURES_H
#define DSA_DATA_STRUCTURES_H

//Author:SlfWind
//Email:xujq1442@163.com

#include <vector>
#include <memory>
#include <cassert>

namespace heap {
	template<typename T>
	class Heap {
		using CompareFunction = bool(*)(const T&, const T&);
		std::vector<T*> values;
		const CompareFunction compare;
		const T get_value(int pos) const {
			return *(values[pos]);
		}
		int child(int pos) const {
			return pos * 2 + 1;
		}
		int parent(int pos) const {
			return (pos - 1) / 2;
		}
		void swap(int lhs, int rhs) {
			int temp = *values[lhs];
			*values[lhs] = *values[rhs];
			*values[rhs] = temp;
		}
		void sift_up(int pos) {
			int siftee = pos;
			while (siftee > 0 && compare(get_value(siftee), get_value(parent(siftee)))) {
				swap(siftee, parent(siftee));
				siftee = parent(siftee);
			}
		}
		void sift_down(int pos) {
			int siftee = pos;
			int sifter = child(siftee);
			int size = values.size();
			while (sifter < size) {
				sifter += int(sifter + 1 < size && compare(get_value(sifter + 1), get_value(sifter)));
				if (compare(get_value(sifter), get_value(siftee))) {
					swap(siftee, sifter);
					siftee = sifter;
					sifter = child(siftee);
				}
				else
					break;
			}
		}
	public:
		Heap(const CompareFunction compare) :compare(compare) {};
		void insert(T* value) {
			values.push_back(value);
			sift_up(values.size() - 1);
		}
		T pop_min() {
			assert(!values.empty());
			swap(0, values.size() - 1);
			T result = *(values[values.size() - 1]);
			values.pop_back();
			sift_down(0);
			return result;
		}
		~Heap() {
			for (auto& v : values)
				delete v;
		}
	};
}

#endif
