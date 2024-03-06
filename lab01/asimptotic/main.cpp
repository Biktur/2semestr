#include <iostream>
#include <fstream>  
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

long long int linear_search(long long int array[], long long int array_length, long long int number_to_find) { // Поиск прямым перебором
  for (int idx = 0; idx != array_length; ++idx) {
    if (array[idx] == number_to_find) {
      return idx;
    }
  }
  return -1;
}

long long int binary_search(long long int array[], long long int array_length, long long int number_to_find) { // Бинарный поиск
  long long int lborder = 0, rborder = array_length - 1;
  while (lborder <= rborder) {
    int middle =lborder + (rborder - lborder) / 2;
    if (array[middle] == number_to_find) {
      return middle;
    }
    if (array[middle] < number_to_find) {
      lborder = middle + 1;
    }
    if (array[middle] > number_to_find) {
      rborder = middle - 1;
    }
  }
  return -1;
}

long long int quadratic_sum(long long int array[], long long int array_length, long long int sum_to_find) { // Прямой перебор для находения элементов с заданной суммой
  for (int i = 0; i < array_length; ++i) {
    for (int j = 0; j < array_length; ++j) {
      if (i != j) {
        if (array[i] + array[j] == sum_to_find) {
          return;
        }
      }
    }
  }
  return;
}

long long int linear_sum(long long int array[], long long int array_length, long long int sum_to_find) { // Быстрый алгоритм для находения элементов с заданной суммой
  long long int lborder = 0, rborder = array_length - 1;
  while (lborder < rborder) {
    if (array[lborder] + array[rborder] == sum_to_find) {
      return;
    }
    if (array[lborder] + array[rborder] < sum_to_find) {
      ++lborder;
    }
    if (array[lborder] + array[rborder] > sum_to_find) {
      --rborder;
    }
  }
  return;
}

void strategy_A(long long int array[], long long int counters_array[], long long int index_found) { // Стратегия A
  if (index_found > 0) {
    std::swap(array[0], array[index_found]);
  }
}

void strategy_B(long long int array[], long long int counters_array[], long long int index_found) { // Стратегия B
  if (index_found > 0) {
    std::swap(array[index_found - 1], array[index_found]);
  }
}

void strategy_C(long long int array[], long long int counters_array[], long long int index_found){ // Стратегия C
  if (index_found != -1) {
    counters_array[index_found] += 1;
    if (index_found != 0){
      if (counters_array[index_found] > counters_array[index_found - 1]) {
        std::swap(counters_array[index_found], counters_array[index_found - 1]);
        std::swap(array[index_found], array[index_found - 1]);
      }
    }
  }
}

int measure_average_time(long long int (*func)(long long int[], long long int, long long int), long long int array[], int number_of_elements) {
  unsigned seed = 1001;
  std::default_random_engine rng(seed);
  std:uniform_int_distribution<long long int> dstr(1, number_of_elements);

  auto begin = std::chrono::steady_clock::now(); // Начинаем отсчет времени
  for (int counter = 0; counter < 100; ++counter) { // Запускаем счётчик
    int number_to_find = dstr(rng); // Берём случайный элемент массива
    func(array, number_of_elements, number_to_find); // Ищем его его нашей функцией
  }
  auto end = std::chrono::steady_clock::now(); // Останавливаем отсчет времени 
  auto time_span = std::chrono::duration_cast < std::chrono::microseconds > (end - begin);
  return time_span.count(); // Записываем в переменную полученное время
}

int measure_worst_posssible_time(long long int (*func)(long long int[], long long int, long long int), long long int array[], int number_of_elements) {
  auto begin = std::chrono::steady_clock::now(); // Начинаем отсчет времени
  for (int counter = 0; counter < 100; ++counter) { // Запускаем счётчик
    int number_to_find = number_of_elements + 1; // Берём элемент не лежащий в массиве
    func(array, number_of_elements, number_to_find); // Ищем его нашей функцией
  }
  auto end = std::chrono::steady_clock::now(); // Останавливаем отсчет времени 
  auto time_span = std::chrono::duration_cast < std::chrono::microseconds > (end - begin);
  return time_span.count(); // Записываем в переменную полученное время
}

int measure_uniform_time(void (*func)(long long int[], long long int[], long long int), int number_of_elements) {
  
  long long int *array = new long long int[number_of_elements]; // Инициализируем массив с заданным числом элементов
  long long int *counters_array = new long long int[number_of_elements]; // Инициализируем массив счётчиков
    for (long long int idx = 0; idx < number_of_elements; ++idx) { // Заполняем его
    array[idx] = idx + 1;
    counters_array[idx] = 0;
  }
  
  unsigned seed = 1001;
  std::default_random_engine rng(seed);
  std::uniform_int_distribution<long long int> dstr(1, number_of_elements); // Задаем равномерное распределение в диапазоне от 1 до кол-ва элементов
      
  auto begin = std::chrono::steady_clock::now(); // Запускаем отсчёт времени
  for (int counter = 0; counter < 1000; ++counter) { // Запускаем счетчик
    int number_to_find = dstr(rng); // Выбираем одно из значений распределенных равномерно
    func(array, counters_array, linear_search(array, number_of_elements, number_to_find)); // Применяем стратегию
  }
  auto end = std::chrono::steady_clock::now(); // Останавливаем отсчёт времени
  auto time_span = std::chrono::duration_cast < std::chrono::microseconds > (end - begin);

  delete[] array; // Очищаем память
  delete[] counters_array;

  return time_span.count(); // Возвращаем прошедшее время
}

