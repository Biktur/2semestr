#include <iostream>

using std::cout;
using std::endl; 

struct Node {
  int key = 0;
  Node *next = nullptr;
};

void insert_after(Node*& prev_ref, int new_key) {
  if (prev_ref->next == nullptr) {
    prev_ref->next = new Node;
    prev_ref->next->key = new_key;
    prev_ref->next->next = nullptr;
    return;
  }
  Node* new_node = new Node;
  new_node->next = prev_ref->next;
  new_node->key = new_key;
  prev_ref->next = new_node;
}


int main() {
  Node* HEAD = new Node;
  insert_after(HEAD, 0);
  insert_after(HEAD, 1);
  insert_after(HEAD, 2);
  Node* ptr = HEAD;
  while (ptr->next != nullptr) {
    cout << ptr->key << ' ';
    ptr = ptr->next;
  }
  cout << ptr->key << endl;
  ptr = HEAD;
  while (ptr->next != nullptr) {
    ptr = HEAD->next;
    delete HEAD;
    HEAD = ptr;
  }
  delete HEAD;
  return 0;
}