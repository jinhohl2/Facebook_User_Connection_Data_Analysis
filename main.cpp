#include <iostream>
#include <string>

#include "include/Graph.h"
#include "include/PageRank.h"
#include "include/Traversal.h"
using namespace std;

/**
 * Command Line Arguments
 * 1. data file including path
 * 2. start node
 */

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr << "Invalid command line arguments." << endl;
    return 1;
  }

  string data_file = argv[1];
  string start = argv[2];
  string end;

  Graph graph;
  cout << "Reading data from file." << endl;
  graph.readFromFile(data_file);
  cout << "Done." << endl << endl;

  Traversal t = Traversal(graph);
  cout << "Finding connected component that includes " << start << " with DFS."
       << endl;
  Graph sub = t.findConnectedSubgraph(start);
  cout << "Done." << endl << endl;

  PageRank pRank = PageRank(sub);
  cout << "Finding the most influential person among the group." << endl;
  pRank.getTransposedMarkovMat();
  end = pRank.getHighestRank();
  cout << "End node found by PageRank: " << end << "\n\n";

  cout << "Start: " << start << ", The most influential person: " << end
       << endl;
  graph.printShortestPath(start, end);
}
