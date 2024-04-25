#include<iostream>

int main() {
  int N = 0;
  std::cin >> N;
  long long ways[4] = {0, 1, 2, 4};
  for (int i = 4; i <= N; ++i) {
    ways[i % 4] = ways[(i - 1) % 4] + ways[(i - 2) % 4] + ways[(i - 3) % 4];
  }
  std::cout << ways[N % 4] << std::endl;
}