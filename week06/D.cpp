#include <iostream>

struct Polynomial {
  int size = 0;
  int *polynomial = nullptr;
  Polynomial(int n) {
    size = n, polynomial = new int[n * 2];
  }
};

Polynomial input_polynomial(int size) {
  Polynomial P = Polynomial(size);
  for (int i = 0; i < 2 * size; ++i) {
    std::cin >> P.polynomial[i]; 
  }
  return P;
}

Polynomial multiply_polynomials(Polynomial P1, Polynomial P2) {
  Polynomial preresult = Polynomial(P1.size * P2.size);
  for (int i = 0; i < P1.size; ++i) {
    for (int j = 0; j < P2.size; ++j) {
      preresult.polynomial[(i * P2.size + j) * 2] = P1.polynomial[i * 2] * P2.polynomial[j * 2];
      preresult.polynomial[(i * P2.size + j) * 2 + 1] = P1.polynomial[i * 2 + 1] + P2.polynomial[j * 2 + 1];
    }
  }

  for (int i = preresult.size - 1; i >= 0; --i) {
    for (int j = i; j < preresult.size - 1; ++j) {
      if (preresult.polynomial[2 * j + 1] < preresult.polynomial[2 * j + 3]) {
        int temp_power = preresult.polynomial[2 * j + 1], temp_coefficient = preresult.polynomial[2 * j];
        preresult.polynomial[2 * j + 1] = preresult.polynomial[2 * j + 3], preresult.polynomial[2 * j] = preresult.polynomial[2 * j + 2];
        preresult.polynomial[2 * j + 3] = temp_power, preresult.polynomial[2 * j + 2] = temp_coefficient;
        continue;
      }
      if (preresult.polynomial[2 * j + 1] == preresult.polynomial[2 * j + 3]) {
        int temp_power = preresult.polynomial[2 * j + 1];
        preresult.polynomial[2 * j + 1] = preresult.polynomial[2 * j + 3];
        preresult.polynomial[2 * j + 3] = temp_power;
        preresult.polynomial[2 * j + 2] += preresult.polynomial[2 * j], preresult.polynomial[2 * j] = 0;
        continue;
      }
      break;
    }
  }
  int n_result = 0;
  for (int i = 0; i < preresult.size; ++i) {
    if (preresult.polynomial[2 * i] != 0) {
      ++n_result;
    }
  }
  Polynomial result = Polynomial(n_result);
  int result_idx = 0;
  for (int i = 0; i < preresult.size; ++i) {
    if (preresult.polynomial[2 * i] != 0) {
      result.polynomial[2 * result_idx + 1] = preresult.polynomial[2 * i + 1];
      result.polynomial[2 * result_idx] = preresult.polynomial[2 * i];
      ++result_idx;
    }
  }
  return result;
}

int main() {
  int n1 = 0;
  std::cin >> n1;
  Polynomial P1 = input_polynomial(n1);
  
  int n2 = 0;
  std::cin >> n2;
  Polynomial P2 = input_polynomial(n2);
  Polynomial P1P2 = multiply_polynomials(P1, P2);
  std::cout << P1P2.size << ' ';
  for (int i = 0; i < P1P2.size * 2; ++i) {
    std::cout << P1P2.polynomial[i] << ' ';
  }
}