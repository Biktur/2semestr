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

int main() {
  Node* tree = nullptr;
  insert_node(tree, 1);
  insert_node(tree, 2);
  insert_node(tree, 0);
  if (find(tree, 1) == tree and find(tree, 2) == tree->right and find(tree, 0) == tree->left) {
    std::cout << "OK" << std::endl;
  }
  delete tree->left;
  delete tree->right;
  delete tree;
  return 0;
}

