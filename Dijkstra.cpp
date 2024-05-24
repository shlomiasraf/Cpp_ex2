/* ID: 207970252
    Mail: Shlomi55577@gmail.com */

#include "Dijkstra.hpp"
#include <queue>
#include <string>
#include <limits>
#include <algorithm>

std::vector<int> ariel::Dijkstra::DijkstraAlgo(Graph &graph, int source, int dest)
{
    std::vector<int> distances(graph.getNumVertices(), std::numeric_limits<int>::max()); // Distance array
    std::vector<int> pi(graph.getNumVertices(), -1); // Predecessor array
    std::queue<int>pq; // Min-heap
    std::vector<int> pathVertices;

    distances[source] = 0;
    pq.push(source);
    while (!pq.empty())
    {
        int u = pq.front();
        pq.pop();

        // If destination reached, return the distance
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
            int w = graph.getMatrix()[u][v];
            if (w != 0 && distances[u] != std::numeric_limits<int>::max() && distances[u] + w < distances[v])
            {
                distances[v] = distances[u] + w;
                pi[v] = u;
                pq.push(v);
            }
        }
    }
    return pathVertices;
}