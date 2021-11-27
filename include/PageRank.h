#pragma once

#include <cmath>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

#include "Edge.h"
#include "Graph.h"
#include "Traversal.h"
#include "Vertex.h"

using std::list;
using std::string;
using std::unordered_map;
using std::vector;
class PageRank {
 public:
  PageRank(const Graph& graph);

  void getTransposedMarkovMat();

  /**
   * Performs matrix-vector multiplication and returns the result.
   */
  static vector<double> multiplication(const vector<vector<double>>& mat,
                                       const vector<double>& vec);

  /**
   * Compares two vectors of doubles with given error.
   */
  bool vecEqual(const vector<double>& v1, const vector<double>& v2,
                double e = 0.001);

  /**
   * Returns the Vertex with the highest PageRank.
   */
  const string& getHighestRank();

 private:
  const Graph& graph_;
  vector<vector<double>> markov_mat_;
};