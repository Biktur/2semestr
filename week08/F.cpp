#include<iostream>

int main() {
  int n = 0;
  std::cin >> n;
  long long* sides = new long long [n];
  long long** values = new long long*[n - 1];
  std::cin >> sides[0];
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> sides[i + 1];
    values[i] = new long long[n - 1];
    values[i][i] = 0;
    for (int j = i - 1; j >= 0; --j) {
      values[j][i] = 0;
      for (int k = 0; k < i - j; ++k) {
        if ((values[j][j + k] + values[j + k + 1][i] + sides[j] * sides[j + k + 1] * sides[i + 1] >= values[j][i]) and (values[j][i] != 0)) {
          continue;
        }
        values[j][i] = values[j][j + k] + values[j + k + 1][i] + sides[j] * sides[j + k + 1] * sides[i + 1];
      }
    }
  }
  std::cout << values[0][n-2];
  for (int i = 0; i < n - 1; ++i) {
    delete[] values[i];
  }
  delete[] sides;
  delete[] values;
  return 0;
}