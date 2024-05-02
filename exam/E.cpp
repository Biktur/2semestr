#include <iostream>

int main() {
  size_t N = 0;
  std::cin >> N;
  uint64_t* amount = new uint64_t[N + 1];
  amount[0] = 1;
  amount[1] = 1;
  for (size_t i = 2; i <= N; ++i) {
    amount[i] = amount[i - 1] + amount[i - 2];
    for (size_t j = i - 3; j + 3 >= 3; --j) {
      amount[i] += 2 * amount[j];
    }
  }
  std::cout << amount[N];
  delete[] amount;
}