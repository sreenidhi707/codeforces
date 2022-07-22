
# Problem 160A Twins

<p align="center">
https://codeforces.com/problemset/problem/160/A <br />
Keywords: Greedy, Sorting <br />
Date First Written: 21<sup>st</sup> July 2022 <br />
Most Recent Edit: 21<sup>st</sup> July 2022
</p>
<hr>

Imagine that you have a twin brother or sister. Having another person that looks exactly like you seems very unusual.
It's hard to say if having something of an alter ego is good or bad. And if you do have a twin, then you very well know
what it's like.

Now let's imagine a typical morning in your family. You haven't woken up yet, and Mom is already going to work. She has
been so hasty that she has nearly forgotten to leave the two of her darling children some money to buy lunches in the
school cafeteria. She fished in the purse and found some number of coins, or to be exact, $n$ coins of arbitrary values
$a_1, a_2, ..., a_n$. But as Mom was running out of time, she didn't split the coins for you two. So she scribbled a note
asking you to split the money equally.

As you woke up, you found Mom's coins and read her note. "But why split the money equally?" — you thought. After all,
your twin is sleeping and he won't know anything. So you decided to act like that: pick for yourself some subset of
coins so that the sum of values of your coins is **strictly larger** than the sum of values of the remaining coins that your
twin will have. However, you correctly thought that if you take too many coins, the twin will suspect the deception.
So, you've decided to stick to the following strategy to avoid suspicions: you take the **minimum number of coins**,
whose sum of values is strictly more than the sum of values of the remaining coins. On this basis, determine what **minimum** number of coins you need to take to divide them in the described manner.

## Input
The first line contains integer $n (1 ≤ n ≤ 100)$ — the number of coins.
The second line contains a sequence of $n$ integers $a_1, a_2, ..., a_n (1 ≤ a_i ≤ 100)$ — the coins' values.
All numbers are separated with spaces.

## Output
In the single line print the single number — the minimum needed number of coins.

## Examples
```
input
2
3 3
output
2

input
3
2 1 2
output
2
```
Note
In the first sample you will have to take $2$ coins (you and your twin have sums equal to $6$, $0$ correspondingly). If you take $1$ coin, you get sums $3$, $3$. If you take $0$ coins, you get sums $0$, $6$. Those variants do not satisfy you as your sum should be strictly more that your twins' sum.

In the second sample one coin isn't enough for us, too. You can pick coins with values $1$, $2$ or $2$, $2$. In any case, the minimum number of coins equals $2$.

## Solution
Two main points to consider in this problem
1. The amount of money to be taken has to be **strictly** more than what is left AND
2. We need to **minimize** the number of coins taken

A strategy to employ could be
1. First sort the given coins by decreasing order of their value.
2. Starting from the largest value, keep taking the coins until the value taken is less than or equal to the value left.

Since we always keep taking the largest possible coin denomination, we are guaranteed to minimize the number of coins.

|                   |               |
| ----------------- | ------------- |
| Time Complexity   | $O(NlogN)$, for sorting        |
| Space Complexity  | $O(N)$, due to sorting        |

```cpp
#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // needed for std::sort()
#include <numeric>   // needed for std::accumulate()

int problem_160A_twins(std::vector<int>& coinValues) {
  // sort in descending order
  std::sort(coinValues.rbegin(), coinValues.rend());

  // find the sum of all the coin values
  int sum = std::accumulate(coinValues.begin(), coinValues.end(), 0);

  size_t numCoinsTaken = 0, valueTaken = 0, i = 0;
  size_t valueRemaining = sum;
  while(i < coinValues.size() and valueTaken <= valueRemaining) {
    valueTaken += coinValues[i];
    valueRemaining -= coinValues[i];
    numCoinsTaken++;
    i++;
  }

  return numCoinsTaken;
}

int main() {
  size_t numCoins;
  std::cin >> numCoins;

  std::vector<int> coinValues;
  while(numCoins--) {
    int coinValue = 0;
    std::cin >> coinValue;
    coinValues.push_back(coinValue);
  }

  size_t result = problem_160A_twins(coinValues);

  std::cout << result << std::endl;
}
```
