#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <exception>

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
	adjacency_matrix(names vertex_names);

	void add_edge(int vertex_one, int vertex_two) override;
	void add_edge(std::string vertex_one, int vertex_two);
	void add_edge(int vertex_one, std::string vertex_two);
	void add_edge(std::string vertex_one, std::string vertex_two);

	void add_vertex() override;
	void add_vertex(std::string vertex_name);

	void remove_edge(int vertex_one, int vertex_two) override;
	void remove_edge(std::string vertex_one, int vertex_two);
	void remove_edge(int vertex_one, std::string vertex_two);
	void remove_edge(std::string vertex_one, std::string vertex_two);

	void remove_vertex(int vertex) override;
	void remove_vertex(std::string vertex);

	friend std::ostream& operator<<(
		std::ostream& out, const adjacency_matrix& graph);

};

