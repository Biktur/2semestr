#include <iostream>

using namespace std;

#define N 10

int linear_sum(long long int array[], long long int array_length, long long int sum_to_find) { // Быстрый алгоритм для находения элементов с заданной суммой
  long long int lborder = 0, rborder = array_length - 1;
  while (lborder < rborder) {
    if (array[lborder] + array[rborder] == sum_to_find) {
      return (lborder + rborder - 2) * (lborder + rborder - 1) / 2 + lborder;
    }
    if (array[lborder] + array[rborder] < sum_to_find) {
      ++lborder;
    }
    if (array[lborder] + array[rborder] > sum_to_find) {
      --rborder;
    }
  }
  return (lborder + rborder - 2) * (lborder + rborder - 1) / 2 + lborder;
}

int quadratic_sum(long long int array[], long long int array_length, long long int sum_to_find) { // Прямой перебор для находения элементов с заданной суммой
  for (int i = 0; i < array_length; ++i) {
    for (int j = 0; j < array_length; ++j) {
      if (i != j) {
        if (array[i] +array[j] == sum_to_find) {
          ;
          return (i + j - 2) * (i + j - 1) / 2 + i;
        }
      }
    }
  }
  return -1;
}


void readArray(long long int (&arr)[N]) {
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
  long long int a[N] = {0};
  long long int b = 0;
  readArray(a);
  cin >> b;
  cout << linear_sum (a, N, b);
}