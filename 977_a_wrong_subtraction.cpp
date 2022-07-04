#include <string>
#include <iostream>

/*
https://codeforces.com/problemset/problem/977/A
A. Wrong Subtraction
time limit per test  : 1 second
memory limit per test: 256 megabytes
input                : standard input
output               : standard output

Little girl Tanya is learning how to decrease a number by one, but she does it wrong with
a number consisting of two or more digits. Tanya subtracts one from a number by the
following algorithm:

* if the last digit of the number is non-zero, she decreases the number by one;
* if the last digit of the number is zero, she divides the number by 10
  (i.e. removes the last digit).

You are given an integer number n. Tanya will subtract one from it k times. Your task is
to print the result after all k subtractions.

It is guaranteed that the result will be positive integer number.

Input
The first line of the input contains two integer numbers n and k (2 ≤ n≤ 10^9, 1 ≤ k≤ 50)
— the number from which Tanya will subtract and the number of subtractions correspondingly.

Output
Print one integer number — the result of the decreasing n by one k times.

It is guaranteed that the result will be positive integer number.
*/

uint64_t problem_977(uint64_t n, uint64_t k) {
  while(k-- && n) {
    if(n % 10) {
      n--;
    }
    else {
      n /= 10;
    }
  }
  return n;
}

int main() {
  int n, k;
  std::cin >> n;
  std::cin >> k;

  int result = problem_977(n, k);
  std::cout << result;
}