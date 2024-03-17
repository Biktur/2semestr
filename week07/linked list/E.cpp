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

void destroy_list(Node*& head_ref) {
  if (head_ref != nullptr) {
    if (head_ref->next != nullptr) {
      Node *current = head_ref;
      while (current->next->next != nullptr) {
        current = current->next;
      }
      delete current->next;
      current->next = nullptr;
      destroy_list(head_ref);
      return;
    }
    delete head_ref;
    head_ref = nullptr;
  }
}

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  destroy_list(HEAD);
  if (HEAD == nullptr) {
    cout << "OK" << endl;
  }
  return 0;
}