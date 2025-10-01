#include "graph.h"

graph::graph() : graph(0, 0) {}

graph::graph(int vertexes, int edges)
	: _vertexes{ vertexes }, _edges{ edges }
{
	_vertex_names.resize(_vertexes, "");
}

graph::graph(names vertex_names)
	: _vertexes{ (int)vertex_names.size() }, _edges{}
{
	for (auto name : vertex_names)
		_vertex_names.push_back(name);
}

const int& graph::vertexes() { return _vertexes; }

const int& graph::edges() { return _edges; }
