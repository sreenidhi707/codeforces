#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void problem_1581B_diameter_of_graph(int64_t numNodes, int64_t numEdges, int64_t diameterLessEqualThan) {
  int64_t numEdgesInFullyConnectedGraph = (numNodes * (numNodes - 1)) / 2;

  // we want the graph to be a 'connnected graph'
  if(numEdges < numNodes - 1 or
     numEdges > numEdgesInFullyConnectedGraph) {
    std::cout << "NO" << std::endl;
    return;
  }

  if(numNodes == 1 and diameterLessEqualThan == 0) {
    std::cout << "YES" << std::endl;
    return;
  }

  // At this point we can assume that the graph is a 'connected graph'
  if(diameterLessEqualThan >= 2 or
     diameterLessEqualThan == 1 and numEdges == numEdgesInFullyConnectedGraph) {
    std::cout << "YES" << std::endl;
    return;
  }
  std::cout << "NO" << std::endl;
}

int main() {
  int numTests = 0;;
  std::cin >> numTests;
  std::vector<int> data;
  while (numTests--) {
    int64_t numNodes, numEdges, k;
    std::cin >> numNodes >> numEdges >> k;
    int64_t diameter = k - 2;
    problem_1581B_diameter_of_graph(numNodes, numEdges, diameter);
  }
}
