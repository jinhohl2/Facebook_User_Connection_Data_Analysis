#pragma once

#include <unordered_map>
#include <vector>

#include "Graph.h"

using std::unordered_map;
using std::vector;

class Traversal {
 public:
  Traversal(const Graph& graph);

  /**
   * Finds and returns the graph that consists only of the connected nodes with
   * the given starting point.
   */
  Graph findConnectedSubgraph(const string& start);

  /**
   * DFS algorithm that finds out which vertices are visited
   */
  void DFS(const string& start);

 private:
  const Graph& graph_;
  unordered_map<string, bool> visited_;
};