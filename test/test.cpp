#include <iostream>

#include "../catch/catch.hpp"
#include "../include/Graph.h"
#include "../include/PageRank.h"
#include "../include/Traversal.h"
using namespace std;

TEST_CASE("test isAdjacent") {
  Graph small_graph;
  Graph large_graph;
  small_graph.readFromFile("test/small_graph.txt");
  large_graph.readFromFile("test/large_graph.txt");

  SECTION("test isAdjacent true small graph") {
    REQUIRE(small_graph.isAdjacent("0", "1"));
    REQUIRE(small_graph.isAdjacent("0", "2"));
    REQUIRE(small_graph.isAdjacent("3", "4"));
  }
  SECTION("test isAdjacent false small graph") {
    REQUIRE_FALSE(small_graph.isAdjacent("0", "3"));
    REQUIRE_FALSE(small_graph.isAdjacent("0", "4"));
    REQUIRE_FALSE(small_graph.isAdjacent("0", "10"));
  }
  SECTION("test isAdjacent true large graph") {
    REQUIRE(large_graph.isAdjacent("0", "17"));
    REQUIRE(large_graph.isAdjacent("6", "8"));
    REQUIRE(large_graph.isAdjacent("9", "17"));
  }
  SECTION("test isAdjacent false large graph") {
    REQUIRE_FALSE(large_graph.isAdjacent("8", "17"));
    REQUIRE_FALSE(large_graph.isAdjacent("3", "17"));
    REQUIRE_FALSE(large_graph.isAdjacent("5", "11"));
  }
}

TEST_CASE("Test DFS traversal that finds correct subgraph") {
  Graph small_graph;
  Graph large_graph;
  small_graph.readFromFile("test/small_graph.txt");
  large_graph.readFromFile("test/large_graph.txt");

  Traversal small_t(small_graph);
  Traversal large_t(large_graph);
  SECTION("DFS small graph") {
    Graph sub_graph = small_t.findConnectedSubgraph("0");
    REQUIRE(small_graph.size() == 8);
    REQUIRE(sub_graph.size() == 4);
  }
  SECTION("DFS large graph") {
    Graph sub_graph = large_t.findConnectedSubgraph("0");
    REQUIRE(large_graph.size() == 20);
    REQUIRE(sub_graph.size() == 20);
  }
}

TEST_CASE("Test PageRank finds correct highest ranker") {
  Graph small_graph;
  Graph large_graph;
  small_graph.readFromFile("test/small_graph.txt");
  large_graph.readFromFile("test/large_graph.txt");

  Traversal t1(small_graph);
  Traversal t2(large_graph);

  Graph sub_small = t1.findConnectedSubgraph("3");
  Graph sub_large = t2.findConnectedSubgraph("0");

  PageRank small_pr(sub_small);
  PageRank large_pr(sub_large);

  SECTION("small graph") {
    small_pr.getTransposedMarkovMat();
    string highest_rank = small_pr.getHighestRank();
    REQUIRE(highest_rank == "4");
  }
  SECTION("large graph") {
    large_pr.getTransposedMarkovMat();
    string highest_rank = large_pr.getHighestRank();
    REQUIRE(highest_rank == "1");
  }
}

TEST_CASE("Test Dijkstra's algorithm finds correct shortest path") {
  Graph small_graph;
  Graph large_graph;
  small_graph.readFromFile("test/small_graph.txt");
  large_graph.readFromFile("test/large_graph.txt");

  SECTION("small graph") {
    vector<Vertex> path = small_graph.findShortestPath("0", "5");
    REQUIRE(path[0] == Vertex("0"));
    REQUIRE(path[1] == Vertex("2"));
    REQUIRE(path[2] == Vertex("5"));
  }
  SECTION("large graph") {
    vector<Vertex> path = large_graph.findShortestPath("0", "19");
    REQUIRE(path[0] == Vertex("0"));
    REQUIRE(path[1] == Vertex("17"));
    REQUIRE(path[2] == Vertex("15"));
    REQUIRE(path[3] == Vertex("19"));
  }
}