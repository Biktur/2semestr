#include <iostream>

using std::cout;
using std::endl; 

struct Node {
  int key = 0;
  Node *next = nullptr;
};

void push_front(Node*& head_ref, int new_key) {
  Node* temp = head_ref;
  head_ref = new Node;
  head_ref->next = temp;
  head_ref->key = new_key;
}

int main() {
  Node* HEAD = nullptr;
  push_front(HEAD, 2);
  push_front(HEAD, 1);
  push_front(HEAD, 0);
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