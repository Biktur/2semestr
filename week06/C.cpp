#include <iostream>

int main() {
  int N = 0, M = 0, k = 0;
  std::cin >> N >> M >> k;
  int *array = new int[N * M];
  for (int i = 0; i < N * M; ++i) {
    std::cin >> array[i];
  }
  int i = 0, j = M - 1;
  int is_in_matrix = 0;
  while (i < N and j >= 0) {
    if (array[M * i + j] == k) {
      is_in_matrix = 1;
      break;
    }
    if (array[M * i + j] > k) {
      --j;
      continue;
    }
    ++i;
  }
  std::cout << is_in_matrix;
}