#ifndef H_DSU
#define H_DSU

#include <vector>

class DSU {
public:
	DSU(int count) : sets(count) {
		for (int i = 0; i < count; i++)
			sets[i] = i;
	}
	int Find(int value);
	void Unite(int first, int second);
private:
	std::vector<int> sets;
};

#endif