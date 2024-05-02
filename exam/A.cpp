#include <iostream>

int main() {
    size_t N = 0;
    std::cin >> N;
    int64_t* numbers = new int64_t[N];
    size_t amount_of_odd = 0;
    for (size_t i = 0; i < N; ++i) {
        std::cin >> numbers[i];
        if (numbers[i] % 2 == 0) {
            continue;
        }
        ++amount_of_odd;
    }
    size_t amount_of_even = 0;
    for (size_t i = 0; i < N; ++i) {
      if (amount_of_even == amount_of_odd) {
        std::cout << i;
        delete[] numbers;
        return 0;
      }
      if (numbers[i] % 2 == 0) {
        ++amount_of_even;
        continue;
      }
      --amount_of_odd;
    }
  std::cout << N;
  delete[] numbers;
  return 0;
}