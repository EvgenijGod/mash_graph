## Задание 1 (2D игра)

Процесс сборки и запуск:

```shell
cmake .
make
cd bin
./main
```

Выполненные пункты:
* Анимация статических объектов - например, сокровища и шипы ловушек блестят.
(2 балла) - огонь


* Плавная спрайтовая анимация динамических объектов - походка игрока и врагов, открытие дверей и.т.д.
(от 2 до 5 баллов)

* Реализовать графический эффект перехода между уровнями (вариант А) и комнатами (вариант Б) - постепенное
 “угасание” и появление игровой карты (fade out / fade in), эффект “мозаики”, плавное “перетекание”
 одного изображения в другое и т.п.
(3 балла)

* Источники света - факелы, лампы и т.д., которые “освещают” (=изменяют цвет) соседних тайлов в некотором
 радиусе.
(4 балла)
анимация источников света
(+1 балл)

* Графическое отображение характеристик игрока и соответствующие им игровые механики - например, если
 выводится здоровье, то игрок может его потерять (ловушки, враги) и, возможно, восстановить.
(2 балла)

* Механика дальнего боя (стрелковое оружие и/или магия - огненные шары, волшебные стрелы и т.д.) с анимацией
 летящего снаряда.
(от 3 до 6 баллов в зависимости от субъективно оцениваемого визуального качества и сложности)

* Визуальные эффекты боя - “вылетающие” спрайты цифр повреждений, искры, “тряска” экрана и т.п.
(от 2 до 4 баллов) - красный экран повреждения

## Задание 2 (Ведьмин шар)

https://www.shadertoy.com/view/sslXRf

![](/task2.png)

