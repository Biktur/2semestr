#include<iostream>

struct Node {
  int key = 0;
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

List* pushback(List* list, int new_key) {
  if (list == nullptr) {
    return nullptr;
  }
  List* new_list = list;
  if (new_list->size == 0) {
    new_list->TAIL = new Node;
    new_list->TAIL->key = new_key;
    new_list->TAIL->next = new_list->NIL;
    new_list->HEAD = new_list->TAIL;
    ++new_list->size;
    return new_list;
  }
  Node* new_element = new Node;
  new_element->key = new_key;
  new_element->next = new_list->NIL;
  new_list->TAIL->next = new_element;
  new_list->TAIL = new_element;
  ++new_list->size;
  return new_list;
}

List* ordered_merge(List* list1, List* list2) {
  if ((list1 == nullptr) or (list1 == nullptr)) {
    return nullptr;
  }
  List* result = create_empty_list();
  unsigned counter1 = 0, counter2 = 0;
  Node* current1 = list1->HEAD;
  Node* current2 = list2->HEAD;
  while ((counter1 < list1->size) or (counter2 < list2->size)) {
    if (counter1 == list1->size) {
      result = pushback(result, current2->key);
      current2 = current2->next;
      ++counter2;
      continue;
    }
    if (counter2 == list2->size) {
      result = pushback(result, current1->key);
      current1 = current1->next;
      ++counter1;
      continue;
    }
    if (current1->key <= current2->key) {
      result = pushback(result, current1->key);
      current1 = current1->next;
      ++counter1;
      continue;
    }
    result = pushback(result, current2->key);
    current2 = current2->next;
    ++counter2;
  }
  return result;
}

void destroy_list(List*& list) {
  if (list == nullptr) {
    return;
  }
  Node* current = list->HEAD;
  for (unsigned i = 0; i < list->size; ++i) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  delete list->NIL;
  delete list;
  list = nullptr;
}

void print(List* list) {
  if (list == nullptr) {
    std::cout << std::endl;
    return;
  }
  if (list->size == 0) {
    std::cout << std::endl;
    return;
  }
  Node* current = list->HEAD;
  for (unsigned i = 0; i < list->size - 1; ++i) {
    std::cout << current->key << ' ';
    current = current->next;
  }
  std::cout << current->key << std::endl;
}

int main() {
  int n = 0;
  std::cin >> n;
  long long given_price[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  long long *max_income = new long long[n];
  List** optimal = new List*[n];
  for (int i = 0; i < n; ++i) {
    if (i < 10) {
      max_income[i] = given_price[i];
      optimal[i] = pushback(create_empty_list(), i + 1);
      continue;
    }
    max_income[i] = 0;
    optimal[i] = nullptr;
  }
  for (int length = 0; length < n; ++length) {
    for (int previous = 0; previous < length; ++previous) {
      if (max_income[length] >= max_income[previous] + max_income[length - previous - 1]) {
        continue;
      }
      max_income[length] = max_income[previous] + max_income[length - previous - 1];
      destroy_list(optimal[length]);
      optimal[length] = ordered_merge(optimal[previous], optimal[length - previous - 1]);
    }
  }
  print(optimal[n - 1]);
  for (int i = 0; i < n; ++i) {
    destroy_list(optimal[i]);
  }
  delete[] max_income;
  delete[] optimal;
} 