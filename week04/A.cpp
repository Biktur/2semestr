#include <iostream>

void func(int *array, int n) {
  array[0] = 2;
}

using namespace std;

int main() {
  double *ptr = new double;
  cout << ptr << ' ' << *ptr << endl;
  *ptr =  0;
  cout << ptr << ' ' << *ptr << endl;
  ptr -= 3;
  cout << ptr << ' ' << *ptr << endl;
  ptr += 5;
  cout << ptr << ' ' << *ptr << endl;

  return 0;
}