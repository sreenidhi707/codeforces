#include <string>
#include <iostream>
#include <algorithm>

bool problem_158B(std::vector<int>& groupSizes) {

  std::sort(groupSizes.begin(), groupSizes.end());
  int maxNumPeoplePerTaxi = 4;
  int minimumNumOfTaxis = 0;
  int beginPtr = 0, endPtr = groupSizes.size() - 1;

  // collect all the group sizes with 4 at the end
  while(endPtr >= 0 and groupSizes[endPtr] == maxNumPeoplePerTaxi) {
    minimumNumOfTaxis++;
    endPtr--;
  }

  while(beginPtr < groupSizes.size() and beginPtr < endPtr) {
    int numPeopleInThisTaxi = 0;
    while(numPeopleInThisTaxi + groupSizes[endPtr] < ) {

    }
    numPeopleInThisTaxi += groupSizes[endPtr];

  }

  return false;
}

int main() {
  int numGroups;
  std::cin >> numGroups;

  std::vector<int> groupSizes;
  while(numGroups--) {
    int groupsize = 0;
    std::cin >> groupsize;
    groupSizes.push_back(groupsize);
  }

  bool result = problem_158B(groupSizes);

  std::cout << result << std::endl;
}
