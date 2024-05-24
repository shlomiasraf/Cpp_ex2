/* ID: 207970252
    Mail: Shlomi55577@gmail.com */
    
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <ostream> 

namespace ariel
{
    class Graph
    {
        private:
            std::vector<std::vector<int>> graph;
            std::vector<std::vector<int>> neighbors;
            int numVertices;
            int numEdges;
            bool hasNegativeEdge;
            bool isDirected;
            bool hasWeight;
        public:
            typedef struct Edge
            {
                int source;
                int dest;
                int weight;
            } Edge;
            std::vector<Edge> edges;

            Graph();
            void loadGraph(std::vector<std::vector<int>>&); // Corrected parameter type

        // Arithmetic operators
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph& operator+();
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph& operator-();
        // Comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;

        Graph& operator++();
        Graph& operator--();
        Graph& operator*=(int scalar);
        Graph& operator/=(int scalar);

        Graph operator*(const Graph& other) const;

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, Graph& g1);
        static bool contains(const Graph& other);

        void printGraph();
        std::vector<std::vector<int>>  getNeighbors();
        int  getNumVertices();
        bool getIfDirected();
        std::vector<std::vector<int>> getMatrix();
        bool getIfHasNegetiveEdge();
        bool getIfHasWeight();
        int getNumEdges();
    };
}

#endif //GRAPH_HPP
