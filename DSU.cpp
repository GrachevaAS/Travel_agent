#include "DSU.h"

int DSU::Find(int value) {
	if (sets[value] == value)
		return value;
	return sets[value] = Find(sets[value]);
}

void DSU::Unite(int first, int second) {
	first = Find(first);
	second = Find(second);
	if (rand() % 2 == 0)
		sets[first] = second;
	else sets[second] = first;
}

