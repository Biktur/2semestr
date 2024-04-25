#include<iostream>

int main() {
  int N = 0;
  std::cin >> N;
  long long Fib_sq[4] = {0, 0, 1, 1};
  for (int i = 0; i < N - 1; ++i) {
    Fib_sq[(i + 4) % 4] = 2 * Fib_sq[(i + 3) % 4] + 2 * Fib_sq[(i + 2) % 4] - Fib_sq[(i + 1) % 4];
  }
  std::cout << Fib_sq[(N + 2) % 4] << std::endl;
}