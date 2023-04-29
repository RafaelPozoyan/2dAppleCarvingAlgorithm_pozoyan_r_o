# 2dAppleCarvingAlgorithm_pozoyan_r_o
Курсовая Позоян Р.О. БПМ-22-4
# Суть поставленной задачи
Данный алгоритм нацелен на максимально рациональное решение ***задачи коммивояджера*** (`TSP`) - одной из самых известных задач комбинаторной оптимизации.  В общем виде нам
задан набор **городов и расстояние**, которое нужно пройти между
каждой парой из них, и тогда задача состоит в том, чтобы найти
кратчайший маршрут для посещения каждого города и возвращения в
**исходную точку**.

Задача коммивояжера применяется в логистике и навигаторах, так как она, собственно, и нацелена на вычисление наиболее рационального пути. А самым быстрым на данный момент является алгоритм **apple carving**.

![image](https://user-images.githubusercontent.com/114441417/234412415-f68b680a-ae8c-4df9-aa9a-cf3af424305e.png)

В общих чертах, планируется реализовать ``apple carving algorithm`` с поэтапной визуализацией посредством библиотеки ``OpenCV``
___

# Ход выполнения
1. На вход подается набор точек с координатами (x, y).`coursework_test.cpp` 

____

2. Производится триангуляция Делоне по точкам.

	* N-2 – количество треугольников;
	* N-3 – количество диагоналей, где N – количество точек. (городов)

![image](https://user-images.githubusercontent.com/114441417/235088195-26ce45de-0e0e-4a26-94e1-2c031b190224.png)

```Для триангуляции планируется использовать стороннюю библиотеку:```

*https://github.com/pkositsyn/delaunay-triangulation-algorithm

Производится визуализация при помощи библиотеки ``OpenCV``.

____

3. Вырезаются треугольники при помощи алгоритма **apple carving**.`applecarving.cpp`

![изображение](https://user-images.githubusercontent.com/114441417/234394583-3c641136-4d47-4482-bf03-452b2b0e2d31.png)

Производится визуализация при помощи библиотеки ``OpenCV``.

____

4. Производится проверка правильности вычислений:

	* Все города посещены только один раз;

	* Salesman по окончании тура оказался в той же точке, что и в начале.

____

# Структура файлов и папок
```
2d_apple_carving_algorithm_pozoyan_r_o
* coursework/
	* coursework.lab/
		* coursework/
			* coursework.hpp
		* applecarving.cpp
		* CMakeLists.txt	
	* coursework.test/
		* coursework_carving_test.cpp
		* CMakeLists.txt
	* CMakeLists.txt
```
