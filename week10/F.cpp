#include<iostream>

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

Node* find(Node*& tree, int key) {
  if (tree == nullptr) {
    return tree;
  }
  Node* current = tree;
  while (current != nullptr) {
    if (current->key == key) {
      return current;
    }
    if (key > current->key) {
      current = current->right;
      continue;
    }
    current = current->left;
  }
  return nullptr;
}

Node* next(Node*& tree, int key) {
  if (tree == nullptr) {
    return tree;
  }
  Node* current = find(tree, key);
  if (current == nullptr) {
    return current;
  }
  if (current->right != nullptr) {
    current = current->right;
    while (current->left != nullptr) {
      current = current->left;
    }
    return current;
  }
  while (current->parent != nullptr) {
    if (current->parent->left == current) {
      return current->parent;
    }
    current = current->parent;
  }
  return nullptr;
}

int main() {
  Node* tree = nullptr;
  insert_node(tree, 1);
  insert_node(tree, 2);
  insert_node(tree, 0);
  insert_node(tree, -1);
  if (next(tree, 1) == tree->right and next(tree, -1) == tree->left and next(tree, 2) == nullptr) {
    std::cout << "OK" << std::endl;
  }
  delete tree->left->left;
  delete tree->left;
  delete tree->right;
  delete tree;
  return 0;
}