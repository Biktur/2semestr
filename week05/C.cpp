#include <iostream>
#include <algorithm>

#define N 12

using namespace std;

void readArray(int (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void printArray(int (&arr)[N]) {
  for (int i = 0; i < N; ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

void heapify(int (&array)[N], int root, int heap_size) {
  int lchild = 2 * root, rchild = 2 * root + 1, largest = root;
  if (array[lchild] > array[largest] and lchild < heap_size) {
    largest = lchild;
  }
  if (array[rchild] > array[largest] and rchild < heap_size) {
    largest = rchild;
  }
  if (largest != root) {
    std::swap(array[root], array[largest]);
    heapify(array, largest, heap_size);
  }
}

void heap_sort(int (&array)[N]) {
  for (int i = N / 2 - 1; i >= 0; --i) {
    heapify(array, i, N);
  } 
  int heap_size = N;
  for (int i = N - 1; i > 0; --i) {
    std::swap(array[i], array[0]);
    heapify(array, 0, --heap_size);
  } 
}

int main() {
  int array[N] = {0};
  readArray(array);
  heap_sort(array);
  printArray(array);
}