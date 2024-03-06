#include <iostream>

using namespace std;

void printArray(int *ptr, int size) {
        for (int i = 0; i < size; ++i) {
        cout << ptr[i] << ' ';
    }
}

int main() {
  int *ptr_old = nullptr, *ptr_new = nullptr;
  int input = 0;
  int size = 0;
  while (1) {
    cin >> input;
    if (input == 0) {
      break;
    }
    ptr_old = ptr_new;
    ptr_new = new int[++size];
    for (int i = 0; i < size - 1; ++i) {
      ptr_new[i] = ptr_old[i];
    }
    ptr_new[size - 1] = input;
    delete[] ptr_old;
    ptr_old = nullptr;
  }
  printArray(ptr_new, size);
  delete[] ptr_new;
  return 0;
}