#include <iostream>
#include <fstream>
#include <ios>
#include <cstdlib>
#include <ctime>
#include <math.h>

#include "CArcGraph_dist.h"
#include "CSetGraph_dist.h"

void boruvka(const CArcGraph_dist& graph, IGraph_dist& tree);
void normalDistribution(int count, std::vector<std::pair<double, double> >& points);

double dist(std::pair<double, double> from, std::pair<double, double> to) {
	return sqrt(pow(from.first - to.first, 2) + pow(from.second - to.second, 2));
}

void CreatePlaneGraph(std::vector<std::pair<double, double> >& points, IGraph_dist& graph) {
	for (unsigned int i = 0; i < points.size(); i++) {
		// std::cout << points[i].first << " " << points[i].second << "\n";
		for (unsigned int j = 0; j < points.size(); j++) {
			if (i != j) {
				graph.AddEdge(i, j, dist(points[i], points[j]));
				graph.AddEdge(j, i, dist(points[i], points[j]));
				// std::cout << i << " " << j << " " << dist(points[i], points[j]) << "\n";
			}
		}
	}
}

void generateGraph(IGraph_dist& graph) {
	std::vector<std::pair<double, double> > points;
	normalDistribution(graph.VerticesCount(), points);
	CreatePlaneGraph(points, graph);
}

double ApproxWayCount(const IGraph_dist& tree, const IGraph_dist& graph);
double RealWay(const IGraph_dist& graph);

//void IGraph_dist::PrintGraph() const {
//	for (int i = 0; i < VerticesCount(); i++) {
//		std::cout << i << ": ";
//		std::vector<int> next;
//		GetNextVertices(i, next);
//		for (unsigned int j = 0; j < next.size(); j++)
//			std::cout << next[j] << " ";
//		std::cout << "\n";
//	}
//}

void analyseResults(const double (&res)[7][5]) {
	std::ofstream fout;
	fout.open("answer.out", std::ios_base::app);
	const int runs = 5;
	double average_res[7];
	double dispersion[7];
	for (int i = 0; i < 7; i++) {
		double average = 0;
		double disp = 0;
		for (int j = 0; j < runs; j++) {
			average += res[i][j];
		}
		average_res[i] = (average /= runs);
		for (int j = 0; j < runs; j++) {
			disp += pow(res[i][j] - average, 2);
		}
		dispersion[i] = sqrt(disp / (runs - 1));
	}
	for (int i = 0; i < 7; i++) {
		fout << average_res[i] << "\t" << dispersion[i] << "\n";
	}
	fout.close();
}

int main() {
	std::ofstream fout;
	fout.open("answer.out", std::ios_base::app);
	std::srand(time(NULL));
	const int runs = 5;
	double res [7][runs];
	for (int count = 4; count < 11; count++) {
		for (int i = 0; i < runs; i++) {
			CArcGraph_dist graph(count);
			generateGraph(graph);
			CSetGraph_dist tree(count); // indirected graph
			boruvka(graph, tree);
			// tree.PrintGraph();
			double approx_value = ApproxWayCount(tree, graph);
			double real_value = RealWay(graph);
			res[count - 4][i] = real_value / approx_value;
			// fout << "answer: " << count << "\t" << approx_value << "\t" << real_value << "\n";
		}
	}
	fout.close();
	analyseResults(res);
	return 0;
}
