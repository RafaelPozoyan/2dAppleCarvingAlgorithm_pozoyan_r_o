# 2dAppleCarvingAlgorithm_pozoyan_r_o
Курсовая Позоян Р.О. БПМ-22-4
# Суть поставленной задачи
Данный алгоритм нацелен на максимально рациональное решение задачи коммивояджера (`TSP`) - одной из самых известных задач комбинаторной оптимизации.  В общем виде нам
задан набор городов и расстояние, которое нужно пройти между
каждой парой из них, и тогда задача состоит в том, чтобы найти
кратчайший маршрут для посещения каждого города и возвращения в
исходную точку.

![изображение](https://user-images.githubusercontent.com/114441417/234395580-63c766a5-365c-4b8f-b485-754c9fc9a0be.png)

# Ход выполнения
1. На вход подаются координаты городов в формате точек (x, y).`coursework_test.cpp` 

____

2. Производится триангуляция по точкам.`triangulation.cpp`

	* N-2 – количество треугольников;
	* N-3 – количество диагоналей, где N – количество точек (городов)


____

3. Вырезаются треугольники при помощи алгоритма обрезания яблока.`applecarving.cpp`
![изображение](https://user-images.githubusercontent.com/114441417/234394583-3c641136-4d47-4482-bf03-452b2b0e2d31.png)

____

4. Производится проверка правильности вычислений:

	* Кол-во посещенных городов меньше N;

	* Все города посещены только один;

	* Salesman по окончании тура оказался в той же точке, что и в начале.

____

5. Выводятся координаты посещенных городов и длина наиболее рационального маршрута.

# Структура файлов и папок

`2d_apple_carving_algorithm_pozoyan_r_o`
- coursework.lab
	- coursework
		- coursework.hpp
	- applecarving.cpp
	- triangulation.cpp
	- CMakeLists.txt	
- coursework.test
	- coursework_test.cpp
        - CMakeLists.txt
- CMakeLists.txt

