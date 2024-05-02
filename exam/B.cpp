#include <iostream>

void qsort(int64_t* array, int64_t ind_left_base, int64_t ind_right_base) {
  if (ind_left_base < ind_right_base) {
    int64_t lborder = ind_left_base, rborder = ind_right_base;
    int64_t mid_element = array[(lborder + rborder) / 2];
    while (1) {
      while (array[lborder] < mid_element) {
        ++lborder;
      }
      while (array[rborder] > mid_element) {
        --rborder;
      }
      if (lborder >= rborder) {
        break;
      }
      int64_t temp = array[lborder];
      array[lborder] = array[rborder];
      array[rborder] = temp;
      ++lborder;
      --rborder;
    }
    qsort(array, ind_left_base, rborder);
    qsort(array, rborder + 1, ind_right_base);
  }
}

int main() {
  size_t N = 0;
  int64_t K = 0;
  std::cin >> N >> K;
  int64_t* array = new int64_t[N];
  for (size_t i = 0; i < N; ++i) {
    std::cin >> array[i];
  }
  qsort(array, 0, N - 1);
  size_t max_size;
  for (size_t i = 0; i < N; ++i) {
    size_t size = 1;
    while (i + size < N) {
      if (array[i + size] - array[i] <= 2 * K) {
        ++size;
        continue;
      }
      break;
    }
    if (max_size < size) {
      max_size = size;
    }
  }
  std::cout << max_size;
  delete[] array;
}