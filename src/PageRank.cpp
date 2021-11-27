#include "../include/PageRank.h"

#include <numeric>
using std::accumulate;

PageRank::PageRank(const Graph& graph) : graph_(graph) {}

void PageRank::getTransposedMarkovMat() {
  vector<vector<Edge*>> original = graph_.getAdjMatrix();
  markov_mat_.resize(original[0].size(), vector<double>(original.size()));

  vector<double> colSum;
  colSum.resize(original.size(), 0);

  for (size_t i = 0; i < markov_mat_.size(); i++) {
    for (size_t j = 0; j < markov_mat_[i].size(); j++) {
      if (original[i][j] != nullptr) {
        markov_mat_[j][i] = 1;
        colSum[j] += 1;
      } else {
        markov_mat_[j][i] = 0;
      }
    }
  }

  for (size_t i = 0; i < markov_mat_.size(); i++) {
    for (size_t j = 0; j < markov_mat_[i].size(); j++) {
      markov_mat_[i][j] = markov_mat_[i][j] / colSum[j];
    }
  }
}

vector<double> PageRank::multiplication(const vector<vector<double>>& mat,
                                        const vector<double>& vec) {
  vector<double> output;
  output.resize(vec.size());

  for (size_t i = 0; i < mat.size(); i++) {
    double prod = 0;
    for (size_t j = 0; j < mat[i].size(); j++) {
      prod += mat[i][j] * vec[j];
    }
    output[i] = prod;
  }
  return output;
}

bool PageRank::vecEqual(const vector<double>& v1, const vector<double>& v2,
                        double e) {
  if (v1.size() != v2.size()) return false;

  for (size_t i = 0; i < markov_mat_.size(); i++) {
    if (fabs(v1[i] - v2[i]) > e) {
      return false;
    }
  }
  return true;
}

const string& PageRank::getHighestRank() {
  bool proceed = true;
  vector<double> rank;
  rank.resize(markov_mat_.size());
  for (size_t i = 0; i < rank.size(); i++) {
    rank[i] = 1.0 / rank.size();
  }

  while (proceed) {
    vector<double> product = multiplication(markov_mat_, rank);
    proceed = !vecEqual(product, rank);
    rank = product;
  }

  int idx = 0;
  double highest = 0;
  for (unsigned int i = 0; i < rank.size(); i++) {
    if (rank[i] > highest) {
      idx = i;
      highest = rank[i];
    }
  }
  return graph_.findKeyByIdx(idx);
}
