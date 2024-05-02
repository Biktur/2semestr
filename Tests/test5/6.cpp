#include<iostream>

unsigned * count_ones(int n) {
    unsigned* array = new unsigned[n];
    int power = 1;
    array[0] = 0;
    for (size_t i = 0; i <= 30; ++i) {
        for (int j = 0; j < power; ++j) {
            if (power + j > n) {
                break;
            }
            array[power + j] = array[j] + 1;
        }
        power *= 2;
    }
    return array;
}

int main() {
  unsigned* array = count_ones(2);
  for (int i = 0; i < 3; ++i) {
    std::cout << array[i] << ' ';
  }
}