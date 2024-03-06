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

void printTransposed(int (&array)[N][M]){
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N - 1; ++j) {
      cout << array[j][i] << ' ';
    }
    cout << array[N - 1][i] << endl;
  }
}

void printArray(int (&arr)[N][M]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << arr[i][j] << ' ';
    }
  }
}

int main() {
  int a[N][M] = {0};
  readArray(a);
  printTransposed(a);
//  printArray(a);
  return 0;
}