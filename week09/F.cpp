#include<iostream>

int main() {
  size_t N = 0;
  std::cin >> N;
  int64_t counter = 0;
  int64_t time = 0;
  for (size_t i = 0; i < N; ++i) {
    int64_t start = 0, end = 0;
    std::cin >> start >> end;
    if (start >= time) {
      ++counter;
      time = end;
    }
  }
  std::cout << counter;
}