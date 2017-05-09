#ifndef H_CMATRIXGRAPH_DIST
#define H_CMATRIXGRAPH_DIST

#include "IGraph_dist.h"

class CMatrixGraph_dist : public IGraph_dist {
public:
	explicit CMatrixGraph_dist(int vertexNum);
	CMatrixGraph_dist(const IGraph_dist& graph);
	~CMatrixGraph_dist();
	bool HasEdge(int from, int to) const;
	double GetLength(int from, int to) const;
	void AddEdge(int from, int to, double dist);
	int VerticesCount() const;
	void GetNextEdges(int vertex, std::vector<std::pair<int, double> >& vertices) const;
	// void GetPrevVertices(int vertex, std::vector<std::pair<int, double> >& vertices) const;
	void GetNextEdges(int vertex, std::vector<int>& vertices) const;
	// void GetPrevVertices(int vertex, std::vector<int>& vertices) const;
private:
	std::vector<bool> hasEdge;
	double** Matrix;
	int vertexCount;
};

#endif
