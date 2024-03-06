#include<iostream>

#define N 5

using namespace std;

void readArray(int (&arr)[N * N]) {
    for (int i = 0; i < N * N; ++i) {
        cin >> arr[i];
    }
}

int trace(int (&array)[N * N]) {
  int s = 0;
  for (int i = 0; i < N * N; i += N + 1) {
    s += array[i];
  }
  return s;
}

void printArray(int (&arr)[N * N]) {
        for (int i = 0; i < N; ++i) {
        cout << arr[i] << ' ';
    }
}

int main() {
    int a[N * N] = {0};
    readArray(a);
    cout << trace(a);
//    printArray(a);
    return 0;
}