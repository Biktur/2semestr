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

List* create_empty_list() {
  List* list = new List;
  list->NIL = new Node;
  list->HEAD = list->NIL;
  list->TAIL = list->NIL;
  return list;
}

int main() {
  List* list = create_empty_list();
  if ((list->HEAD == list->NIL) and (list->TAIL == list->NIL) and (list->NIL != nullptr)) {
    cout << "OK" << endl;
  }
  delete list->NIL;
  delete list;
  return 0;
}