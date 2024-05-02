#include<iostream>

bool pattern_match(char const* pattern, char const* str) {
  size_t pattern_size = 0;
  while (pattern[pattern_size] != '0') {
    ++pattern_size;
  }
  size_t str_size = 0;
  while (str[str_size] != '0') {
    ++str_size;
  }
  bool** match = new bool*[pattern_size + 1];
  for (size_t i = 0; i <= pattern_size; ++i) {
    match[i] = new bool[str_size + 1];
    for (size_t j = 0; j <= str_size; ++j) {
      if (i == 0) {
        match[i][j] = (j == 0);
        continue;
      }
      if (pattern[i - 1] == '*') {
        if (j == 0) {
          match[i][j] = match[i - 2][j];
          continue;
        }
        match[i][j] = ((str[j - 1] == pattern[i - 2]) and (match[i][j - 1])) or (match[i - 2][j]);
        continue;
      }
      if (j == 0) {
        match[i][j] = 0;
        continue;
      }
      match[i][j] = match[i - 1][j - 1] and (str[j - 1] == pattern[i - 1]);
    }
  }
  bool answer = match[pattern_size][str_size];
  for (size_t i = 0; i <= pattern_size; ++i) {
    for (size_t j = 0; j <= str_size; ++j) {
      std::cout << match[i][j];
    }
    std::cout << std::endl;
  }
  for (size_t i = 0; i <= pattern_size; ++i) {
    delete[] match[i];
  }
  delete[] match;
  return answer;
}

int main() {
  char* pattern = new char[100];
  char* str = new char[100];
  for (size_t i = 0; i < 100; ++i) {
    std::cin >> pattern[i];
    if (pattern[i] == '0') {
      break;
    }
  }
  for (size_t i = 0; i < 100; ++i) {
    std::cin >> str[i];
    if (str[i] == '0') {
      break;
    }
  }
  std::cout << pattern_match(pattern, str);
  delete[] pattern;
  delete[] str;
}