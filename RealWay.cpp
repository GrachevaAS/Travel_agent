#include <algorithm>
#include "IGraph_dist.h"
#include "CArcGraph_dist.h"
#include "CMatrixGraph_dist.h"
#include "WeightedGraphEdge.h"

double countEdgesLength(const IGraph_dist& graph) {
	double result = 0;
	for (int i = 0; i < graph.VerticesCount(); i++)
		for (int j = 0; j < graph.VerticesCount(); j++)
			result += graph.GetLength(i, j);
	// std::cout << "ALL: " << result;
	return result + 1;
}

double findShortestWay(int start, const CMatrixGraph_dist& Mgraph, std::vector<bool> toVisit) {
	static double globalMax = countEdgesLength(Mgraph);
	double minimum = globalMax;
	bool flag = false;
	int count = 0;
	for (unsigned int i = 0; i < toVisit.size(); i++) {
		if (!toVisit[i] && Mgraph.HasEdge(start, i)) {
			flag = true;
			toVisit[i] = true;
			minimum = std::min(findShortestWay(i, Mgraph, toVisit) + Mgraph.GetLength(start,i), minimum);
			toVisit[i] = false;
		}
		if (toVisit[i])
			count++;
	}
	if (count == 2)
		std::cout << start << "\n";
	if (flag) {
		return minimum;
	}
	if (Mgraph.HasEdge(start, 0))
	    return Mgraph.GetLength(start, 0);
	return globalMax;
}

double RealWay(const IGraph_dist& graph) {
	std::vector<bool> toVisit(graph.VerticesCount(), false);
	toVisit[0] = true;
	CMatrixGraph_dist Mgraph(graph);
	return findShortestWay(0, Mgraph, toVisit);
}