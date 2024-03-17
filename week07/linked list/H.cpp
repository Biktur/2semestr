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

void remove_key(Node*& head_ref, int key) {
  if (head_ref != nullptr) {
    Node *current = head_ref;
    if (head_ref->key == key) {
      Node* temp = head_ref;
      head_ref = head_ref->next;
      delete temp;
      return;
    }
    while (current->next != nullptr) {
      if (current->next->key == key) {
        if (current->next->next != nullptr) {
          Node *temp = current->next->next;
          delete current->next;
          current->next = temp;
          return;
        }
        delete current->next;
        current->next = nullptr;
        return;
      }
      current = current->next;
    }
  }
}

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  remove_key(HEAD, 0);
  remove_key(HEAD, 1);
  remove_key(HEAD, 2);
  remove_key(HEAD, 3);
  if (HEAD == nullptr) {
    cout << "OK" << endl;
  }
  return 0;
}