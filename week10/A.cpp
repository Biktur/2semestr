#include<iostream>

struct Node {
  int key = 0;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};

int main() {
  Node* tree = nullptr;
  tree = new Node;
  if ((tree->key == 0) and (tree->left == nullptr) and (tree->right == nullptr) and (tree->parent == nullptr)) {
    std::cout << "OK" << std::endl;
  } else {
    std::cout << std::endl;
  }
  delete tree;
  return 0;
}