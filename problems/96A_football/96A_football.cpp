#include <string>
#include <iostream>

bool problem_96A(const std::string& playerPositions) {
  const size_t maximumConsecutivePlayers = 7;
  if(playerPositions.size() < maximumConsecutivePlayers) {
    return false;
  }

  size_t i = 0;
  while(i + 1 < playerPositions.size()) {
    if(playerPositions[i] == playerPositions[i + 1]) {
      size_t numConsecutivePlayers = 1;
      while(i + 1 < playerPositions.size() and
            playerPositions[i] == playerPositions[i + 1]) {
        i++;
        numConsecutivePlayers++;
      }

      if(numConsecutivePlayers >= maximumConsecutivePlayers) {
        return true; // dangerous situation found
      }
    }
    else { // TRICKY, I forgot this else part and got infinite loop
      i++;
    }
  }
  return false;
}

int main() {
  std::string playerPositions;
  std::cin >> playerPositions;

  bool result = problem_96A(playerPositions);

  std::cout << (result ? "YES" : "NO") << std::endl;
}