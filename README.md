# 2dAppleCarvingAlgorithm_pozoyan_r_o

1.На вход подаются координаты городов в формате точек (x, y). (coursework_test.cpp)

2.Производится триангуляция по точкам. (triangulation.cpp)

	N-2 – количество треугольников;

	N-3 – количество диагоналей, где N – количество точек (городов)


3.Вырезаются треугольники при помощи алгоритма обрезания яблока. (applecarving.cpp)


4.Производится проверка правильности вычислений:

 	·Кол-во посещенных городов меньше N;

 	·Все города посещены только один;

 	·Salesman по окончании тура оказался в той же точке, что и в начале.
  




5. Выводятся координаты посещенных городов и длина наиболее рационального маршрута.
