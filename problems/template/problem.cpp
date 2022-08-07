#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <limits.h>
#include <map>
#include <unordered_map>

template <typename T>
void printVector(const std::vector<T>& nums) {
  for (const auto& it : nums) {
    std::cout << it << std::endl;
  }
}

void problem_number_title(std::vector<int>& nums) {
  uint64_t maxScore = 0;
  for (size_t i = 0; i < nums.size(); i++) {
    uint64_t thisRunScore = 0;
    int j = i; // start from current index
    while(j < nums.size()) { // jump across the array indices
      thisRunScore += nums[j];
      j += nums[j];
    }
    maxScore = std::max(maxScore, thisRunScore);
  }
  std::cout << maxScore << std::endl;
}

int main() {
  // freopen("input.txt", "r", stdin);
  int numTests = 0;;
  std::cin >> numTests;
  while (numTests--) {
    int arrayLength = 0;
    std::cin >> arrayLength;

    std::vector<int> nums(arrayLength);
    for (size_t i = 0; i < arrayLength; i++) {
      std::cin >> nums[i];
    }

    problem_number_title(nums);
  }
}
