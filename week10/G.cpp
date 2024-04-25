#include<iostream>

enum TraverseType { INORDER, PREORDER, POSTORDER };

struct Node {
  int key = 0;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};

void insert_node(Node*& tree, int new_key) {
  if (tree == nullptr) {
    tree = new Node;
    tree->key = new_key;
    return;
  }
  Node* current = tree;
  while (true) {
    if (new_key > current->key) {
      if (current->right == nullptr) {
        Node* new_element = new Node;
        new_element->key = new_key;
        new_element->parent = current;
        current->right = new_element;
        return;
      }
      current = current->right;
      continue;
    }
    if (current->left == nullptr) {
      Node* new_element = new Node;
      new_element->key = new_key;
      new_element->parent = current;
      current->left = new_element;
      return;
    }
    current = current->left;
  }
}

void print_inorder(Node*& tree) {
  if (tree == nullptr) {
    return;
  }
  print_inorder(tree->left);
  std::cout << tree->key << ' ';
  print_inorder(tree->right);
}

void print_preorder(Node*& tree) {
  if (tree == nullptr) {
    return;
  }
  std::cout << tree->key << ' ';
  print_preorder(tree->left);
  print_preorder(tree->right);
}

void print_postorder(Node*& tree) {
  if (tree == nullptr) {
    return;
  }
  print_postorder(tree->left);
  print_postorder(tree->right);
  std::cout << tree->key << ' ';
}

void print(Node*& tree, const TraverseType type) {
  switch (static_cast<int>(type)) {
    case 0: print_inorder(tree);
      break;
    case 1: print_preorder(tree);
      break;
    case 2: print_postorder(tree);
      break;
  }
  std::cout << std::endl;
}

int main() {
  Node* tree = nullptr;
  insert_node(tree, 4);
  insert_node(tree, 2);
  insert_node(tree, 1);
  insert_node(tree, 6);
  insert_node(tree, 5);
  insert_node(tree, 7);
  print(tree, TraverseType::INORDER);    // 1 2 3 4 5 6 7
  print(tree, TraverseType::PREORDER);   // 4 2 1 3 6 5 7
  print(tree, TraverseType::POSTORDER);  // 1 3 2 5 7 6 4
  delete tree->left->left;
  delete tree->left->right;
  delete tree->left;
  delete tree->right->left;
  delete tree->right->right;
  delete tree->right;
  delete tree;
  return 0;
}