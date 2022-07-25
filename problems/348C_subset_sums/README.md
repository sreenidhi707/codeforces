# Problem 348C Subset Sums

<p align="center">
https://codeforces.com/problemset/problem/348/C <br />
Keywords: Brute Force, Data Structures, sqrt(N) <br />
Date First Written: 24<sup>th</sup> July 2022 <br />
Most Recent Edit: 24<sup>th</sup> July 2022
</p>
<hr>

You are given an array $a_1, a_2, ..., a_n$ and $m$ sets $S_1, S_2, ..., S_m$ of indices of elements of this array. Let's denote $S_k = \{ S_{k, i} \} (1 \leq i \leq |S_k|)$. In other words, $S_{k, i}$ is some element from set $S_k$.

In this problem you have to answer $q$ queries of the two types:

* Find the sum of elements with indices from set $S_k:\sum_{i=1}^{|S_k|} a_{S_{k,i}}$. The query format is `"? k"`.

* Add number $x$ to all elements at indices from set $S_k: a_{S_{k,i}}$is replaced by $a_{S_{k,i}}+x$ for all $i (1 \leq i \leq |Sk|)$. The query format is `"+ k x"`.

After each first type query print the required sum.

## Input
The first line contains integers $n, m, q (1 \leq n, m, q \leq 10^5)$. The second line contains $n$ integers $a_1, a_2, ..., a_n (|a_i| ≤ 10^8)$ — elements of array $a$.

Each of the following $m$ lines describes one set of indices. The $k$-th line first contains a positive integer, representing the number of elements in set $(|S_k|)$, then follow $|S_k|$ distinct integers $S_{k,1}, S_{k,2}, ..., S_{k,|S_k|} (1 \leq S_k, i \leq n)$ — elements of set $S_k$.

The next $q$ lines contain queries. Each query looks like either `"? k"` or `"+ k x"` and sits on a single line. For all queries the following limits are held: $1 \leq k \leq m, |x| ≤ 10^8$. The queries are given in order they need to be answered.

It is guaranteed that the sum of sizes of all sets $S_k$ doesn't exceed $10^5$.

## Output
After each first type query print the required sum on a single line.

Please, do not write the `%lld` specifier to read or write 64-bit integers in С++. It is preferred to use the `cin`, `cout` streams or the `%I64d` specifier.

## Examples
```
input
5 3 5
5 -5 5 1 -4
2 1 2
4 2 1 4 5
2 2 5
? 2
+ 3 4
? 1
+ 2 1
? 2

output
-3
4
9
```
## Solution
### Brute Force
This is not s simple problem. However a brute force solution is fairly easy to code up.

* For `query`, simply sum up the values of the array $a$ based on the locations present
  in `indices`.
* For `update`, add the value `k` to all those locations present in `indices`.

The code snippet below implements the brute force approach, note that this gives a `Time
limit exceeded` error.
```cpp
void bruteForce() {
  freopen("input.txt", "r", stdin);

  int arrayLength = 0, numSubsets = 0, numQueries = 0;
  std::cin >> arrayLength >> numSubsets >> numQueries;

  std::vector<int64_t> nums(arrayLength + 1); // +1 because indices are 1 based
  for (int i = 1; i < arrayLength + 1; i++) { // note 1 based indexing
    std::cin >> nums[i];
  }

  std::vector<std::vector<int>> subsets(numSubsets + 1);
  for (int i = 1; i < numSubsets + 1; i++) {
    int numElems;
    std::cin >> numElems;
    std::vector<int> temp(numElems);
    for (size_t j = 0; j < numElems; j++) {
      std::cin >> temp[j];
    }

    subsets[i] = temp;
  }

  // read queries
  for (int i = 0; i < numQueries; i++) {
    char queryType;
    std::cin >> queryType;
    if(queryType == '?') {
      int k;
      std::cin >> k;

      int64_t subsetSum = 0;
      for (size_t i = 0; i < subsets[k].size(); i++) {
        subsetSum += nums[subsets[k][i]];
      }
      std::cout << subsetSum << std::endl;
    }
    else {
      int k, x;
      std::cin >> k >> x;
      for (size_t j = 0; j < subsets[k].size(); j++) {
        nums[subsets[k][j]] += x;
      }
    }
  }
}
```
|                   |               |
| ----------------- | ------------- |
| Time Complexity   | $O(n^2)$, where $n$ is the number |
|                   | of queries and each query can be $n$ long      |
| Space Complexity  | $O(n^2)$        |

---

### Optimized, TBD
There is a tutorial for this problem here https://codeforces.com/blog/entry/9031. The goal is to
reduce the $O(n^2)$ to $O(n \sqrt{n})$.

One optimization for the `sum` could be that we could precalculate all the subset sums as
and when they are read and simply lookup into the array. If there were only `sum` type
queries, we would get a $O(1)$ runtime, however due to `add` we also need a way to keep track
of `x` values which needs to be added to the `sum` query. This would still make `add` $O(n)$
resulting in overall $O(n^2)$.

The solution talks about splitting the set of subsets into two sets called $heavy$ and $light$.
$light$ set contains less than $\sqrt{n}$ elements and other sets are $heavy$. Key observation
is that
* Each $light$ set contains less than $\sqrt{n}$ elements.
* The number of $heavy$ sets does not exceed $\sqrt{n}$ elements.

I'm not sure how exactly this proceeds next, but this is what the complexity ends up like.
|                   |               |
| ----------------- | ------------- |
| Time Complexity   | $O(n \sqrt{n})$        |
| Space Complexity  | $O(n)$        |
