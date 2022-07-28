

# Problem 58A Chat room

<p align="center">
https://codeforces.com/problemset/problem/58/A <br />
Keywords: 2 - Pointers, Greedy, String <br />
Date First Written: 28<sup>th</sup> July 2022 <br />
Most Recent Edit: 28<sup>th</sup> July 2022
</p>
<hr>

Vasya has recently learned to type and log on to the Internet. He immediately entered a chat room and decided to say
hello to everybody. Vasya typed the word `s`. It is considered that Vasya managed to say hello if several letters can be
deleted from the typed word so that it resulted in the word `"hello"`. For example, if Vasya types the word
`"ahhellllloou"`, it will be considered that he said hello, and if he types `"hlelo"`, it will be considered that Vasya
got misunderstood and he didn't manage to say hello. Determine whether Vasya managed to say hello by the given word `s`.

## Input
The first and only line contains the word `s`, which Vasya typed. This word consisits of small Latin letters, its length
is no less that 1 and no more than 100 letters.

## Output
If Vasya managed to say hello, print `"YES"`, otherwise print `"NO"`.

## Examples
```
input
ahhellllloou

output
YES

input
hlelo

output
NO
```

## Solution
Two pointer approach is used to solve this problem.

## Code
```cpp
#include <string>
#include <iostream>

bool problem_58A(const std::string& typedWord) {
  std::string helloWord("hello");

  size_t i = 0, j = 0;
  while(i < helloWord.size() and j < typedWord[j]) {
    if(helloWord[i] == typedWord[j]) {
      i++;
    }
    j++;
  }
  return i == helloWord.size();
}

int main() {
  std::string typedWord;
  std::cin >> typedWord;

  std::string result = problem_58A(typedWord) ? "YES" : "NO";

  std::cout << result << std::endl;
}
```