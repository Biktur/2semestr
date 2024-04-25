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

List* pushfront(List* list, int new_key) {
  if (list == nullptr) {
    return nullptr;
  }
  List* new_list = list;
  if (new_list->size == 0) {
    new_list->HEAD = new Node;
    new_list->HEAD->key = new_key;
    new_list->HEAD->next = new_list->NIL;
    new_list->TAIL = new_list->HEAD;
    ++new_list->size;
    return new_list;
  }
  Node* new_element = new Node;
  new_element->key = new_key;
  new_element->next = new_list->HEAD;
  new_list->HEAD = new_element;
  ++new_list->size;
  return new_list;
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
    std::cout << list->size << std::endl;
    return;
  }
  Node* current = list->HEAD;
  for (unsigned i = 0; i < list->size - 1; ++i) {
    std::cout << current->key << ' ';
    current = current->next;
  }
  std::cout << current->key << ' ' << list->size << std::endl;
}

List* copy_list(List* list) {
  if (list == nullptr) {
    return nullptr;
  }
  List* new_list = create_empty_list();
  Node* current = list->HEAD;
  for (unsigned i = 0; i < list->size; ++i) {
    new_list = pushback(new_list, current->key);
    current = current->next;
  }
  return new_list;
}

void qsort(int* array, int ind_left_base, int ind_right_base) {
  if (ind_left_base < ind_right_base) {
    int lborder = ind_left_base, rborder = ind_right_base;
    int mid_element = array[(lborder + rborder) / 2];
    while (1) {
      while (array[lborder] < mid_element) {
        ++lborder;
      }
      while (array[rborder] > mid_element) {
        --rborder;
      }
      if (lborder >= rborder) {
        break;
      }
      int temp = array[lborder];
      array[lborder] = array[rborder];
      array[rborder] = temp;
      ++lborder;
      --rborder;
    }
    qsort(array, ind_left_base, rborder);
    qsort(array, rborder + 1, ind_right_base);
  }
}

int main() {
  size_t N = 0;
  std::cin >> N;
  int* sequence = new int[N];
  int* temp = new int[N];
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> sequence[i];
    temp[i] = sequence[i];
  }
  qsort(temp, 0, N - 1);
  int* sorted_sequence = new int[N];
  sorted_sequence[0] = temp[0];
  size_t N1 = 1;
  for (unsigned i = 1; i < N; ++i)  {
    if (temp[i] != temp[i - 1]) {
      ++N1;
      sorted_sequence[N1 - 1] = temp[i];
    }
  }
  delete[] temp;
  List*** descending = new List**[N];
  long long** size = new long long*[N];
  for (unsigned i = 0; i < N; ++i) {
    descending[i] = new List*[N1];
    size[i] = new long long[N1];
    for (unsigned j = 0; j < N1; ++j) {
      if (i == 0 and j == 0) {
        if (sequence[i] == sorted_sequence[j]) {
          size[i][j] = 1;
          descending[i][j] = pushfront(create_empty_list(), sequence[i]);
          continue;
        }
        size[i][j] = 0;
        descending[i][j] = create_empty_list();
        continue;
      }
      if (i == 0) {
        if (sequence[i] == sorted_sequence[j]) {
          size[i][j] = 1;
          descending[i][j] = pushfront(create_empty_list(), sequence[i]);
          continue;
        }
        size[i][j] = size[i][j - 1];
        descending[i][j] = copy_list(descending[i][j - 1]);
        continue;
      }
      if (j == 0) {
        if (sequence[i] == sorted_sequence[j]) {
          size[i][j] = 1;
          descending[i][j] = pushfront(create_empty_list(), sequence[i]);
          continue;
        }
        size[i][j] = size[i - 1][j];
        descending[i][j] = copy_list(descending[i - 1][j]);
        continue;
      }
      if (sequence[i] == sorted_sequence[j]) {
        size[i][j] = size[i - 1][j - 1] + 1;
        descending[i][j] = pushfront(copy_list(descending[i - 1][j - 1]), sequence[i]);
        continue;
      }
      if (size[i - 1][j] >= size[i][j - 1]){
        size[i][j] = size[i - 1][j];
        descending[i][j] = copy_list(descending[i - 1][j]);
        continue;
      }
      size[i][j] = size[i][j - 1];
      descending[i][j] = copy_list(descending[i][j - 1]);
    }
  }
  print(descending[N - 1][N1 - 1]);
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N1; ++j) {
      destroy_list(descending[i][j]);
    }
    delete[] descending[i];
    delete[] size[i];
  }
  delete[] descending;
  delete[] size;
  delete[] sequence;
  delete[] sorted_sequence;
}