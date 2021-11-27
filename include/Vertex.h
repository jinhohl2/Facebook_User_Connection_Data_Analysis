#pragma once

#include <climits>
#include <cmath>
#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Vertex {
 public:
  Vertex() = default;
  Vertex(const string& key) : key_(key), index_(-1) {}
  Vertex(const string& key, int index) : key_(key), index_(index) {}

  // getters
  const string& key() const { return key_; }
  int index() const { return index_; }
  int distance() const { return distance_; }
  Vertex* prev() const { return prev_; }

  // setters
  void setKey(const string& key) { key_ = key; }
  void setIndex(int index) { index_ = index; }
  void setDistance(int distance) { distance_ = distance; }
  void setPrev(Vertex* prev) { prev_ = prev; }

  bool operator==(const Vertex& other) const { return key_ == other.key_; }

 private:
  string key_;
  int index_;  // adjacency matrix index

  // will be used for Dijkstra's algorithm
  int distance_ = INT_MAX;
  Vertex* prev_ = nullptr;
};

ostream& operator<<(ostream& out, const Vertex& v);