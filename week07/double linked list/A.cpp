#include <iostream>

using std::cout;
using std::endl;

struct Node {
  int key = 0;
  Node* prev = nullptr;
  Node* next = nullptr;
};

struct List {
  size_t size = 0;
  Node* HEAD = nullptr;
  Node* TAIL = nullptr;
  Node* NIL = nullptr;
};

int main() {
  List* list = new List;
  if ((list->HEAD == nullptr) and (list->TAIL == nullptr) and (list->NIL == nullptr)) {
    cout << "OK" << endl;
  }
  list->HEAD = new Node;
  if ((list->HEAD->key == 0) and (list->HEAD->next == nullptr) and (list->HEAD->prev == nullptr)) {
    cout << "OK" << endl;
  }
  delete list->HEAD;
  delete list;
  return 0;
}