#pragma once
#include <string>
#include <vector>

typedef std::vector<std::string> names;

class graph
{
protected:
	int _vertexes;
	int _edges;

	names _vertex_names;
public:

	graph();
	graph(int vertexes, int edges);
	graph(names vertex_names);

	const int& vertexes();
	const int& edges();

	virtual void add_edge(int vertex_one, int vertex_two) = 0;
	virtual void add_vertex() = 0;

	virtual void remove_edge(int vertex_one, int vertex_two) = 0;
	virtual void remove_vertex(int vertex) = 0;

	virtual ~graph() {}
};

