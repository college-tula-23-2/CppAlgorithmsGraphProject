#pragma once
class graph
{
	int vertices;
	int edges;
public:

	graph();
	graph(int vertices, int edges);
	graph(const graph& other);
	graph(graph&& other);

	virtual void vertex_add() = 0;
	virtual void edge_add() = 0;

	virtual ~graph() {}
};

