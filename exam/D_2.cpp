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
  int64_t K = 0;
  std::cin >> K;
  int64_t* times = new int64_t[N * K];
  for (size_t i = 0; i < N; ++i) {
    times[i * K] = time[i];
    for (size_t j = 1; j < K; ++j) {
      times[i * K + j] = times[i * K + j - 1] + time[i];
    }
  }
  qsort(times, 0, N * K - 1);
  std::cout << times[K - 1];
  delete[] time;
  delete[] times;
}
