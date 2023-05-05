# Решение задачи коммивояджера посредством алгоритма "Apple carving".
Курсовая Позоян Р.О. БПМ-22-4
# Суть поставленной задачи
Данный алгоритм нацелен на наиболее рациональное решение ***задачи коммивояджера*** (`TSP`) - одной из самых известных задач комбинаторной оптимизации.  В общем виде нам
дан набор **городов и расстояние**(***точек с координатами***), которое нужно пройти между
каждой парой из них, и тогда задача состоит в том, чтобы найти
кратчайший маршрут для посещения каждого города и возвращения в
**исходную точку**.

*https://en.wikipedia.org/wiki/Travelling_salesman_problem

Задача коммивояжера применяется в логистике и навигаторах, так как она, собственно, и нацелена на вычисление наиболее рационального пути. А самым быстрым на данный момент является алгоритм **apple carving**.

![image](https://user-images.githubusercontent.com/114441417/234412415-f68b680a-ae8c-4df9-aa9a-cf3af424305e.png)

В общих чертах, планируется реализовать ``apple carving algorithm`` с поэтапной визуализацией посредством библиотеки ``OpenCV``
___

# Ход выполнения
1. На вход подается набор точек с координатами (x, y) и параметры визуализации.

____

2. Совершается триангуляция Делоне по точкам.

	* N-2 – количество треугольников;
	* N-3 – количество диагоналей, где N – количество точек. (городов)

![image](https://user-images.githubusercontent.com/114441417/235088195-26ce45de-0e0e-4a26-94e1-2c031b190224.png)

```Для триангуляции планируется использовать стороннюю библиотеку:```

*https://www.geom.at/products/fade2d/

Производится визуализация данного этапа при помощи библиотеки ``OpenCV``.

____

3. Вырезаются треугольники при помощи алгоритма **apple carving**.

![изображение](https://user-images.githubusercontent.com/114441417/234394583-3c641136-4d47-4482-bf03-452b2b0e2d31.png)

Подробное описание данного алгоритма смотреть здесь:
*https://www.researchgate.net/publication/340401264_Apple_Carving_Algorithm_to_Approximate_Traveling_Salesman_Problem_from_Compact_Triangulation_of_Planar_Point_Sets

Производится визуализация данного этапа при помощи библиотеки ``OpenCV``.

____

4. Проверка правильности вычислений:

	* Все города посещены только один раз;

	* Salesman по окончании тура оказался в той же точке, что и в начале.

___

Реализация самого ***Apple carving algorithm*** и визуализация через ***OpenCV*** будут являться непосредственно частями библиотеки.
Входные данный будут подаваться в приложении. (Координаты точек и параметры визуализация)


