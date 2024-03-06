#include<iostream>

#define N 7

using namespace std;

void readArray(int (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void moveNegativeToEnd(int (&array)[N]) {
    for (int i = 1;  i < N; ++i){
        if (array[i] >= 0) {
            for (int j = i; j > 0; --j) {
                if (array[j - 1] >= 0) {
                    break;
                }
                array[j] += array[j-1], array[j-1] = array[j] - array[j-1], array[j] -= array[j-1];
            }
        }
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
    moveNegativeToEnd(a);
    printArray(a);
    return 0;
}