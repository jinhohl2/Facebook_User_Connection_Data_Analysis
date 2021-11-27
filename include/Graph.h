#pragma once

#include <cmath>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

#include "Edge.h"
#include "Vertex.h"

using std::list;
using std::string;
using std::unordered_map;
using std::vector;

class Graph {
 public:
  const vector<vector<Edge*>>& getAdjMatrix() const { return adj_matrix_; }
  const unordered_map<string, Vertex>& getVertices() const { return vertices_; }

  size_t size() const { return vertices_.size(); }
  bool contains(const string& key) const {
    return vertices_.find(key) != vertices_.end();
  }

  /**
   * Finds the key of the vertex at "idx" in the adjacency matrix. Returns empty
   * string if not found.
   */
  const string& findKeyByIdx(int idx) const;

  /**
   * Reads the given file and construct an undirected, unweighted graph.
   */
  void readFromFile(const string& file_name);

  /**
   * Inserts a vertex. If the vertex already exists, do nothing
   */
  void insertVertex(const string& key);

  /**
   * Inserts edge between two vertices. If the edge between two vertices already
   * exists or self loop is added, do nothing
   */
  void insertEdge(const string& key1, const string& key2);

  /**
   * Returns true only if the two vertices are connected
   */
  bool isAdjacent(const string& key1, const string& key2) const;

  /**
   * Returns neighbours of the vertex
   */
  vector<Vertex*> getNeighbours(const Vertex& key) const;

  /**
   * Prints all vertices in the shortest path from src to dest
   */
  void printShortestPath(const string& src, const string& dest);

  /**
   * prints all vertices
   */
  void printAllNodes() const;

  /**
   * Returns the shortest path from src to dest found by using Dijkstra's
   * algorithm
   */
  vector<Vertex> findShortestPath(const string& src, const string& dest);
 private:

  // key: vertex key
  // value: vertex object
  unordered_map<string, Vertex> vertices_;
  vector<vector<Edge*>> adj_matrix_;
};
