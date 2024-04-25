#include<iostream>

int main() {
  int64_t M = 0, N = 0;
  std::cin >> M >> N;
  while (true) {
    int64_t den = N / M + 1 - (N % M == 0);
    if (N % M == 0) {
      std::cout << den << std::endl;
      break;
    }
    std::cout << den << ' ';
    M = M * den - N;
    N = N * den;
  }
}