#ifndef H_CSETGRAPH_DIST
#define H_CSETGRAPH_DIST

#include "IGraph_dist.h"
#include <unordered_map>

class CSetGraph_dist : public IGraph_dist {
public:
	explicit CSetGraph_dist(int vertexNum);
	~CSetGraph_dist();
	int VerticesCount() const;
	bool HasEdge(int from, int to) const;
	double GetLength(int from, int to) const;
	void AddEdge(int from, int to, double dist);
	void GetNextEdges(int vertex, std::vector<std::pair<int, double> >& vertices) const;
	// void GetPrevVertices(int vertex, std::vector<std::pair<int, double> >& vertices) const;
	void GetNextEdges(int vertex, std::vector<int >& vertices) const;
	// void GetPrevVertices(int vertex, std::vector<int >& vertices) const;
private:
	std::unordered_map<int, double>* adjLists;
	std::unordered_map<int, double>* adjListsReverse;
	int vertexCount;
};

#endif