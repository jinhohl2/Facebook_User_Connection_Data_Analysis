#include "../include/Graph.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::fstream;
using std::priority_queue;

const string& Graph::findKeyByIdx(int idx) const {
  for (const auto& it : vertices_) {
    if (it.second.index() == idx) {
      return it.second.key();
    }
  }
  return "";
}

void Graph::insertVertex(const string& key) {
  if (vertices_.find(key) != vertices_.end()) return;
  vertices_[key] = Vertex(key, adj_matrix_.size());

  for (vector<Edge*>& row : adj_matrix_) {
    row.emplace_back(nullptr);
  }
  adj_matrix_.emplace_back(adj_matrix_.size() + 1, nullptr);
}

void Graph::insertEdge(const string& v1, const string& v2) {
  if (adj_matrix_[vertices_[v1].index()][vertices_[v2].index()] != nullptr ||
      v1 == v2)
    return;

  auto* edge = new Edge(vertices_[v1], vertices_[v2]);
  adj_matrix_[vertices_[v1].index()][vertices_[v2].index()] = edge;
  adj_matrix_[vertices_[v2].index()][vertices_[v1].index()] = edge;
}

vector<Vertex*> Graph::getNeighbours(const Vertex& v) const {
  vector<Vertex*> neighbours;
  vector<Edge*> row = adj_matrix_[v.index()];

  for (Edge* edge : row) {
    if (edge != nullptr) {
      Vertex& other = edge->getOtherEnd(v);
      neighbours.push_back(&other);
    }
  }
  return neighbours;
}

bool Graph::isAdjacent(const string& v1, const string& v2) const {
  return adj_matrix_[vertices_.at(v1).index()][vertices_.at(v2).index()] !=
         nullptr;
}

void Graph::readFromFile(const string& file_name) {
  fstream file;
  file.open(file_name);

  if (file.is_open()) {
    while (!file.eof()) {
      string src, dest;
      file >> src >> dest;

      insertVertex(src);
      insertVertex(dest);
      insertEdge(src, dest);
    }
  }
}

void Graph::printShortestPath(const string& src, const string& dest) {
  cout << "*** Shortest path from " << src << " to " << dest << " ***" << endl;

  if (!contains(src)) {
    cout << src << " is not in the graph." << endl;
  }
  if (!contains(dest)) {
    cout << dest << " is not in the graph." << endl;
  }
  if (!contains(src) or !contains(dest)) return;

  vector<Vertex> shortest_path = findShortestPath(src, dest);
  if (shortest_path.size() < 2) {
    cout << "Path does not exist." << endl;
    return;
  }

  for (size_t i = 0; i < shortest_path.size(); ++i) {
    cout << shortest_path[i];
    if (i < shortest_path.size() - 1) {
      cout << " - ";
    }
  }
  cout << endl;
}

vector<Vertex> Graph::findShortestPath(const string& src, const string& dest) {
  for (auto& it : vertices_) {
    it.second.setDistance(INT_MAX);
    it.second.setPrev(nullptr);
  }
  vertices_[src].setDistance(0);

  // Since std::priority_queue is max heap, use custom comparator
  auto cmp = [](Vertex* v1, Vertex* v2) {
    return v1->distance() > v2->distance();
  };

  priority_queue<Vertex*, vector<Vertex*>, decltype(cmp)> q(cmp);
  q.push(&vertices_[src]);
  Graph T;

  while (!q.empty()) {
    Vertex* u = q.top();
    q.pop();
    T.insertVertex(u->key());

    vector<Vertex*> neighbours = getNeighbours(*u);
    for (Vertex* v : neighbours) {
      if (T.contains(v->key())) continue;

      if (u->distance() + 1 < v->distance()) {
        v->setDistance(u->distance() + 1);
        v->setPrev(u);
        q.push(v);
      }
    }
  }

  vector<Vertex> ret;
  Vertex* curr = &vertices_[dest];
  while (curr != nullptr) {
    ret.push_back(*curr);
    curr = curr->prev();
  }
  std::reverse(ret.begin(), ret.end());
  return ret;
}

void Graph::printAllNodes() const {
  for (const auto& it : vertices_) {
    std::cout << it.first << " ";
  }
}
