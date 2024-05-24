/* ID: 207970252
    Mail: Shlomi55577@gmail.com */
    
#include "Graph.hpp"
#include <iostream>
#include <vector>


ariel::Graph::Graph() = default;


void ariel::Graph::loadGraph(std::vector<std::vector<int> >& graph)
{
    // Check if the graph is matrix
    int numRows = graph.size();
    if(graph.size() == 0)
    {
        throw std::invalid_argument("Invalid graph: The graph is empty.");
    }
    else
    {
        int numCols = graph[0].size();
        if (numRows != numCols)
        {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }
    this-> graph = graph;
    this->numVertices = (int)graph.size();
    this->numEdges = 0;
    this->hasNegativeEdge = false;
    this->isDirected = false;
    this->hasWeight = false;
    this->neighbors = {};
    this->neighbors.resize(numVertices);
    this->edges = std::vector<Edge>();
    for(int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if(this->graph[i][j] < 0)
            {
                this->hasNegativeEdge = true;
            }
            if(this->graph[i][j] != this->graph[j][i])
            {
                this->isDirected = true;
            }
            if(this->graph[i][j] != 0)
            {
                Edge edge;
                edge.source = i;
                edge.dest = j;
                edge.weight = graph[i][j];
                this->edges.push_back(edge);
                this->numEdges++;
                this->neighbors[i].push_back(j);
            }
            if(this->graph[i][j] != 0 && this->graph[i][j] != 1)
            {
                this->hasWeight = true;
            }
        }
    }
}
void ariel::Graph::printGraph()
{
    if(this->isDirected)
    {
        std::cout << "Graph with " << this->numVertices << " vertices and " << this->numEdges << " edges." << std::endl;
    }
    else
    {
        std::cout << "Graph with " << this->numVertices << " vertices and " << this->numEdges/2 << " edges." << std::endl;
    }
}
int ariel::Graph::getNumVertices()
{
    return this->numVertices;
}
std::vector<std::vector<int>> ariel::Graph::getNeighbors()
{
    return this->neighbors;
}
bool ariel::Graph::getIfDirected()
{
    return this->isDirected;
}
std::vector<std::vector<int> > ariel::Graph::getMatrix() 
{
    return this->graph;
}
bool ariel::Graph::getIfHasNegetiveEdge()
{
    return this->hasNegativeEdge;
}
bool ariel::Graph::getIfHasWeight()
{
    return this->hasWeight;
}
int ariel::Graph::getNumEdges()
{
    return this->numEdges;
}
// Implementation of arithmetic operators

ariel::Graph ariel::Graph::operator+(const Graph& other) const
{
    // Check if the graphs have the same size
    if (graph.size() != other.graph.size() || graph[0].size() != other.graph[0].size())
    {
        throw std::invalid_argument("Graphs must have the same size for addition.");
    }
    Graph result;
    std::vector<std::vector<int>> newGraph(graph.size(), std::vector<int>(graph[0].size(), 0));
    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            newGraph[i][j] = graph[i][j] + other.graph[i][j];
        }
    }
    result.loadGraph(newGraph);
    return result;
}

ariel::Graph& ariel::Graph::operator+=(const Graph& other)
{
    // Check if the graphs have the same size
    if (graph.size() != other.graph.size() || graph[0].size() != other.graph[0].size())
    {
        throw std::invalid_argument("Graphs must have the same size for addition.");
    }

    // Perform element-wise addition
    for (size_t i = 0; i < graph.size(); i++) {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            graph[i][j] += other.graph[i][j];
        }
    }
    return *this;
}

ariel::Graph& ariel::Graph::operator+()
{
    for (size_t i = 0; i < graph.size(); i++) {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            if(graph[i][j] < 0)
            {
                graph[i][j] = -graph[i][j];
            }
        }
    }
    return *this;
}

ariel::Graph ariel::Graph::operator-(const Graph& other) const
{
    // Check if the graphs have the same size
    if (graph.size() != other.graph.size() || graph[0].size() != other.graph[0].size())
    {
        throw std::invalid_argument("Graphs must have the same size for addition.");
    }
    Graph result;
    std::vector<std::vector<int>> newGraph(graph.size(), std::vector<int>(graph[0].size(), 0));
    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            newGraph[i][j] = graph[i][j] - other.graph[i][j];
        }
    }
    result.loadGraph(newGraph);
    return result;
}


