#include<iostream>

char const * expand_string(char const * const src) {
    size_t initial_size = 1;
    size_t size = 1;
    while (src[initial_size - 1] != 0) {
        if (src[initial_size - 1] >= '0' and src[initial_size - 1] <= '9') {
            size += int(src[initial_size - 1]) - int('0') - 2;
        }
        ++size;
        ++initial_size;
    }
    char* string = new char[size];
    size_t gap = 0;
    for (size_t i = 0; i < initial_size; ++i) {
        if (src[i] > '0' and src[i] <= '9') {
            for (int j = 0; j < int(src[i]) - int('0') - 1; ++j) {
                string[i + j + gap] = src[i - 1];
            }
            gap += int(src[i]) - int('0') - 2;
            continue;
        }
        string[i + gap] = src[i];
    }
    return string;
}

int main() {
  char const *src = "ab2cc3d2e0";
  char const *expect = "abbccccdde0";
  char const *expanded = expand_string(src);
  for (int i = 0; i < 10; ++i) {
    std::cout << expanded[i] << ' ';
  }
  delete[] expanded;
}