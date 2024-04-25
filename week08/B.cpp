#include<iostream>

int main() {
  int n = 0;
  std::cin >> n;
  long long given_price[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  long long *max_income = new long long[n];
  for (int i = 0; i < n; ++i) {
    if (i < 10) {
      max_income[i] = given_price[i];
      continue;
    }
    max_income[i] = 0;
  }
  for (int length = 0; length < n; ++length) {
    for (int previous = 0; previous < length; ++previous) {
      if (max_income[length] >= max_income[previous] + max_income[length - previous - 1]) {
        continue;
      }
      max_income[length] = max_income[previous] + max_income[length - previous - 1];
    }
  }
  std::cout << max_income[n - 1];
  delete[] max_income;
}