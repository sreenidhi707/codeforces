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

void problem_1472C_long_jumps_brute_force(std::vector<int>& nums) {
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

void problem_1472C_long_jumps_dynamic_programming(std::vector<size_t>& nums) {
  size_t N = nums.size();
  std::vector<size_t> maxScores = nums;

  uint64_t maxScore = 0;
  for (int i = N - 1; i >= 0; i--) {
    if(i + nums[i] < N) {
      maxScores[i] += maxScores[i + nums[i]];
    }
    maxScore = std::max(maxScore,  maxScores[i]);
  }
  std::cout << maxScore << std::endl;
}

int main() {
  int numTests = 0;;
  std::cin >> numTests;
  while (numTests--) {
    int arrayLength = 0;
    std::cin >> arrayLength;

    std::vector<size_t> nums;
    for (size_t i = 0; i < arrayLength; i++) {
      int num = 0;
      std::cin >> num;
      nums.push_back(num);
    }

    problem_1472C_long_jumps_dynamic_programming(nums);
  }
}
