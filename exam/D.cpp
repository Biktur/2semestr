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
  std::cin >> N;
  int64_t* time = new int64_t[N];
  for (size_t i = 0; i < N; ++i) {
    std::cin >> time[i];
  }
  qsort(time, 0, N - 1);
  int64_t K = 0;
  std::cin >> K;
  size_t done = 0;
  for (int64_t i = time[0]; i <= 2147483647; ++i) {
    for (size_t j = 0; j < N; ++j) {
      if (i % time[j] == 0) {
        ++done;
      }
    }
    if (done >= K) {
      std::cout << i;
      delete[] time;
      return 0;
    }
  }
  std::cout << 0;
  delete[] time;
  return 0;
}