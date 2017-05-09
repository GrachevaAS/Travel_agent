#include <vector>
#include <unordered_map>
#include "CSetGraph_dist.h"

CSetGraph_dist::CSetGraph_dist(int vertexNum) {
	vertexCount = vertexNum;
	adjLists = new std::unordered_map<int, double>[vertexNum];
	adjListsReverse = new std::unordered_map<int, double>[vertexNum];
}

CSetGraph_dist::~CSetGraph_dist() {
	delete[] adjLists;
	delete[] adjListsReverse;
}

int CSetGraph_dist::VerticesCount() const {
	return vertexCount;
}

bool CSetGraph_dist::HasEdge(int from, int to) const {
	for (std::unordered_map<int, double>::const_iterator it = adjLists[from].begin();
		it != adjLists[from].end(); it++) {
		if ((*it).first == to)
			return true;
	}
	return false;
}

double CSetGraph_dist::GetLength(int from, int to) const {
	for (std::unordered_map<int, double>::const_iterator it = adjLists[from].begin();
		it != adjLists[from].end(); it++) {
		if ((*it).first == to)
			return (*it).second;
	}
	return 0;
}


void CSetGraph_dist::AddEdge(int from, int to, double dist) {
	adjLists[from][to] =  dist;
	adjListsReverse[to][from] = dist;
}

void CSetGraph_dist::GetNextEdges(int vertex, std::vector<std::pair<int, double> >& vertices) const {
	for (std::unordered_map<int, double>::const_iterator it = adjLists[vertex].begin();
		it != adjLists[vertex].end(); it++) {
		vertices.push_back(*it);
	}
}

//void CSetGraph_dist::GetPrevVertices(int vertex, std::vector<std::pair<int, double> >& vertices) const {
//	for (std::unordered_map<int, double>::const_iterator it = adjLists[vertex].begin();
//		it != adjLists[vertex].end(); it++) {
//		vertices.push_back(*it);
//	}
//}

void CSetGraph_dist::GetNextEdges(int vertex, std::vector<int>& vertices) const {
	for (std::unordered_map<int, double>::const_iterator it = adjLists[vertex].begin();
		it != adjLists[vertex].end(); it++) {
		vertices.push_back((*it).first);
	}
}

//void CSetGraph_dist::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
//	for (std::unordered_map<int, double>::const_iterator it = adjLists[vertex].begin();
//		it != adjLists[vertex].end(); it++) {
//		vertices.push_back((*it).first);
//	}
//}