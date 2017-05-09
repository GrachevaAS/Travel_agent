#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "IGraph_dist.h"
#include "WeightedGraphEdge.h"

double ApproxWayCount(const IGraph_dist& tree, const IGraph_dist& graph) {
	std::stack<int> dfsStack;
	bool* visited = new bool[tree.VerticesCount()];
	for (int i = 0; i < tree.VerticesCount(); i++)
		visited[i] = false;
	dfsStack.push(0);
	int current_from = 0;
	std::vector<std::pair<int, int> > way;
	while (!dfsStack.empty()) {
		int current = dfsStack.top();
		way.push_back(std::make_pair(current_from, current));
		visited[current] = true;
		dfsStack.pop();
		std::vector<int> tempArr;
		tree.GetNextEdges(current, tempArr);
		for (unsigned int j = 0; j < tempArr.size(); j++) {
			if (!visited[tempArr[j]]) {
				dfsStack.push(tempArr[j]);
			}
		}		
		current_from = current;
	}
	way.push_back(std::make_pair(current_from, 0));
	double result = 0;
	for (unsigned int i = 1; i < way.size(); i++) {
		//std::cout << way[i].first << " " << way[i].second << "\n";
		result += graph.GetLength(way[i].first, way[i].second);
	}
	delete[] visited;
	return result;
}