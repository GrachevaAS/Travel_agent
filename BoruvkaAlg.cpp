//#ifdef DEBUG
//#include <iostream>
//#endif

#include <iostream>
#include <vector>
#include <assert.h>
#include <climits>

#include "CArcGraph_dist.h"
#include "CSetGraph_dist.h"
#include "WeightedGraphEdge.h"
#include "DSU.h"

void boruvka(const CArcGraph_dist& graph, IGraph_dist& tree) {
	const int vertices = graph.VerticesCount();
	int treeSize = 0;
	long long result = 0;
	int INF = INT_MAX;
	Edge* compMinEdges = new Edge[vertices];
	std::vector<Edge> edges(graph.EdgesCount());
	graph.GetEdges(edges);
	DSU components(vertices);
	while (treeSize < vertices - 1) {
		for (int i = 0; i < vertices; i++) {
			compMinEdges[i].dist = INF;
		}
		for (unsigned int i = 0; i < edges.size(); i++) {
			if (components.Find(edges[i].from) != components.Find(edges[i].to)) {
				if (edges[i] < compMinEdges[components.Find(edges[i].from)]) {
					compMinEdges[components.Find(edges[i].from)] = edges[i];
				}
				if (edges[i] < compMinEdges[components.Find(edges[i].to)])
					compMinEdges[components.Find(edges[i].to)] = edges[i];
			}
		}
		bool flag = false;
		for (int i = 0; i < vertices; i++) {
			if (compMinEdges[i].dist < INF && !tree.HasEdge(compMinEdges[i].from, compMinEdges[i].to)) {
				if (!tree.HasEdge(compMinEdges[i].from, compMinEdges[i].to)) {
					tree.AddEdge(compMinEdges[i].from, compMinEdges[i].to, compMinEdges[i].dist);
					tree.AddEdge(compMinEdges[i].to, compMinEdges[i].from, compMinEdges[i].dist);
					components.Unite(compMinEdges[i].from, compMinEdges[i].to);

					treeSize++;
					flag = true;
				}
			}
		}
		if (!flag)
			break;

	}
	delete[] compMinEdges;
}