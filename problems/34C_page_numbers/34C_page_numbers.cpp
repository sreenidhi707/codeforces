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

int main() {
  std::string line;
  std::getline(std::cin, line);

  std::stringstream ss(line);
  std::string token;
  std::set<int> pageNumbersSet;
  while (std::getline(ss, token, ',')) {
    pageNumbersSet.insert(std::atoi(token.c_str()));
  }

  std::vector<int> pageNumbersVec(pageNumbersSet.begin(), pageNumbersSet.end());

  /* At this point the page numbers are all
     1. Sorted
     2. Duplicates removed
  */
  int i = 0;
  bool first = true;
  while(i < pageNumbersVec.size()) {
    int groupStart = i, groupEnd = i;
    while(groupEnd + 1 < pageNumbersVec.size() and
          pageNumbersVec[groupEnd] + 1 == pageNumbersVec[groupEnd + 1]) {
      groupEnd++;
    }

    i = groupEnd + 1;

    if (not first) {
      std::cout << ",";
    }

    if(groupStart == groupEnd) {
      std::cout << pageNumbersVec[groupStart];
    }
    else {
      std::cout << pageNumbersVec[groupStart] << "-" << pageNumbersVec[groupEnd];
    }
    first = false;
  }
  std::cout << std::endl;
}