/* ID: 207970252
    Mail: Shlomi55577@gmail.com */

#include "BFS.hpp"
#include <queue>
#include <string>
std::vector<int> ariel::BFS::BFSAlgo(Graph &graph, int source, int dest)
{
    std::vector<int> pathVertices;
    std::vector<std::string> color(graph.getNumVertices(), "white"); // Initialize color array
    std::vector<int> pi(graph.getNumVertices(), -1); // Predecessor array

    color[source] = "gray";

    std::queue<int> Q;
    Q.push(source);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        if (u == dest)
        {
            while (dest != source)
            {
                pathVertices.push_back(dest);
                dest = pi[dest];
            }
        }
        std::vector<int> neighborsOfU = graph.getNeighbors()[u];
        for (int v : neighborsOfU)
        {
            if (color[v] == "white")
            {
                color[v] = "gray";
                pi[v] = u;
                Q.push(v);
            }
        }
        color[u] = "black";
    }
    return pathVertices;
}