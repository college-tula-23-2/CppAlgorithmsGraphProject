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
