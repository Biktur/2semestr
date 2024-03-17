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

List* push_back(List* list_ptr, int new_key) {
  if (list_ptr == nullptr) {
    return nullptr;
  }
  List *new_list = list_ptr;
  if (list_ptr->size != 0) {
    Node *new_element = new Node;
    new_element->key = new_key;
    new_element->prev = new_list->TAIL;
    new_element->next = new_list->NIL;
    new_list->TAIL->next = new_element;
    new_list->TAIL = new_element;
    ++new_list->size;
    return new_list;
  }
  new_list->HEAD = new Node;
  new_list->HEAD->key = new_key;
  new_list->HEAD->next = new_list->NIL;
  new_list->HEAD->prev = new_list->NIL;
  new_list->TAIL = new_list->HEAD;
  ++new_list->size;
  return new_list;
}

void print_list(const List* list_ptr) {
  if (list_ptr == nullptr) {
    std::cout << std::endl;
    return;
  }
  Node *current = list_ptr->HEAD;
  for (unsigned i = 1; i < list_ptr->size; ++i) {
    std::cout << current->key << ' ';
    current = current->next;
  }
  if (list_ptr->size != 0) {
    std::cout << current->key << std::endl; 
    return;
  }
  std::cout << std::endl;
}

int main() {
  List* list = create_empty_list();
  list = push_back(list, 0);
  print_list(list);
  delete list->HEAD;
  delete list->NIL;
  delete list;
  return 0;
}