#include <vector>
#include "CMatrixGraph_dist.h"


CMatrixGraph_dist::CMatrixGraph_dist(int vertexNum) {
	vertexCount = vertexNum;
	hasEdge.resize(vertexCount * vertexCount, false);
	Matrix = new double*[vertexCount];
	Matrix[0] = new double[vertexCount * vertexCount];
	for (int i = 1; i < vertexCount; i++) {
		Matrix[i] = Matrix[i - 1] + vertexCount;
	}
	for (int i = 0; i < vertexCount; i++) {
		for (int j = 0; j < vertexCount; j++) {
			Matrix[i][j] = 0;
		}
	}
}

CMatrixGraph_dist::CMatrixGraph_dist(const IGraph_dist& graph) : CMatrixGraph_dist(graph.VerticesCount()) {
	std::vector<std::pair<int, double> > temp;
	for (int i = 0; i < vertexCount; i++) {
		graph.GetNextEdges(i, temp);
		for (unsigned int j = 0; j < temp.size(); j++) {
			this->AddEdge(i, temp[j].first, temp[j].second);
		}
		temp.clear();
	}

}

CMatrixGraph_dist::~CMatrixGraph_dist() {
	delete[] Matrix[0];
	delete[] Matrix;
}

bool CMatrixGraph_dist::HasEdge(int from, int to) const {
	if (hasEdge[from * vertexCount + to] == true)
		return true;
	return false;
}

double CMatrixGraph_dist::GetLength(int from, int to) const {
	return Matrix[from][to];
}

int CMatrixGraph_dist::VerticesCount() const {
	return vertexCount;
}

void CMatrixGraph_dist::AddEdge(int from, int to, double dist) {
	Matrix[from][to] = dist;
	hasEdge[from * vertexCount + to] = true;
}

void CMatrixGraph_dist::GetNextEdges(int vertex, std::vector<std::pair<int, double>>& vertices) const {
	for (int i = 0; i < vertexCount; i++) {
		if (hasEdge[vertex * vertexCount + i] != false)
			vertices.push_back(std::make_pair(i, Matrix[vertex][i]));
	}
}

//void CMatrixGraph_dist::GetPrevVertices(int vertex, std::vector<std::pair<int, double>>& vertices) const {
//	for (int i = 0; i < vertexCount; i++) {
//		if (hasEdge[i * vertexCount + vertex] != false)
//			vertices.push_back(std::make_pair(i, Matrix[vertex][i]));
//	}
//}

void CMatrixGraph_dist::GetNextEdges(int vertex, std::vector<int>& vertices) const {
	for (int i = 0; i < vertexCount; i++) {
		if (hasEdge[vertex * vertexCount + i] != false)
			vertices.push_back(i);
	}
}

//void CMatrixGraph_dist::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
//	for (int i = 0; i < vertexCount; i++) {
//		if (hasEdge[i * vertexCount + vertex] != false)
//			vertices.push_back(i);
//	}
//}
