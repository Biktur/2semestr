#include <iostream>
#include <algorithm>

#define N 5 

using namespace std;

void qsort(int (&array)[N], int ind_left_base, int ind_right_base) {
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
      std::swap(array[lborder], array[rborder]);
      ++lborder;
      --rborder;
    }
    qsort(array, ind_left_base, rborder);
    qsort(array, rborder + 1, ind_right_base);
  }
}

void readArray(int (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void printArray(int (&arr)[N]) {
        for (int i = 0; i < N; ++i) {
        cout << arr[i] << ' ';
    }
}

int main() {
  int array[N] = {0};
  readArray(array);
  qsort(array, 0, N - 1);
  printArray(array);
}