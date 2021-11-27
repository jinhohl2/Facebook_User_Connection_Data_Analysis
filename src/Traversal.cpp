#include "../include/Traversal.h"

Traversal::Traversal(const Graph& graph)
    : graph_(graph) {
  for (const auto& it : graph.getVertices()) {
    visited_[it.first] = false;
  }
}

Graph Traversal::findConnectedSubgraph(const string& start) {
  DFS(start);

  Graph subgraph;
  for (const auto& v1 : visited_) {
    if (!v1.second) continue;  // if v1 not visited

    subgraph.insertVertex(v1.first);
    for (const auto& v2 : visited_) {
      if (!v2.second) continue;  // if v2 not visited

      subgraph.insertVertex(v2.first);
      if (graph_.isAdjacent(v1.first, v2.first)) {
        subgraph.insertEdge(v1.first, v2.first);
      }
    }
  }
  return subgraph;
}

void Traversal::DFS(const string& start) {
  visited_[start] = true;

  const vector<Vertex*>& neighbours = graph_.getNeighbours(graph_.getVertices().at(start));
  for (const Vertex* neighbour : neighbours) {
    if (!visited_[neighbour->key()]) DFS(neighbour->key());
  }
}
