#include<iostream>
#include <cassert>

struct Stack {
  size_t size = 0;
  int data[100];
};

Stack stack_new() {
  Stack new_stack;
  return new_stack;
}

bool stack_is_empty(Stack const &s) {
  return !(s.size);
}

bool stack_is_full(Stack const &s) {
  return (s.size == 100);
}

Stack& stack_push(Stack &s, int val) {
  if (s.size < 100) {
    s.data[s.size] = val;
    ++s.size;
  }
  return s;
}

int stack_pop(Stack &s) {
  if (s.size == 0) {
    return 0;
  }
  --s.size;
  return s.data[s.size];
}

int main() {
  Stack s = stack_new();
  for (unsigned cnt = 0; cnt != 100; ++cnt)
      stack_push(s, 1);
  Node* current = s.TAIL;
  for (int i = 0; i < 100; ++i) {
    std::cout << current->key << ' ';
    current = current->prev;
  }
  assert(true == stack_is_full(s));
}