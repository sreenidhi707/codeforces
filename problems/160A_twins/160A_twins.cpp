#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // needed for std::sort()
#include <numeric>   // needed for std::accumulate()

int problem_160A_twins(std::vector<int>& coinValues) {
  // sort in descending order
  std::sort(coinValues.rbegin(), coinValues.rend());

  // find the sum of all the coin values
  int sum = std::accumulate(coinValues.begin(), coinValues.end(), 0);

  size_t numCoinsTaken = 0, valueTaken = 0, i = 0;
  size_t valueRemaining = sum;
  while(i < coinValues.size() and valueTaken <= valueRemaining) {
    valueTaken += coinValues[i];
    valueRemaining -= coinValues[i];
    numCoinsTaken++;
    i++;
  }

  return numCoinsTaken;
}

int main() {
  size_t numCoins;
  std::cin >> numCoins;

  std::vector<int> coinValues;
  while(numCoins--) {
    int coinValue = 0;
    std::cin >> coinValue;
    coinValues.push_back(coinValue);
  }

  size_t result = problem_160A_twins(coinValues);

  std::cout << result << std::endl;
}
