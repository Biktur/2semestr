#include<iostream>

#define N 6

using namespace std;

void readArray(int (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void reverseArray(int (&arr)[N]) {
    for (int i = 0;  i < N / 2; ++i){
        arr[i] += arr[N - i - 1], arr[N - i - 1] = arr[i] - arr[N - i - 1], arr[i] -= arr[N - i - 1];
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
    reverseArray(a);
    printArray(a);
    return 0;
}