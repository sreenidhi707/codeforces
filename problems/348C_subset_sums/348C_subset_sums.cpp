#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

template <typename T>
void printVector(const std::vector<T>& nums) {
  for (const auto& it : nums) {
    std::cout << it << std::endl;
  }
}

void bruteForce() {
  freopen("input.txt", "r", stdin);

  int arrayLength = 0, numSubsets = 0, numQueries = 0;
  std::cin >> arrayLength >> numSubsets >> numQueries;

  std::vector<int64_t> nums(arrayLength + 1); // +1 because indices are 1 based
  for (int i = 1; i < arrayLength + 1; i++) { // note 1 based indexing
    std::cin >> nums[i];
  }

  std::vector<std::vector<int>> subsets(numSubsets + 1);
  for (int i = 1; i < numSubsets + 1; i++) {
    int numElems;
    std::cin >> numElems;
    std::vector<int> temp(numElems);
    for (size_t j = 0; j < numElems; j++) {
      std::cin >> temp[j];
    }

    subsets[i] = temp;
  }

  // read queries
  for (int i = 0; i < numQueries; i++) {
    char queryType;
    std::cin >> queryType;
    if(queryType == '?') {
      int k;
      std::cin >> k;

      int64_t subsetSum = 0;
      for (size_t i = 0; i < subsets[k].size(); i++) {
        subsetSum += nums[subsets[k][i]];
      }
      std::cout << subsetSum << std::endl;
    }
    else {
      int k, x;
      std::cin >> k >> x;
      for (size_t j = 0; j < subsets[k].size(); j++) {
        nums[subsets[k][j]] += x;
      }
    }
  }
}

void speedOptimized() {
  freopen("input.txt", "r", stdin);

  int arrayLength = 0, numSubsets = 0, numQueries = 0;
  std::cin >> arrayLength >> numSubsets >> numQueries;

  std::vector<int64_t> nums(arrayLength + 1); // +1 because indices are 1 based
  for (int i = 1; i < arrayLength + 1; i++) { // note 1 based indexing
    std::cin >> nums[i];
  }

  std::string line;
  std::getline(std::cin, line);

  std::vector<std::vector<int>> subsets(numSubsets + 1);
  std::vector<int64_t> subsetSums(numSubsets + 1, 0);
  std::vector<int64_t> subsetLengths(numSubsets + 1, 0);

  for (int i = 1; i < numSubsets + 1; i++) {
    std::cin >> subsetLengths[i];
    int index;
    for (size_t j = 0; j < subsetLengths[i]; j++) {
      std::cin >> index;
      subsetSums[i] += nums[index];
    }
  }

  // read queries
  for (int i = 0; i < numQueries; i++) {
    char queryType;
    std::cin >> queryType;
    if(queryType == '?') {
      int k;
      std::cin >> k;

      int64_t subsetSum = 0;
      for (size_t i = 0; i < subsets[k].size(); i++) {
        subsetSum += nums[subsets[k][i]];
      }
      std::cout << subsetSums[k] << std::endl;
    }
    else {
      int k, x;
      std::cin >> k >> x;
      for (size_t j = 0; j < subsets[k].size(); j++) {
        nums[subsets[k][j]] += x;
      }
    }
  }
}

int main() {
  bruteForce();
}
