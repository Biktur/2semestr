#include<iostream>

int** read_incidence_matrix(size_t n_nodes, size_t n_edges) {
  int** matrix = new int*[n_nodes];
  for (size_t i = 0; i < n_nodes; ++i) {
    matrix[i] = new int[n_edges];
    for (size_t j = 0; j < n_edges; ++j) {
      std::cin >> matrix[i][j];
    }
  }
  return matrix;
}

int main() {
  size_t n_nodes = 0, n_edges = 0;
  int** incidence_matrix = nullptr;
  std::cin >> n_nodes >> n_edges;
  incidence_matrix = read_incidence_matrix(n_nodes, n_edges);
  for (size_t i = 0; i < n_nodes; ++i) {
    for (size_t j = 0; j < n_edges; ++j) {
      std::cout << incidence_matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  for (size_t i = 0; i < n_nodes; ++i) {  // Реализация удаления матрицы
    delete[] incidence_matrix[i];
  }
  delete[] incidence_matrix;
  return 0;
}