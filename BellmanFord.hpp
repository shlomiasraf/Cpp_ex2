/* ID: 207970252
    Mail: Shlomi55577@gmail.com */

#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include "Graph.hpp"



namespace ariel 
{
    class BellmanFord
    {
    public:
        static std::vector<int> BellmanFordAlgo(Graph&, int, int);
        static std::vector<int> BellmanFordToFindNegativeCycle(Graph&);
        static bool contains(std::vector<int>, int);
        static std::vector<int> checkVerTwice(std::vector<int>);

    };
}





#endif //BELLMANFORD_H
