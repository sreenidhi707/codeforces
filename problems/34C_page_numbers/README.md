

# Problem 34C Page Numbers

<p align="center">
https://codeforces.com/problemset/problem/34/C <br />
Keywords: String, Sorting <br />
Date First Written: 27<sup>th</sup> July 2022 <br />
Most Recent Edit: 27<sup>th</sup> July 2022
</p>
<hr>

«Bersoft» company is working on a new version of its most popular text editor — Bord 2010. Bord, like many other text editors, should be able to print out multipage documents. A user keys a sequence of the document page numbers that he wants to print out (separates them with a comma, without spaces).

Your task is to write a part of the program, responsible for «standardization» of this sequence. Your program gets the sequence, keyed by the user, as input. The program should output this sequence in format $l_1-r_1,l_2-r_2,...,l_k-r_k$, where $r_i + 1 < l_i + 1$ for all $i$ from $1$ to $k - 1$, and $l_i \leq r_i$. The new sequence should contain all the page numbers, keyed by the user, and nothing else. If some page number appears in the input sequence several times, its appearances, starting from the second one, should be ignored. If for some element $i$ from the new sequence $l_i = r_i$, this element should be output as $l_i$, and not as «$l_i - l_i$».

For example, sequence `1,2,3,1,1,2,6,6,2` should be output as `1-3,6`.

## Input
The only line contains the sequence, keyed by the user. The sequence contains at least one and at most 100 positive integer numbers. It's guaranteed, that this sequence consists of positive integer numbers, not exceeding 1000, separated with a comma, doesn't contain any other characters, apart from digits and commas, can't end with a comma, and the numbers don't contain leading zeroes. Also it doesn't start with a comma or contain more than one comma in a row.

## Output
Output the sequence in the required format.

## Examples
```
input
1,2,3,1,1,2,6,6,2

output
1-3,6

input
3,2,1

output
1-3

input
30,20,10

output
10,20,30

```

## Solution
This is a reasonably easy problem, an approach could be
1. Sort the given numbers.
2. Remove the the duplicates.
3. Merge the "groups" and output group ranges.

Steps 1 and 2 can be accomplished by simply inserting the given page numbers into a
`std::set<int>` and then creating a `std::vector<int>` out of them.

Note that it is the 3rd step which is somewhat tricky and needs some explanation. First
let us define a "group" as a section of the array which has numbers continually increasing
by exactly 1. For example

Numbers ---------> 2, 3, 6, 7, 8, 10, 15, 16
Three groups ----> ****  ^^^^^^^      ######

There are 3 groups in the above list of numbers with three separate symbols underneath them.


The code snippet below implements group merging logic, note that the only purpose of the
`bool` variable `first` is to handling printing "`,`".

```cpp
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
```

The complete code is below
```cpp
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
```
|                   |               |
| ----------------- | ------------- |
| Time Complexity   | $O(nlogn)$ time is dominated by sorting     |
| Space Complexity  | $O(n)$   space needed for `std::set<int>`     |