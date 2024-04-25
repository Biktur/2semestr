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

bool check_adjacency_matrix(int** adjacency_matrix, size_t matrix_size) {
  for (size_t i = 0; i < matrix_size; ++i) {
    for (size_t j = 0; j < i; ++j) {
      if (adjacency_matrix[i][j] != adjacency_matrix[j][i]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  size_t n_nodes = 0;
  int** adjacency_matrix = nullptr;
  std::cin >> n_nodes;
  adjacency_matrix = read_adjacency_matrix(n_nodes);
  std::cout << check_adjacency_matrix(adjacency_matrix, n_nodes) << std::endl;
  for (size_t i = 0; i < n_nodes; ++i) {  // Реализация удаления матрицы
    delete[] adjacency_matrix[i];
  }
  delete[] adjacency_matrix;
  return 0;
}