#include "Ring.h"

#include "graphics.h" // подключаем графическую бибилотеку
#include <iostream>
#include <math.h>
#include <stdlib.h>                     // Provides exit
#include <ctype.h>                      // Provides toupper

#include <vector>
#include <windows.h>
using namespace std;

void Ring::draw(int x, int y) // Функция помещает курсор текстового экрана в точку с координатами х,у
{
	COORD p = { x, y }; // структура
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p); // функция библиотеки windows.h
}

void Ring::showRing(Element elem, int x, int y) //
{
	draw(x + 1, y); // устанавливаем курсор
	setColor(WHITE, elem.get_color());  // установка цета
	for (int i = 0; i < elem.get_size(); i++) // вывод size символов
	{
		draw(x + i, y); // устанавливаем курсор
		cout << (char)219; // выбор формы дисков
	}
	setColor(WHITE, BLACK); // вернуть старый цвет
}

void Ring::setColor(int background, int text) // функция установки цвета
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text)); // библиотечная функция
}

Ring::Ring() // конструктор по умаолчанию
{
	N = 3;   // инициализация полей
	x = 15;
	y = 20;
	sx = 25;

	vector <Element> tower0;
	vector <Element> tower1;
	vector <Element> tower2;

	Element element; // объект класса
	element.set_size(10);
	element.set_color(1);
}

Ring::~Ring() // деструктор
{
	towers.clear();
	cout << "Destructor" << endl;
}

Ring::Ring(const Ring & obj) // конструктор копии
{
	Element *temp;                 //создаем указатель на структуру  
	vector <vector <Element>> Towers = obj.towers; // копирование 2-мер. вектора
	int N = N;
	int x = x;
	int y = y;
	int sx = sx;
}

Ring::Ring(int pn)
{
	N = pn;   // инициализация полей
	x = 15;
	y = 20;
	sx = 25;
	vector <Element> tower0;
	vector <Element> tower1;
	vector <Element> tower2;

	Element element;  // 1 объект класса
	element.set_size(15);  // заполнил поле размер
	element.set_color(1);  // выбрал цвет

	tower0.push_back(element);  // поместил в вектор объект класса (копию)
	tower1.push_back(element);  // 3 башни
	tower2.push_back(element);  // запись диска основания
	// помещается копия объекта следовательно можно менять параметры
	for (int i = N; i >= 1; i--)  // заполняем башню
	{
		element.set_size(i + 2); // указать размер
		element.set_color(i + 1); // указать цвет
		tower0.push_back(element); // добавление диска
	}

	towers.push_back(tower0);  // поместил в многомерный вектор одномерные вектора
	towers.push_back(tower1);
	towers.push_back(tower2);
}

void Ring::showTowers()  // вывод всех башен
{
	int lx = x;
	int ly = y;  // локальные переменные
	draw(lx, ly); // установить курсор начала отрисовки
	for (int i = 0; i < towers.size(); i++) // цикл по всем векторам - количесвто одномерных векторов в моем векторе
	{
		draw(lx + i, ly + i); // установить курсор начала отрисовки
		for (int j = 0; j < towers[i].size(); j++)  // внутри каждого вектора = кол-во дисков в векторе
		{
			draw(lx, ly); // установить курсор начала отрисовки
			showRing(towers[i][j], lx, ly); // вывод прямоугольных башен в координатах
			ly--;
		}
		ly = y;
		lx += sx;  // отрисоавть следующую башню левее
	}
}

bool Ring::shiftDisk(int from, int to, int step) // доб. удал. дисков
{
	Element element0; // создаются 2 объекта, которые принимают значения верхних дисков
	Element element1;
	from--;
	to--;
	element0 = towers[from][towers[from].size() - 1]; // находим размер вектора
	element1 = towers[to][towers[to].size() - 1]; // размер вектора

	if (element0.get_size() < element1.get_size()) // сравниваю размеры 
	{
		towers[from].pop_back(); // удалить последний элемент
		towers[to].push_back(element0); // добавить в конец (сверху) диск
		return true;
	}
	else
		return false;
}

bool Ring::win()  // функция победы
{
	if (towers[1].size() == N + 1 || towers[2].size() == N + 1) // если башня собралась на 2 или 3 стержне то победа
		return true;
	else
		return false;
}