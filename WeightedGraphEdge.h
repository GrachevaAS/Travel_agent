#ifndef H_ORGRAPHEDGE
#define H_ORGRAPHEDGE

struct Edge {
	Edge(int begin = 0, int end = 0, double distance = 0) : from(begin), to(end), dist(distance) {}
	Edge(const Edge& another) : from(another.from), to(another.to), dist(another.dist) {}
	~Edge() {}
	int from;
	int to;
	double dist;
	void operator= (const Edge& another) {
		from = another.from;
		to = another.to;
		dist = another.dist;
	}
	bool operator< (const Edge& another) {
		return (dist < another.dist || (dist == another.dist && from < another.from));
	}
};

#endif