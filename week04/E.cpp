#include <iostream>

using namespace std;

bool reserve_memory(size_t N, int *&dst) {
  if (dst == nullptr) {
      dst = new int[N];
      return true;
  }
  return false;
}

void free_memory(int *&ptr) {
  if (ptr != nullptr) {
    delete[] ptr;
  }
  ptr = nullptr;
}

int main() {
  int N = 0;
  int *ptr = nullptr;
  cin >> N;
  cout << reserve_memory(N, ptr) << endl;
  free_memory(ptr);
  return 0;
}