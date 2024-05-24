/* ID: 207970252
    Mail: Shlomi55577@gmail.com */

#include "Algorithms.hpp"
#include <queue>
#include <string>

#include "BellmanFord.hpp"
#include "BFS.hpp"
#include "DFS.hpp"
#include "Dijkstra.hpp"


int ariel::Algorithms::isConnected(Graph &graph)
{
    int numVertices = graph.getNumVertices();

    // Initialize visited array
    std::vector<bool> visited(numVertices, false);
    if(!graph.getIfDirected())
    {
        if(numVertices > 0)
        {
            DFS::DFSAlgo(0,visited,graph);
            for (int v = 1; v < numVertices; v++)
            {
                if (!visited[v])
                {
                    return 0;
                }
            }
            return 1;
        }
    }
    else
    {
        // Perform DFS traversal starting from each vertex
        for (int v = 0; v < numVertices; v++)
        {
            DFS::DFSAlgo(v,visited,graph);
            for (int j = 0; j < numVertices; j++)
            {
                if (!visited[j])
                {
                    return 0;
                }
                visited[j] = false;
            }
        }
        return 1;
    }
    return 0;
}
std::string ariel::Algorithms::isBipartite(Graph &graph) {
    int numVertices = graph.getNumVertices();
    int colorArr[numVertices];

    // Initialize color array
    for (int i = 0; i < numVertices; i++)
    {
        colorArr[i] = -1;
    }

    // Assign first color to source
    colorArr[0] = 1;

    // Create a queue for BFS traversal
    std::queue<int> q;
    q.push(0);

    // BFS traversal
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // Check for self-loop
        if (graph.getMatrix()[u][u] == 1)
        {
            return "0"; // Not bipartite
        }

        // Explore neighbors
        for (int v = 0; v < numVertices; v++)
        {
            // If edge exists and neighbor is uncolored
            if (graph.getMatrix()[u][v] != 0 && colorArr[v] == -1)
            {
                // Assign alternate color to neighbor
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            // If edge exists and neighbor has same color as u
            else if (graph.getMatrix()[u][v] != 0 && colorArr[v] == colorArr[u])
            {
                return "0"; // Not bipartite
            }
        }
    }
    std::string groupA = "The graph is bipartite: A={";
    std::string groupB = "B={";
    for(int v = 0; v < numVertices; v++)
    {
        if(colorArr[v] == 1)
        {
            groupA += std::to_string(v) + ", ";
        }
        else
        {
            groupB += std::to_string(v) + ", ";
        }
    }
    groupA.replace(groupA.rfind(","), 2, "}");
    groupA += ", ";
    groupB.replace(groupB.rfind(","), 2, "}");
    return groupA + groupB; // Bipartite
}
std::string ariel::Algorithms::shortestPath(Graph &graph, int source, int dest)
{
    std::vector<int> pathVertices;
    if(!graph.getIfHasWeight())
    {
        pathVertices = BFS::BFSAlgo(graph,source,dest);
    }
    else if(!graph.getIfHasNegetiveEdge())
    {
        pathVertices = Dijkstra::DijkstraAlgo(graph,source,dest);
    }
    else
    {
        pathVertices = BellmanFord::BellmanFordAlgo(graph,source,dest);
    }
    if(pathVertices.size() > 0)
    {
        std::string path = std::to_string(source) + "->";
        for(int i = pathVertices.size()-1; i >= 0; i--)
        {
            path += std::to_string(pathVertices[i]);
            if(i > 0)
            {
                path += "->";
            }
        }
        return path;
    }
    return "-1";
}
std::string ariel::Algorithms::isContainsCycle(Graph &graph)
{
    std::vector<bool> visited(graph.getNumVertices(), false);
    std::vector<int> pathVertices;
    for (int i = 0; i < graph.getNumVertices(); ++i)
    {
        if (!visited[i]) {
            if (DFS::DFSToFindCycle(i, -1, visited, graph, pathVertices))
            {
                std::string path = "The cycle is: ";
                for (int j = 0; j < pathVertices.size(); j++)
                {
                    path += std::to_string(pathVertices[j]);
                    if (j < pathVertices.size() - 1)
                    {
                        path += "->";
                    }
                }
                return path;
            }
        }
    }
    return "0";
}
std::string ariel::Algorithms::negativeCycle(Graph &graph)
{
    if(graph.getIfHasNegetiveEdge() && graph.getIfDirected())
    {
        std::vector<int> pathVertices = BellmanFord::BellmanFordToFindNegativeCycle(graph);
        if(pathVertices.size() > 0)
        {
            std::string path = "The negative cycle is: ";
            for (int j = pathVertices.size()-1; j >= 0; j--)
            {
                path += std::to_string(pathVertices[j]);
                if (j > 0)
                {
                    path += "->";
                }
            }
            return path;
        }
    }
    return "Does not contain a negative cycle.";

}

