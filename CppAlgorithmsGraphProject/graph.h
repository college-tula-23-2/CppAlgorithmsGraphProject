#pragma once
#include <string>
#include <vector>

class graph
{
protected:
	int _vertexes;
	int _edges;

	std::vector<std::string> _vertex_names;
public:

	graph();
	graph(int vertexes, int edges);
	graph(std::vector<std::string> vertex_names);

	const int& vertexes();
	const int& edges();

	/*virtual void vertex_add() = 0;
	virtual void edge_add() = 0;*/

	virtual ~graph() {}
};

