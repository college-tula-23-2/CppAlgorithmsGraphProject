#include <iostream>

#include "adjacency_matrix.h"

int main()
{
    adjacency_matrix graph({"aaaaa", "bbb", "ccccccc"});

    std::cout << graph << "\n";
}
