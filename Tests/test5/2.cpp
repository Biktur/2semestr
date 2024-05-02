#include <iostream>

int* merge_sorted(int const *first_begin, int const *first_end, int const *second_begin, int const *second_end) {
    size_t first_size = first_end - first_begin;
    size_t second_size = second_end - second_begin;
    if (first_size + second_size == 0) {
        return nullptr;
    }
    int* result = new int[first_size + second_size];
    size_t i = 0, j = 0;
    while (i + j < first_size + second_size) {
        if (i == first_size) {
            result[i + j] = second_begin[j];
            ++j;
            continue;
        }
        if (j == second_size) {
            result[i + j] = first_begin[i];
            ++i;
            continue;
        }
        if (first_begin[i] <= second_begin[j]) {
            result[i + j] = first_begin[i];
            ++i;
            continue;
        }
        result[i + j] = second_begin[j];
        ++j;
    }
  return result;
}

int main() {
    int const arr1[3] = {1, 2, 3};
    int const arr2[3] = {0, 2, 4};
    int const expected[6] = {0, 1, 2, 2, 3, 4};
    int *merged = merge_sorted(arr1, arr1 + 3, arr2, arr2 + 3);
    for (int i = 0; i < 6; ++i) {
      std::cout << merged[i] << ' ';
    }
    return 0;
}