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

Node* min(Node*& tree) {
  if (tree == nullptr) {
    return tree;
  }
  Node* current = tree;
  while (1) {
    if (current->left == nullptr) {
      return current;
    }
    current = current->left;
  }
}

void delete_node(Node*& tree, int key) {
  if (tree == nullptr) {
    return;
  }
  Node* element_to_delete = find(tree, key);
  if (element_to_delete == nullptr) {
    return;
  }
  if (element_to_delete->left == nullptr) {
    if (element_to_delete->right == nullptr) {
      if (element_to_delete->parent == nullptr) {
        tree = nullptr;
        delete element_to_delete;
        return;
      }
      if (element_to_delete->parent->right == element_to_delete) {
        element_to_delete->parent->right = element_to_delete->right;
        delete element_to_delete;
        return;
      }
      element_to_delete->parent->left = element_to_delete->right;
      delete element_to_delete;
      return;
    }
    element_to_delete->right->parent = element_to_delete->parent;
    if (element_to_delete->parent == nullptr) {
      tree = element_to_delete->right;
      delete element_to_delete;
      return;
    }
    if (element_to_delete->parent->right == element_to_delete) {
      element_to_delete->parent->right = element_to_delete->right;
      delete element_to_delete;
      return;
    }
    element_to_delete->parent->left = element_to_delete->right;
    delete element_to_delete;
    return;
  }
  if (element_to_delete->right == nullptr) {
    element_to_delete->left->parent = element_to_delete->parent;
    if (element_to_delete->parent == nullptr) {
      tree = element_to_delete->left;
      delete element_to_delete;
      return;
    }
    if (element_to_delete->parent->right == element_to_delete) {
      element_to_delete->parent->right = element_to_delete->left;
      delete element_to_delete;
      return;
    }
    element_to_delete->parent->left = element_to_delete->left;
    delete element_to_delete;
    return;
  }
  Node* root = min(element_to_delete->right);
  if (root->parent->left == root) {
    root->parent->left = nullptr;
  }
  else {
    root->parent->right = nullptr;
  }
  root->parent = element_to_delete->parent;
  root->left = element_to_delete->left;
  root->right = element_to_delete->right;
  element_to_delete->left->parent = root;
  if (element_to_delete->right != nullptr) {
    element_to_delete->right->parent = root;
  }
  if (element_to_delete->parent == nullptr) {
    tree = root;
    delete element_to_delete;
    return;
  }
  if (element_to_delete->parent->right == element_to_delete) {
    element_to_delete->parent->right = root;
    delete element_to_delete;
    return;
  }
  element_to_delete->parent->left = root;
  delete element_to_delete;
  return;
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
  print(tree, TraverseType::INORDER);
  insert_node(tree, 4);
  print(tree, TraverseType::INORDER);
  insert_node(tree, 2);
  print(tree, TraverseType::INORDER);
  insert_node(tree, 5);
  print(tree, TraverseType::INORDER);
  insert_node(tree, 6);
  print(tree, TraverseType::INORDER);
  insert_node(tree, 3);
  print(tree, TraverseType::INORDER);
  delete_node(tree, 3);
  print(tree, TraverseType::INORDER);
  delete_node(tree, 4);
  print(tree, TraverseType::INORDER);
  delete_node(tree, 2);
  print(tree, TraverseType::INORDER);
  delete_node(tree, 5);
  print(tree, TraverseType::INORDER);
  delete_node(tree, 6);
  print(tree, TraverseType::INORDER);
  if (!(tree->left) and !(tree->right)) {
    std::cout << "OK" << std::endl;
  }
  delete_node(tree, 4);
  return 0;
}