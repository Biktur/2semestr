#include<iostream>

int main() {
  int banknotes[] = {1, 7, 28, 49, 63, 98};
  int M = 0;
  std::cin >> M;
  int counter = 0;
  for (int i = 5; i >= 0; --i) {
    counter += M / banknotes[i];
    M = M % banknotes[i];
  }
  std::cout << counter;
}