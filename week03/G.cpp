#include<iostream>

#define N 1

using namespace std;

void readArray(int (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

int findLastZero(int (&array)[N]) {
    int a = 0, b = N - 1;
    int c = 0;
    if (array[b] == 0) {
        return b;
    }
    while (a < b) {
        c = a + (b - a) / 2;
        if (array[c] != 0) {
            b = c - 1;
        }
        else {
            a = c + 1;
        }
        if (array[b] == 0) {
            return b;
        }
    }
    return a - 1;
}

void printArray(int (&arr)[N]) {
        for (int i = 0; i < N; ++i) {
        cout << arr[i] << ' ';
    }
}

int main() {
    int a[N] = {0};
    readArray(a);
    cout << findLastZero(a);
//    printArray(a);
    return 0;
}