/* ID: 207970252
    Mail: Shlomi55577@gmail.com */

#ifndef DFS_H
#define DFS_H
#include "Graph.hpp"

namespace ariel 
{
    class DFS
    {
        public:
            static void DFSAlgo(int, std::vector<bool>&, Graph&);
            static bool DFSToFindCycle(int, int, std::vector<bool>&, Graph&, std::vector<int>&);
    };
}


#endif //DFS_H
