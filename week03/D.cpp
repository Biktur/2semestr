#include<iostream>

#define N 7

using namespace std;

void readArray(int (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void shiftArrayRight(int (&arr)[N]) {
    for (int i = 1;  i < N; ++i){
        arr[i] += arr[0], arr[0] = arr[i] - arr[0], arr[i] -= arr[0];
    }
}

void printArray(int (&arr)[N]) {
        for (int i = 0; i < N; ++i) {
        cout << arr[i] << ' ';
    }
}

int main() {
    int a[N] = {0};
    readArray(a);
    shiftArrayRight(a);
    printArray(a);
    return 0;
}