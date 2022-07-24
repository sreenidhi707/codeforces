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

std::vector<int> readNumbersInLine() {
  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  int num;
  std::vector<int> nums;
  while (iss >> num) {
    nums.push_back(num);
  }
  return nums;
}

int main() {
  // freopen("input.txt", "r", stdin);

  int arrayLength = 0, numSubsets = 0, numQueries = 0;
  std::cin >> arrayLength >> numSubsets >> numQueries;

  std::vector<int64_t> nums(arrayLength + 1); // +1 because indices are 1 based
  for (int i = 1; i < arrayLength + 1; i++) { // note 1 based indexing
    std::cin >> nums[i];
  }

  std::string line;
  std::getline(std::cin, line);

  std::vector<std::vector<int>> indices(numSubsets + 1);

  for (int i = 1; i < numSubsets + 1; i++) {
    int numElems;
    std::cin >> numElems;
    std::vector<int> temp(numElems);
    for (size_t j = 0; j < numElems; j++) {
      std::cin >> temp[j];
    }

    indices[i] = temp;
  }

  // read queries
  for (int i = 0; i < numQueries; i++) {
    char queryType;
    std::cin >> queryType;
    if(queryType == '?') {
      int k;
      std::cin >> k;

      int64_t subsetSum = 0;
      for (size_t i = 0; i < indices[k].size(); i++) {
        subsetSum += nums[indices[k][i]];
      }
      std::cout << subsetSum << std::endl;
    }
    else {
      int k, x;
      std::cin >> k >> x;
      for (size_t j = 0; j < indices[k].size(); j++) {
        nums[indices[k][j]] += x;
      }
    }
  }
}
