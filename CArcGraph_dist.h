#ifndef H_CARCGRAPH_DIST
#define H_CARCGRAPH_DIST

#include <vector>
#include "IGraph_dist.h"
#include "WeightedGraphEdge.h"

class CArcGraph_dist : public IGraph_dist {
public:
	explicit CArcGraph_dist(int vertexNum);
	~CArcGraph_dist() {}
	int VerticesCount() const;
	int EdgesCount() const;
	bool HasEdge(int from, int to) const;
	double GetLength(int from, int to) const;
	void AddEdge(int from, int to, double dist);
	void AddEdge(Edge edge);
	void GetNextEdges(int vertex, std::vector<std::pair<int, double> >& vertices) const;
	// void GetPrevVertices(int vertex, std::vector<std::pair<int, double> >& vertices) const;
	void GetNextEdges(int vertex, std::vector<int >& vertices) const;
	// void GetPrevVertices(int vertex, std::vector<int >& vertices) const;
	void GetEdges(std::vector<Edge>& edges) const;
private:
	std::vector<Edge> edgesList;
	int vertexCount;
};

#endif