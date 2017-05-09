#ifndef H_IGRAPH_DIST
#define H_IGRAPH_DIST

#include <iostream>
#include <vector>

class IGraph_dist {
public:
	IGraph_dist() {}
	virtual ~IGraph_dist() {}
	virtual bool HasEdge(int from, int to) const = 0;
	virtual double GetLength(int from, int to) const = 0;
	virtual void AddEdge(int from, int to, double dist) = 0;
	virtual int VerticesCount() const = 0;
	virtual void GetNextEdges(int vertex, std::vector<std::pair<int, double> >& vertices) const = 0;
	// virtual void GetPrevVertices(int vertex, std::vector<std::pair<int, double> >& vertices) const = 0;
	virtual void GetNextEdges(int vertex, std::vector<int >& vertices) const = 0;
	// virtual void GetPrevVertices(int vertex, std::vector<int >& vertices) const = 0;
	// virtual void PrintGraph() const;
};

#endif