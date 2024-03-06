#include<iostream>

#define N 5
#define M 3

using namespace std;

void readArray(int (&arr)[N][M]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> arr[i][j];
    }
  }
}

void sort2d(int (&array)[N][M]) {
  for (int i = 0; i < N * M; ++i) {
    for (int j = i; j > 0; --j) {
      if (array[j / M][j % M] >= array[(j - 1) / M][(j - 1) % M]) {
        break;
      }
      array[j / M][j % M] += array[(j - 1) / M][(j - 1) % M], array[(j - 1) / M][(j - 1) % M] = array[j / M][j % M] - array[(j - 1) / M][(j - 1) % M], array[j / M][j % M] -= array[(j - 1) / M][(j - 1) % M];
    }
  }
}

void printArray(int (&arr)[N][M]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  int a[N][M] = {0};
  readArray(a);
  sort2d(a);
  printArray(a);
  return 0;
}