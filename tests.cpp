/* ID: 207970252
    Mail: Shlomi55577@gmail.com */
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <sstream>
#include <iostream>

TEST_CASE("Test graph +")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 + g2;

    std::ostringstream oss;
    oss << g3;
    CHECK(oss.str() == "[0, 2, 1], [2, 0, 3], [1, 3, 0]\n");
}
TEST_CASE("Test graph +=")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> weightedGraph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 4, 0}
    };
    g1.loadGraph(weightedGraph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph2);

    g1 += g2;

    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 2, 1], [2, 0, 3], [1, 6, 0]\n");
}
TEST_CASE("Test graph unary+")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, -2},
        {1, 0, 1},
        {-3, 1, 0}
    };
    g1.loadGraph(graph);
    +g1;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 1, 2], [1, 0, 1], [3, 1, 0]\n");
}
TEST_CASE("Test graph -")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 - g2;

    std::ostringstream oss;
    oss << g3;
    CHECK(oss.str() == "[0, 0, -1], [0, 0, -1], [-1, -1, 0]\n");
}
TEST_CASE("Test graph -=")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> weightedGraph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 4, 0}
    };
    g1.loadGraph(weightedGraph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph2);

    g1 -= g2;

    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 0, -1], [0, 0, -1], [-1, 2, 0]\n");
}
TEST_CASE("Test graph unary-")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, -2},
        {1, 0, 1},
        {-3, 1, 0}
    };
    g1.loadGraph(graph);
    -g1;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, -1, -2], [-1, 0, -1], [-3, -1, 0]\n");
}
TEST_CASE("Test graph >")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0,3},
        {1, 0, 1,4},
        {0, 1, 0,5},
        {4, 6, 8,9}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g2.loadGraph(graph2);
    CHECK(g1 > g2);
}
TEST_CASE("Test graph >=")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0,3},
        {1, 0, 0,0},
        {0, 0, 0,0},
        {0, 0, 0,0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 4, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g2.loadGraph(graph2);
    CHECK(g1 <= g2);
}
TEST_CASE("Test graph <")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 0},
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g2.loadGraph(graph2);
    CHECK((g1 < g2));
}
TEST_CASE("Test graph <=")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0},
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g2.loadGraph(graph2);
    CHECK((g1 <= g2));
}
TEST_CASE("Test graph ==")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0},
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g2.loadGraph(graph2);
    CHECK((g1 == g2));
}
TEST_CASE("Test graph !=")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 21, 0},
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g2.loadGraph(graph2);
    CHECK((g1 != g2));
}
TEST_CASE("Test graph ++")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 21, 0},
    };
    g1.loadGraph(graph1);
    ++g1;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[1, 2, 1], [2, 1, 2], [1, 22, 1]\n");
}
TEST_CASE("Test graph --")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 21, 0},
    };
    g1.loadGraph(graph1);
    --g1;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[-1, 0, -1], [0, -1, 0], [-1, 20, -1]\n");
}
TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    std::ostringstream oss;
    oss << g4;
    CHECK(oss.str() == "[0, 0, 2], [1, 0, 1], [1, 0, 0]\n");
}
TEST_CASE("Test graph multiplication with scalar")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    g1 *= 4;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 4, 0], [4, 0, 4], [0, 4, 0]\n");
}
TEST_CASE("Test graph division with scalar")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 8, 0},
        {8, 0, 8},
        {0, 8, 0}};
    g1.loadGraph(graph);
    g1 /= 4;
    std::ostringstream oss;
    oss << g1;
    CHECK(oss.str() == "[0, 2, 0], [2, 0, 2], [0, 2, 0]\n");
}
TEST_CASE("Invalid operations") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {4, 2 ,3, 6}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g1 * g2);
}
TEST_CASE("Invalid operations2")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    ariel::Graph g5;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
}
TEST_CASE("Invalid operations3")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    ariel::Graph g6;
    std::vector<std::vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}