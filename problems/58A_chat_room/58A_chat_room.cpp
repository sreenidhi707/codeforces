#include <string>
#include <iostream>

bool problem_58A(const std::string& typedWord) {
  std::string word("hello");

  size_t i = 0, j = 0;
  while(i < word.size() and j < typedWord[j]) {
    if(word[i] == typedWord[j]) {
      // increment only when character matches
      i++;
    }
    j++; // increment always
  }

  // at the end, we want to make sure that all characters in the word "hello" are 'consumed'
  return i == word.size();
}

int main() {
  std::string typedWord;
  std::cin >> typedWord;

  std::string result = problem_58A(typedWord) ? "YES" : "NO";

  std::cout << result << std::endl;
}