#include<iostream>

void number_of_ones(int64_t N) {
  int64_t number = 0;
  while (N != 0) {
    number += (N % 2);
    N /= 2;
  }
  std::cout << number << ' ';
}

int main() {
  size_t N = 0;
  std::cin >> N;
  for (size_t i = 0; i < N; ++i) {
    int64_t a = 0;
    std::cin >> a;
    number_of_ones(a);
  }
}