#include <string>
#include <iostream>
#include <vector>
#include <numeric> // needed for std::iota

void rotateInRange(std::vector<int>& arr,
                   size_t begin, size_t end) {
  int lastItem = arr[end - 1];
  for (size_t i = end - 1; i > begin; i--) {
    arr[i] = arr[i - 1];
  }
  arr[begin] = lastItem;
}

void rotateInGroups(std::vector<int>& arr,
                    std::vector<std::pair<int, int>>& groupLocations) {
  for (const auto& groupLocation : groupLocations) {
    rotateInRange(arr, groupLocation.first, groupLocation.second);
  }
}

std::vector<int>
problem_1691B_shoe_shuffling(std::vector<int>& shoeSizes) {
  int begin = 0, end = 0;
  std::vector<std::pair<int, int>> groupLocations;
  while (begin < shoeSizes.size()) {
    while (end < shoeSizes.size() and
           shoeSizes[begin] == shoeSizes[end]) {
      end++;
    }

    // we want the group size to be atleast 2
    if(end - begin == 1) {
      return {-1};
    }

    groupLocations.push_back({begin, end}); // half open range [begin, end)
    begin = end;
  }

  std::vector<int> nums(shoeSizes.size());
  std::iota(nums.begin(), nums.end(), 1);
  rotateInGroups(nums, groupLocations);

  return nums;
}

int main() {
  int numTests = 1;
  std::cin >> numTests;
  while (numTests--) {
    int numStudents = 0;
    std::cin >> numStudents;

    std::vector<int> shoeSizes;
    int shoeSize = 0;
    while (numStudents--) {
      std::cin >> shoeSize;
      shoeSizes.push_back(shoeSize);
    }

    // std::vector<int> shoeSizes = {1, 1, 2, 3, 3, 3, 3, 44, 44};
    std::vector<int> permutation = problem_1691B_shoe_shuffling(shoeSizes);
    for(const auto& num : permutation) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
}
