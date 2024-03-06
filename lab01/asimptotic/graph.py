import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# Считываем файлы с результатми в виде DataFrame'ов
search = pd.read_csv(r"lab01\asimptotic\search.csv") 
sum_of_two = pd.read_csv(r"lab01\asimptotic\sum_of_two.csv")
frequently_used_element = pd.read_csv(r"lab01\asimptotic\frequently_used_element.csv")

# Создаем фигуры
fig_bin = plt.figure()
fig_lin = plt.figure()
fig_quad_sum = plt.figure()
fig_lin_sum = plt.figure()
fig_uniform = plt.figure()
fig_binomial = plt.figure()

# Создаем в них координатные плоскости
plt_bin = fig_bin.add_subplot()
plt_lin = fig_lin.add_subplot()
plt_quad_sum = fig_quad_sum.add_subplot()
plt_lin_sum = fig_lin_sum.add_subplot()
plt_uniform = fig_uniform.add_subplot()
plt_binomial = fig_binomial.add_subplot()

figures = [fig_bin, fig_lin, fig_quad_sum, fig_lin_sum, fig_uniform, fig_binomial]
plots = [plt_bin, plt_lin, plt_quad_sum, plt_lin_sum, plt_uniform, plt_binomial]

# Задаем точки
x = [[np.log(search["number_of_elements"]), np.log(search["number_of_elements"])], [search["number_of_elements"], search["number_of_elements"]], [sum_of_two["number_of_elements"] ** 2], [[sum_of_two["number_of_elements"]]], [frequently_used_element["number_of_elements"], frequently_used_element["number_of_elements"], frequently_used_element["number_of_elements"]], [frequently_used_element["number_of_elements"], frequently_used_element["number_of_elements"], frequently_used_element["number_of_elements"]]]
y= [[search["average_bin"], search["worst_possible_bin"]], [search["average_lin"], search["worst_possible_lin"]], [sum_of_two["quad_sum"]], [sum_of_two["lin_sum"]], [frequently_used_element["A_uniform"], frequently_used_element["B_uniform"], frequently_used_element["C_uniform"]], [frequently_used_element["A_binomial"], frequently_used_element["B_binomial"], frequently_used_element["C_binomial"]]]

# Задаем размерность осей
xmul = [1, 10 ** (-3), 10 ** (-6), 10 ** (-3), 10 ** (-3), 10 ** (-3)]
ymul = [1, 10 ** (-6), 10 ** (-6), 10 ** (-3), 10 ** (-3), 10 ** (-3)]

xlabel = [r"$\ln$(Number of elements)", r"Number of elements, $10^3$", r"(Number of elements)$^2$, $10^6$", r"Number of elements, $10^3$", r"Number of elements, $10^3$", r"Number of elements, $10^3$"]
ylabel = [r"Time passed, microseconds", r"Time passed, seconds", r"Time passed, seconds", r"Time passed, milliseconds", r"Time passed, milliseconds", r"Time passed, milliseconds"]

# Задаем обозначения тосек
labels = [["average", "worst"], ["average", "worst"], ["average"], ["average"], ["strategy_A", "strategy_B", "strategy_C"], ["strategy_A", "strategy_B", "strategy_C"]]

# Задаем пути для сохранения графиков
destination = [r"lab01\asimptotic\bin.png", r"lab01\asimptotic\lin.png", r"lab01\asimptotic\quad_sum.png", r"lab01\asimptotic\lin_sum.png", r"lab01\asimptotic\uniform.png", r"lab01\asimptotic\binomial.png"]

point_size = 3 # Задаем размер точек

colors = [['b', 'r'], ['b', 'r'], ['k'], ['k'], ['r', 'g', 'b'], ['r', 'g', 'b']] # Задаем цвет точек

for i in range(6):

  for j in range (len(x[i])):
    plots[i].scatter(np.array(x[i][j]) * xmul[i], np.array(y[i][j]) * ymul[i], point_size, colors[i][j], label = labels[i][j]) # Строим графики

  # Обозначаем оси
  plots[i].set_xlabel(xlabel[i])
  plots[i].set_ylabel(ylabel[i])

  # Размещаем легенду
  plots[i].legend(loc='upper left', shadow=True)

  # Сохраняем графики
  figures[i].savefig(destination[i])