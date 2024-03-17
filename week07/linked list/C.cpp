#include <iostream>

using std::cout;
using std::endl; 

struct Node {
  int key = 0;
  Node *next = nullptr;
};

void push_back(Node*& head_ref, int new_key) {
  Node *current = head_ref;
  if (current != nullptr){
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new Node;
    current->next->key = new_key;
    current->next->next = nullptr;
    return;
  }
  head_ref = new Node;
  head_ref->key = new_key;
  head_ref->next = nullptr;
}

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
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