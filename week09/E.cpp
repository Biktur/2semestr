#include<iostream>

int main() {
  int64_t N = 0, k = 0;
  size_t S = 0;
  std::cin >> N >> k >> S;
  int64_t* dist = new int64_t[S + 1];
  std::cin >> dist[0];
  for (size_t i = 1; i < S; ++i) {
    std::cin >> dist[i];
  }
  dist[S] = N;
  size_t start = 0;
  int64_t counter = 0;
  while (true) {
    if (dist[start + 1] - dist[start] > k) {
      std::cout << -1;
      delete[] dist;
      return 0;
    }
    if (dist[S] - dist[start] <= k) {
      std::cout << counter;
      delete[] dist;
      return 0;
    }
    for (size_t end = S - 1; end > start; -- end) {
      if (dist[end] - dist[start] <= k) {
        ++counter;
        start = end;
      }
    }
  }
}