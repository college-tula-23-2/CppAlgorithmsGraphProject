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

	/*virtual void vertex_add() = 0;
	virtual void edge_add() = 0;*/

	virtual ~graph() {}
};

