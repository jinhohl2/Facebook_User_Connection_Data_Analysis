#pragma once

#include <iostream>
#include <string>

#include "Vertex.h"

using std::string;

class Edge {
 public:
  Edge(Vertex& v1, Vertex& v2) : v1_(v1), v2_(v2) {}

  Vertex& getOtherEnd(const Vertex& v) {
    if (v1_ == v) return v2_;
    return v1_;
  }

  bool operator==(const Edge& other) const {
    return (v1_ == other.v1_ && v2_ == other.v2_) ||
           (v1_ == other.v2_ && v2_ == other.v1_);
  }

 private:
  Vertex& v1_;
  Vertex& v2_;
};