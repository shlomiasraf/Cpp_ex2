/* ID: 207970252
    Mail: Shlomi55577@gmail.com */

#include "BellmanFord.hpp"
#include <limits>
#include <algorithm>
std::vector<int> ariel::BellmanFord::BellmanFordAlgo(Graph &graph, int source, int dest)
{
    std::vector<int> pathVertices;
    std::vector<int> distances(graph.getNumVertices(), std::numeric_limits<int>::max()); // Distance array
    std::vector<int> pi(graph.getNumVertices(), -1); // Predecessor array

    // Initialize distances
    if(graph.getNumVertices() > source)
    {
        distances[source] = 0;
    }
    // Relax edges repeatedly (n-1 times)
    for (int i = 0; i < graph.getNumVertices()-1; i++)
    {
        for (int j = 0; j < graph.getNumEdges(); j++)
        {
            int w = graph.edges[j].weight;

            if (distances[graph.edges[j].source] != std::numeric_limits<int>::max() && distances[graph.edges[j].source] + w < distances[graph.edges[j].dest])
            {
                distances[graph.edges[j].dest] = distances[graph.edges[j].source] + w;
                pi[graph.edges[j].dest] = graph.edges[j].source;
            }
        }
    }
    // Check for negative cycles
    for (int i = 0; i < graph.getNumEdges(); i++)
    {
            int w = graph.edges[i].weight;
            if (distances[graph.edges[i].source] != std::numeric_limits<int>::max() && distances[graph.edges[i].source] + w < distances[graph.edges[i].dest])
            {
                // Indicates a negative cycle
                return pathVertices;
            }
    }
    while (dest != source)
    {
        pathVertices.push_back(dest);
        dest = pi[dest];
    }
    return pathVertices;
}
std::vector<int> ariel::BellmanFord::BellmanFordToFindNegativeCycle(Graph &graph)
{
    // Create a 2D vector to represent the adjacency matrix
    std::vector<std::vector<int>> gd(graph.getNumVertices()+1, std::vector<int>(graph.getNumVertices()+1, 0));

    // Set the first row to represent edges from the new vertex to existing vertices
    for (int j = 1; j < graph.getNumVertices()+1; j++)
    {
        gd[0][j] = std::numeric_limits<int>::max();
    }

    // Copy the existing graph's adjacency matrix into gd, shifting indices by 1
    for (int i = 1; i <= graph.getNumVertices(); i++)
    {
        gd[i][0] = 0;
        for (int j = 1; j <= graph.getNumVertices(); j++)
        {
            gd[i][j] = graph.getMatrix()[i-1][j-1]; // Copy edge weights from the original graph
        }
    }
    // Load the graph from the adjacency matrix
    graph.loadGraph(gd);
    std::vector<int> pathVertices;
    std::vector<int> distances(graph.getNumVertices(), 1000); // Distance array
    std::vector<int> pi(graph.getNumVertices(), -1); // Predecessor array

    // Initialize distances
    if(graph.getNumVertices() > 0)
    {
        distances[0] = 0;
    }
    // Relax edges repeatedly (n-1 times)
    for (int i = 0; i < graph.getNumVertices()-1; i++)
    {
        for (int j = 0; j < graph.getNumEdges(); j++)
        {
            int w = graph.edges[j].weight;
            if (distances[graph.edges[j].source] != std::numeric_limits<int>::max() && distances[graph.edges[j].source] + w < distances[graph.edges[j].dest])
            {
                distances[graph.edges[j].dest] = distances[graph.edges[j].source] + w;
                pi[graph.edges[j].dest] = graph.edges[j].source;
            }
        }
    }
    // Check for negative cycles
    for (int i = 0; i < graph.getNumEdges(); i++)
    {
        int w = graph.edges[i].weight;
        if (distances[graph.edges[i].source] + w < distances[graph.edges[i].dest])
        {
            // Indicates a negative cycle
            int dest = graph.edges[i].dest;
            pi[dest] = graph.edges[i].source;
            while(!contains(pathVertices,dest-1))
            {
                pathVertices.push_back(dest-1);
                dest = pi[dest];
            }
            if(pathVertices.size() > 0)
            {
                pathVertices.push_back(dest-1);
                pathVertices = checkVerTwice(pathVertices);
                break;
            }
        }
    }
    return pathVertices;
}
std::vector<int> ariel::BellmanFord::checkVerTwice(std::vector<int> pathVertices)
{
    std::vector<int> result;
    bool foundTwice = false;

    for (int i = 0; i < pathVertices.size(); i++)
    {
        int current = pathVertices[i];
        for (int j = i + 1; j < pathVertices.size(); j++)
        {
            if (pathVertices[j] == current)
            {
                foundTwice = true;
                result.assign(pathVertices.begin() + i, pathVertices.begin() + j + 1);
                break;
            }
        }
        if (foundTwice)
        {
            break;
        }
    }
    return result;
    // If no vertex appears twice, return an empty vector
};
bool ariel::BellmanFord::contains(std::vector<int> pathVertices, int ver)
{
    for(int i = 0; i < pathVertices.size(); i++)
    {
        if(pathVertices[i] == ver)
        {
            return true;
        }
    }
    return false;
}
