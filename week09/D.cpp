#include<iostream>

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
  int64_t S = 0;
  size_t N = 0;
  std::cin >> S >> N;
  int64_t* user_data = new int64_t[N];
  for (size_t i = 0; i < N; ++i) {
    std::cin >> user_data[i];
  }
  qsort(user_data, 0, N - 1);
  for (size_t i = 0; i < N; ++i) {
    if (user_data[i] > S) {
      std::cout << i;
      delete[] user_data;
      return 0;
    }
    S -= user_data[i];
  }
  std::cout << N;
  delete[] user_data;
  return 0;
}