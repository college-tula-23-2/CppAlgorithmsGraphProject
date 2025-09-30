#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>

#include "graph.h"

typedef std::vector<std::vector<int>> matrix;

class adjacency_matrix : public graph
{
	void create_matrix();
protected:
	matrix _matrix;

public:
	adjacency_matrix();
	adjacency_matrix(int vertexes);
	adjacency_matrix(std::vector<std::string> vertex_names);

	friend std::ostream& operator<<(
		std::ostream& out, const adjacency_matrix& graph);

};

