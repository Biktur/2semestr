#include <iostream>

struct Polynomial {
  int size = 0;
  int *polynomial = nullptr;
  Polynomial(int n, int *P) {
    size = n, polynomial = P;
  }
};

Polynomial input_polynomial(int* polynomial, int size) {
  polynomial = new int[size * 2];
  for (int i = 0; i < 2 * size; ++i) {
    std::cin >> polynomial[i]; 
  }
  return Polynomial(size, polynomial);
}

Polynomial multiply_polynomials(Polynomial P1, Polynomial P2) {
  int *ptr = new int[P1.size * P2.polynomial[0] + 1];
  for (int i = 0, i < P1[Polynomial])

}

int main() {
  int n1 = 0;
  std::cin >> n1;
  int *ptr1 = nullptr;
  Polynomial P1 = Polynomial(n1, ptr1);
  
  int n2 = 0;
  std::cin >> n2;
  int *ptr2 = nullptr;
  Polynomial P2 = Polynomial(n2, ptr2);
}