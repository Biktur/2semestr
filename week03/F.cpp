#include<iostream>

#define N 4

using namespace std;

void readArray(int (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void mergeArrays(int (&lhs)[N], int (&rhs)[N], int (&res)[2 * N]) {
    for (int i = 0; i < N; ++i) {
        res[i] = lhs[i];
    }
    for (int i = 0; i < N; ++i) {
        res[i + N] = rhs[i];
    }
}

void printArray(int (&arr)[2 * N]) {
        for (int i = 0; i < 2 * N; ++i) {
        cout << arr[i] << ' ';
    }
}

int main() {
    int a[N] = {0}, b[N] = {0}, c[2 * N] = {0};
    readArray(a);
    readArray(b);
    mergeArrays(a, b, c);
    printArray(c);
    return 0;
}