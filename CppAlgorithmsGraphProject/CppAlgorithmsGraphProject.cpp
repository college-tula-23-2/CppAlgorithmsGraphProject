#include <iostream>

#include "adjacency_matrix.h"

int main()
{
    adjacency_matrix graph({"a", "b", "c"});
    std::cout << graph << "\n\n";

    graph.add_edge(0, 2);
    std::cout << graph << "\n\n";

    graph.add_edge("a", 1);
    std::cout << graph << "\n\n";

    try
    {
        graph.add_vertex();
        std::cout << graph << "\n\n";

        graph.add_vertex("abc");
        std::cout << graph << "\n\n";

        graph.remove_vertex("c");
        std::cout << graph << "\n\n";

        //graph.add_edge(1, "d");
    }
    catch (std::exception ex)
    {
        std::cout << ex.what() << "\n";
    }
}
