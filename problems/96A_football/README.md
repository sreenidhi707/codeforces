

# Problem 96A Football

<p align="center">
https://codeforces.com/problemset/problem/96/A <br />
Keywords: 2 - Pointer, String <br />
Date First Written: 28<sup>th</sup> July 2022 <br />
Most Recent Edit: 28<sup>th</sup> July 2022  <br />
Difficulty: 900
</p>
<hr>

Petya loves football very much. One day, as he was watching a football match, he was writing the players' current positions on a piece of paper. To simplify the situation he depicted it as a string consisting of zeroes and ones. A zero corresponds to players of one team; a one corresponds to players of another team. If there are at least 7 players of some team standing one after another, then the situation is considered dangerous. For example, the situation `00100110111111101` is dangerous and `11110111011101` is not. You are given the current situation. Determine whether it is dangerous or not.

## Input
The first input line contains a non-empty string consisting of characters `"0"` and `"1"`, which represents players. The length of the string does not exceed 100 characters. There's at least one player from each team present on the field.

## Output
Print `"YES"` if the situation is dangerous. Otherwise, print `"NO"`.

## Examples
```
input
001001

output
NO

input
1000000001

output
YES
```
## Solution
Effectively, the problem is **"Given a binary array, find the longest run of either zeros
or ones"** .If the longest run is longer than 7, then it is a dangerous situation.

A simple 2-pointer based solution works here.

The code snippet below implements the brute force approach
```cpp
bool problem_96A(const std::string& playerPositions) {
  const size_t maximumConsecutivePlayers = 7;
  if(playerPositions.size() < maximumConsecutivePlayers) {
    return false;
  }

  size_t i = 0;
  while(i + 1 < playerPositions.size()) {
    if(playerPositions[i] == playerPositions[i + 1]) {
      // start of a potential group
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
```
|                   |               |
| ----------------- | ------------- |
| Time Complexity   | $O(n)$      |
| Space Complexity  | $O(1)$        |

---