ariel::Graph& ariel::Graph::operator-=(const Graph& other)
{
    // Check if the graphs have the same size
    if (graph.size() != other.graph.size() || graph[0].size() != other.graph[0].size())
    {
        throw std::invalid_argument("Graphs must have the same size for addition.");
    }

    // Perform element-wise addition
    for (size_t i = 0; i < graph.size(); i++) {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            graph[i][j] -= other.graph[i][j];
        }
    }
    return *this;
}

ariel::Graph& ariel::Graph::operator-()
{
    for (size_t i = 0; i < graph.size(); i++) {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            if(graph[i][j] > 0)
            {
                graph[i][j] = -graph[i][j];
            }
        }
    }
    return *this;
}
bool ariel::Graph::operator==(const Graph& other) const
{
    if (graph.size() != other.graph.size() || graph[0].size() != other.graph[0].size())
    {
        return false;
    }

    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            if (graph[i][j] != other.graph[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool ariel::Graph::operator!=(const Graph& other) const
{
    return !(*this == other);
}
bool ariel::Graph::operator>(const Graph& other) const
{
    if(*this != other)
    {
        int minVar = std::min(graph.size(),other.graph.size());
        bool contains = true;
        for (size_t i = 0; i < minVar; i++)
        {
            for (size_t j = 0; j < minVar; j++)
            {
                if (graph[i][j] != other.graph[i][j])
                {
                    contains = false;
                    break;
                }
            }
            if(!contains)
            {
                break;
            }
        }
        if(contains)
        {
            return true;
        }
        if(this->numEdges > other.numEdges)
        {
            return true;
        }
        if(this->numEdges == other.numEdges && graph.size() > other.graph.size())
        {
            return true;
        }
    }
    return false;
}

// Greater than or equal to operator
bool ariel::Graph::operator>=(const Graph& other) const
{
    return (*this > other) || (*this == other);
}

// Less than operator
bool ariel::Graph::operator<(const Graph& other) const
{
    return !(*this > other) && (*this != other);
}

// Less than or equal to operator
bool ariel::Graph::operator<=(const Graph& other) const
{
    return (*this < other) || (*this == other);
}

ariel::Graph& ariel::Graph::operator++()
{
    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            graph[i][j]++;
        }
    }
    return *this;
}

ariel::Graph& ariel::Graph::operator--()
{
    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            graph[i][j]--;
        }
    }
    return *this;
}

ariel::Graph& ariel::Graph::operator*=(int scalar)
{
    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            graph[i][j] *= scalar;
        }
    }
    return *this;
}
ariel::Graph& ariel::Graph::operator/=(int scalar)
{
    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            graph[i][j] /= scalar;
        }
    }
    return *this;
}
ariel::Graph ariel::Graph::operator*(const Graph& other) const
{
    if (graph.size() != other.graph.size() || graph[0].size() != other.graph[0].size())
    {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    Graph result;
    std::vector<std::vector<int>> newGraph(graph.size(), std::vector<int>(graph[0].size(), 0));

    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph.size(); j++)
        {
            for (size_t k = 0; k < graph.size(); k++)
            {
                if(i != j)
                {
                    newGraph[i][j] += graph[i][k] * other.graph[k][j];
                }
                else
                {
                    newGraph[i][j] = 0;
                    break;
                }
            }
        }
    }
    result.loadGraph(newGraph);
    return result;
}

namespace ariel
{
    // Definition of the friend function
    std::ostream& operator<<(std::ostream& os, Graph& g1)
    {
        os << '[';
        for (size_t i = 0; i < g1.getMatrix().size(); i++)
        {
            for (size_t j = 0; j < g1.getMatrix()[i].size(); j++)
            {
                if(j != g1.getMatrix()[i].size()-1)
                {
                    os << g1.getMatrix()[i][j] << ", ";
                }
                else
                {
                    os << g1.getMatrix()[i][j] << "]";
                }
            }
            if(i != g1.getMatrix().size()-1)
            {
                os << ", [";
            }
        }
        os << "\n";
        return os;
    }
}
