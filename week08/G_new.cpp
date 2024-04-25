#include<iostream>

void qsort(int* array, int ind_left_base, int ind_right_base) {
  if (ind_left_base < ind_right_base) {
    int lborder = ind_left_base, rborder = ind_right_base;
    int mid_element = array[(lborder + rborder) / 2];
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
      int temp = array[lborder];
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
  int* sequence = new int[N];
  int* temp = new int[N];
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> sequence[i];
    temp[i] = sequence[i];
  }
  qsort(temp, 0, N - 1);
  int* sorted_sequence = new int[N];
  sorted_sequence[0] = temp[0];
  size_t N1 = 1;
  for (unsigned i = 1; i < N; ++i)  {
    if (temp[i] != temp[i - 1]) {
      ++N1;
      sorted_sequence[N1 - 1] = temp[i];
    }
  }
  delete[] temp;
  long long** size = new long long*[N];
  for (unsigned i = 0; i < N; ++i) {
    size[i] = new long long[N1];
    for (unsigned j = 0; j < N1; ++j) {
      if (i == 0 and j == 0) {
        if (sequence[i] == sorted_sequence[j]) {
          size[i][j] = 1;
          continue;
        }
        size[i][j] = 0;
        continue;
      }
      if (i == 0) {
        if (sequence[i] == sorted_sequence[j]) {
          size[i][j] = 1;
          continue;
        }
        size[i][j] = size[i][j - 1];
        continue;
      }
      if (j == 0) {
        if (sequence[i] == sorted_sequence[j]) {
          size[i][j] = 1;
          continue;
        }
        size[i][j] = size[i - 1][j];
        continue;
      }
      if (sequence[i] == sorted_sequence[j]) {
        size[i][j] = size[i - 1][j - 1] + 1;
        continue;
      }
      if (size[i - 1][j] >= size[i][j - 1]){
        size[i][j] = size[i - 1][j];
        continue;
      }
      size[i][j] = size[i][j - 1];
    }
  }
  unsigned i = N - 1;
  unsigned j = N1 - 1;
  while ((i >= 0) and (j >= 0)) {
    if ((i == 0) and (j == 0)) {
      std::cout << sequence[i] << ' ';
      break;
    }
    if (i == 0) {
      if (size[i][j - 1] == 0) {
        std::cout << sequence[i] << ' ';
        break;
      }
      --j;
      continue;
    }
    if (j == 0) {
      if (size[i - 1][j] == 0) {
        std::cout << sequence[i] << ' ';
        break;
      }
      --i;
      continue;
    }
    if (size[i][j] == size[i - 1][j]) {
      --i;
      continue;
    }
    if (size[i][j] == size[i][j - 1]) {
      --j;
      continue;
    }
    if (size[i - 1][j - 1] == 0) {
      std::cout << sequence[i] << ' ';
      --i;
      --j;
      break;
    }
    std::cout << sequence[i] << ' ';
    --i;
    --j;
  }
  std::cout << size[N - 1][N1 - 1];
  for (unsigned i = 0; i < N; ++i) {
    delete[] size[i];
  }
  delete[] size;
  delete[] sequence;
  delete[] sorted_sequence;
}