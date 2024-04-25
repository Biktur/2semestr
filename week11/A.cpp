#include<iostream>

int** read_adjacency_matrix(size_t n_nodes) {
  int** matrix = new int*[n_nodes];
  for (size_t i = 0; i < n_nodes; ++i) {
    matrix[i] = new int[n_nodes];
    for (size_t j = 0; j < n_nodes; ++j) {
      std::cin >> matrix[i][j];
    }
  }
  return matrix;
}

int main() {
  size_t n_nodes = 0;
  int** adjacency_matrix = nullptr;
  std::cin >> n_nodes;
  adjacency_matrix = read_adjacency_matrix(n_nodes);
  for (size_t i = 0; i < n_nodes; ++i) {
    for (size_t j = 0; j < n_nodes; ++j) {
      std::cout << adjacency_matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  for (size_t i = 0; i < n_nodes; ++i) {  // Реализация удаления матрицы
    delete[] adjacency_matrix[i];
  }
  delete[] adjacency_matrix;
  return 0;
}