int measure_binomial_time(void (*func)(long long int[], long long int[], long long int), int number_of_elements) {
  
  long long int *array = new long long int[number_of_elements]; // Инициализируем массив с заданным числом элементов
  long long int *counters_array = new long long int[number_of_elements]; // Инициализируем массив счётчиков
    for (long long int idx = 0; idx < number_of_elements; ++idx) { // Заполняем его
    array[idx] = idx + 1;
    counters_array[idx] = 0;
  }
  
  unsigned seed = 1001;
  std::default_random_engine rng(seed);
  std::uniform_int_distribution<long long int> dstr(1, number_of_elements); // Задаем равномерное распределение в диапазоне от 1 до кол-ва элементов
  std::binomial_distribution<long long int> bin_dstr(dstr(rng), dstr(rng)); //Задаем биномиальное распределение со случайнми параметрами
    
  auto begin = std::chrono::steady_clock::now(); // Запускаем отсчёт времени
  for (int counter = 0; counter < 1000; ++counter) { // Запускаем счетчик
    int number_to_find = bin_dstr(rng); // Выбираем одно из значений распределенных равномерно
    func(array, counters_array, linear_search(array, number_of_elements, number_to_find)); // Применяем стратегию
  }
  auto end = std::chrono::steady_clock::now(); // Останавливаем отсчёт времени
  auto time_span = std::chrono::duration_cast < std::chrono::microseconds > (end - begin);

  delete[] array; // Очищаем память
  delete[] counters_array;

  return time_span.count(); // Возвращаем прошедшее время
}

int main() {

  // Инициализирум переменнsые для записи в файл
  std::ofstream output_search;
  std::ofstream output_sum_of_two;
  std::ofstream output_frequently_used_element;

  unsigned seed = 1001;
  std::default_random_engine rng(seed);
  
  { // Локализуем переменную array
    output_search.open("search.csv"); // Открываем файл для первого задания 
    output_search << "number_of_elements," << "average_bin," << "average_lin," << "worst_possible_bin," << "worst_possible_lin" << '\n'; // Записываем в файл название столбцов

    long long int *array = new long long int[100000]; // Инициализирум массив
    for (long long int idx = 0; idx < 100000; ++idx) {
      array[idx] = idx + 1; // Заполняем массив натуральными числами
    }

    for (long long int number_of_elements = 100; number_of_elements <= 1000000; number_of_elements += 10) { // Пробегаемся по кол-ву элементов в массиве

      int average_bin = measure_average_time(binary_search, array, number_of_elements), average_lin = measure_average_time(linear_search, array, number_of_elements); // Записываем в переменную полученное время
      int worst_possible_bin = measure_worst_posssible_time(binary_search, array, number_of_elements), worst_possible_lin = measure_worst_posssible_time(linear_search, array, number_of_elements);

      output_search << number_of_elements << ',' << average_bin << ',' << average_lin << ',' << worst_possible_bin << ',' << worst_possible_lin << '\n'; // Записываем в строку файла кол-во элементов в массиве и полученное время
    }
    
    delete[] array; // Очищаем память
    output_search.close(); // Закрываем файл для первого задания
  }

  

  {  
    output_sum_of_two.open("sum_of_two.csv"); // Открываем файл для второго задания
    output_sum_of_two << "number_of_elements," << "quad_sum," << "lin_sum" << "\n"; // Записываем в него названия столбцов

    long long int *array = new long long int[10000];
    for (long long int idx = 0; idx < 10000; ++idx) {
      array[idx] = idx + 1; // Заполняем массив натуральными числами
    }

    for (long long int number_of_elements = 100; number_of_elements <= 10000; number_of_elements += 10) { // Пробегаемся по кол-ву элементов в массиве
      
      int quad_sum =  measure_average_time(quadratic_sum, array, number_of_elements), lin_sum = measure_average_time(linear_sum, array, number_of_elements);// Записываем в переменные прошедшее время
      
      output_sum_of_two << number_of_elements << ',' << quad_sum << ',' << lin_sum << "\n"; // Записываем в строку файла кол-во элементов в массиве и полученное время
    }

    delete[] array; // Очищаем память
    output_sum_of_two.close(); // Закрываем файл для второго задания
  }

  

  {
    output_frequently_used_element.open("frequently_used_element.csv"); // Открываем файл для третьего задания 
    output_frequently_used_element << "number_of_elements," << "A_uniform," << "B_uniform," << "C_uniform," << "A_binomial," << "B_binomial," << "C_binomial" << '\n'; // Записываем в него название столбцов

    for (long long int number_of_elements = 100; number_of_elements <= 100000; number_of_elements += 10) { // Пробегаемся по кол-ву элементов в массиве

      int A_uniform = measure_uniform_time(strategy_A, number_of_elements), B_uniform = measure_uniform_time(strategy_B, number_of_elements), C_uniform = measure_uniform_time(strategy_C, number_of_elements); // Записываем в переменную полученное время
      int A_binomial = measure_binomial_time(strategy_A, number_of_elements), B_binomial = measure_binomial_time(strategy_B, number_of_elements), C_binomial = measure_binomial_time(strategy_C, number_of_elements);

      output_frequently_used_element << number_of_elements << ',' << A_uniform << ',' << B_uniform << ',' << C_uniform << ',' << A_binomial << ',' << B_binomial << ',' << C_binomial << '\n'; // Записываем в строку файла кол-во элементов в массиве и полученное время
    }

    output_frequently_used_element.close(); // Закрываем файл для третьего задания
  }

  return 0; 
}