#include <iostream>

#include "CArcGraph_dist.h"

CArcGraph_dist::CArcGraph_dist(int vertexNum) {
	vertexCount = vertexNum;
}

int CArcGraph_dist::VerticesCount() const {
	return vertexCount;
}

bool CArcGraph_dist::HasEdge(int from, int to) const {
	for (unsigned int i = 0; i < edgesList.size(); i++) {
		if (edgesList[i].from == from && edgesList[i].to == to)
		    return true;
	}
	return false;
}

double CArcGraph_dist::GetLength(int from, int to) const {
	for (unsigned int i = 0; i < edgesList.size(); i++) {
		if (edgesList[i].from == from && edgesList[i].to == to)
			return edgesList[i].dist;
	}
	return 0;
}


int CArcGraph_dist::EdgesCount() const {
	return edgesList.size();
}

void CArcGraph_dist::AddEdge(int from, int to, double dist) {
	Edge temp(from, to, dist);
	edgesList.push_back(temp);
}

void CArcGraph_dist::AddEdge(Edge edge) {
	edgesList.push_back(edge);
}

void CArcGraph_dist::GetEdges(std::vector<Edge>& edges) const {
	for (unsigned int i = 0; i < edgesList.size(); i++) {
		edges[i] = edgesList[i];
	}
}

void CArcGraph_dist::GetNextEdges(int vertex, std::vector<std::pair<int, double> >& vertices) const {
	for (unsigned int i = 0; i < edgesList.size(); i++) {
		if (edgesList[i].from == vertex)
			vertices.push_back(std::make_pair(edgesList[i].to, edgesList[i].dist));
	}
}

//void CArcGraph_dist::GetPrevVertices(int vertex, std::vector<std::pair<int, double> >& vertices) const {
//	for (unsigned int i = 0; i < edgesList.size(); i++) {
//		if (edgesList[i].to == vertex)
//			vertices.push_back(std::make_pair(edgesList[i].from, edgesList[i].dist));
//	}
//}

void CArcGraph_dist::GetNextEdges(int vertex, std::vector<int>& vertices) const {
	for (unsigned int i = 0; i < edgesList.size(); i++) {
		if (edgesList[i].from == vertex)
			vertices.push_back(edgesList[i].to);
	}
}

//void CArcGraph_dist::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
//	for (unsigned int i = 0; i < edgesList.size(); i++) {
//		if (edgesList[i].to == vertex)
//			vertices.push_back(edgesList[i].from);
//	}
//}