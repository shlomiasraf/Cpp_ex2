/* ID: 207970252
    Mail: Shlomi55577@gmail.com */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"
#include <string>

namespace ariel
{
    class Algorithms
    {
        public:
            static int isConnected(Graph&);
            static std::string shortestPath(Graph&, int, int);
            static std::string isContainsCycle(Graph&);
            static std::string isBipartite(Graph&);
            static std::string negativeCycle(Graph&);

    };
}

#endif //ALGORITHMS_HPP
