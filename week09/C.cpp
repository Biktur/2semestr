#include<iostream>

int main() {
  size_t k = 0;
  std::cin >> k;
  int64_t* banknotes = new int64_t[k];
  for (size_t i = 0; i < k; ++i) {
    std::cin >> banknotes[i];
  }
  int64_t M = 0;
  std::cin >> M;
  int64_t counter = 0;
  for (int64_t i = k - 1; i >= 0; --i) {
    counter += M / banknotes[i];
    M = M % banknotes[i];
  }
  std::cout << counter;
  delete[] banknotes;
}