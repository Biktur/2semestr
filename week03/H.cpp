#include<iostream>

#define N 7

using namespace std;

void readArray(int (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

int find_unique(int (&a)[N]) {
  int res = a[0];
  for (int i = 1; i < N; ++i) {
    res = res xor a[i];
  }
  return res;
}

void printArray(int (&arr)[N]) {
        for (int i = 0; i < N; ++i) {
        cout << arr[i] << ' ';
    }
}

int main() {
    int a[N] = {0};
    readArray(a);
    cout << find_unique(a);
//    printArray(a);
    return 0;
}