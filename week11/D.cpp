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

size_t most_common_node(int** incidence_matrix, size_t n_nodes, size_t n_edges) {
  size_t max = 0;
  size_t max_node = 0;
  for (size_t i = 0; i < n_nodes; ++i) {
    size_t counter = 0;
    for (size_t j = 0; j < n_edges; ++j) {
      counter += (incidence_matrix[i][j] != 0);
    }
    if (counter > max) {
      max_node = i;
      max = counter;
    }
  }
  return max_node;
}

int main() {
  size_t n_nodes = 0, n_edges = 0;
  int** incidence_matrix = nullptr;
  std::cin >> n_nodes >> n_edges;
  incidence_matrix = read_incidence_matrix(n_nodes, n_edges);
  std::cout << most_common_node(incidence_matrix, n_nodes, n_edges) << std::endl;
  for (size_t i = 0; i < n_nodes; ++i) {  // Реализация удаления матрицы
    delete[] incidence_matrix[i];
  }
  delete[] incidence_matrix;
  return 0;
}