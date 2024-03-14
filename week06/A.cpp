#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int mark;
};

void sort_by_name(Student students[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = i; j > 0; --j) {
      if (students[j].name < students[j-1].name) {
        Student temp = students[j];
        students[j] = students[j-1];
        students[j-1] = temp;
        continue;
      }
      if (students[j].name >= students[j-1].name) {
        break;
      }
    }
  }
}

void sort_by_mark(Student students[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = i; j > 0; --j) {
      if (students[j].mark < students[j-1].mark) {
        Student temp = students[j];
        students[j] = students[j-1];
        students[j-1] = temp;
        continue;
      }
      if (students[j].mark >= students[j-1].mark) {
        break;
      }
    }
  }
}

int main() {
  int N = 0;
  std::cin >> N;
  Student *students = new Student[N];
  for (int i = 0; i < N; ++i) {
    std::cin >> students[i].name >> students[i].mark;
  }
  int M = 0;
  std::cin >> M;
  sort_by_name(students, N);
  sort_by_mark(students, N);
  for (int i = 0; i < N; ++i) {
    if (students[i].mark > M) {
      std::cout << students[i].name << ' ';
    }
  }
}