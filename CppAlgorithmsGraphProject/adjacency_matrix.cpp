#include "adjacency_matrix.h"

void adjacency_matrix::create_matrix()
{
	_matrix.resize(_vertexes);
	for (int i{}; i < _matrix.size(); i++)
		_matrix[i].resize(_vertexes, 0);
}

adjacency_matrix::adjacency_matrix()
	: adjacency_matrix(0) {}

adjacency_matrix::adjacency_matrix(int vertexes)
	: graph(vertexes, 0)
{
	this->create_matrix();
}

adjacency_matrix::adjacency_matrix(names vertex_names)
	: graph(vertex_names)
{
	this->create_matrix();
}

void adjacency_matrix::add_edge(int vertex_one, int vertex_two)
{
	if (vertex_one < 0 || vertex_one >= _vertexes
		|| vertex_two < 0 || vertex_two >= _vertexes)
		throw std::exception("index of a vertex out of range");

	_matrix[vertex_one][vertex_two] = 1;
	_matrix[vertex_two][vertex_one] = 1;

	_edges++;
}

void adjacency_matrix::add_edge(std::string vertex_one, int vertex_two)
{
	int index_one = std::ranges::find(_vertex_names, vertex_one) - _vertex_names.begin();
	this->add_edge(index_one, vertex_two);
}

void adjacency_matrix::add_edge(int vertex_one, std::string vertex_two)
{
	int index_two = std::ranges::find(_vertex_names, vertex_two) - _vertex_names.begin();
	this->add_edge(vertex_one, index_two);
}

void adjacency_matrix::add_edge(std::string vertex_one, std::string vertex_two)
{
	int index_one = std::ranges::find(_vertex_names, vertex_one) - _vertex_names.begin();
	int index_two = std::ranges::find(_vertex_names, vertex_two) - _vertex_names.begin();

	this->add_edge(index_one, index_two);
}

void adjacency_matrix::add_vertex()
{
	_vertexes++;

	_matrix.resize(_vertexes);
	for (int i{}; i < _vertexes; i++)
		_matrix[i].resize(_vertexes, 0);

	_vertex_names.resize(_vertexes, "");
}

void adjacency_matrix::add_vertex(std::string vertex_name)
{
	this->add_vertex();
	_vertex_names.back() = vertex_name;
}

void adjacency_matrix::remove_edge(int vertex_one, int vertex_two)
{
	if (vertex_one < 0 || vertex_one >= _vertexes
		|| vertex_two < 0 || vertex_two >= _vertexes)
		throw std::exception("index of a vertex out of range");

	_matrix[vertex_one][vertex_two] = 0;
	_matrix[vertex_two][vertex_one] = 0;

	_edges--;
}

void adjacency_matrix::remove_edge(std::string vertex_one, int vertex_two)
{
	int index_one = std::ranges::find(_vertex_names, vertex_one) - _vertex_names.begin();
	this->remove_edge(index_one, vertex_two);
}

void adjacency_matrix::remove_edge(int vertex_one, std::string vertex_two)
{
	int index_two = std::ranges::find(_vertex_names, vertex_two) - _vertex_names.begin();
	this->remove_edge(vertex_one, index_two);
}

void adjacency_matrix::remove_edge(std::string vertex_one, std::string vertex_two)
{
	int index_one = std::ranges::find(_vertex_names, vertex_one) - _vertex_names.begin();
	int index_two = std::ranges::find(_vertex_names, vertex_two) - _vertex_names.begin();

	this->remove_edge(index_one, index_two);
}

void adjacency_matrix::remove_vertex(int vertex)
{
	if (vertex < 0 || vertex >= _vertexes)
		throw std::exception("index of a vertex out of range");

	_matrix.erase(_matrix.begin() + vertex);
	for (int i{}; i < _vertexes - 1; i++)
		_matrix[i].erase(_matrix[i].begin() + vertex);

	_vertex_names.erase(_vertex_names.begin() + vertex);

	_vertexes--;
}

void adjacency_matrix::remove_vertex(std::string vertex)
{
	int index = std::ranges::find(_vertex_names, vertex) - _vertex_names.begin();
	this->remove_vertex(index);
}



std::ostream& operator<<(std::ostream& out, const adjacency_matrix& graph)
{

	auto longest = [](std::string s1, std::string s2) 
		{ 
			return s1.length() < s2.length(); 
		};

	int max_length = std::ranges::max(graph._vertex_names, longest).length();
	if (!max_length) max_length = 2;

	int name_index{};

	for (int row{}; row < graph._vertexes + 1; row++)
	{
		if (!row)
		{
			out << std::setw(max_length + 1) << "";
			for (int i{}; i < graph._vertex_names.size(); i++)
			{
				out << std::setw(max_length + 1);

				if (graph._vertex_names[i] != "")
					out << graph._vertex_names[i];
				else
					out << i;
			}
				
			out << "\n";
		}
		else
		{
			out << std::setw(max_length + 1);
			if (graph._vertex_names[name_index] != "")
				out << graph._vertex_names[name_index];
			else
				out << name_index;

			for (auto item : graph._matrix[name_index])
				out << std::setw(max_length + 1) << item;
			out << "\n";

			name_index++;
		}
	}
	return out;
}
