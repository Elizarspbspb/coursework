#include "Ring.h"

#include "graphics.h"
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

void Ring::showRing(Element elem, int x, int y)
{
	draw(x+1, y); // устанавливаем курсор
	setColor(WHITE, elem.color);  // установка цета
	for (int i = 0; i < elem.size; i++) // вывод size символов
	{
		draw(x+i, y); // устанавливаем курсор
		cout << (char)219; // выбор формы прямоугольника
	}
	//draw(x + 10, y+10); // устанавливаем курсор
	setColor(WHITE, BLACK); // вернуть старый цвет
}

void Ring::setColor(int background, int text) // функция установки цвета
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
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

	Element element; // экземпляр структуры
	element.size = 10; // заполнил поле размер
	element.color = 0; // выбрал цвет
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

	Element element; // экземпляр структуры
	element.size = 15;  // заполнил поле размер
	element.color = 0;  // выбрал цвет

	tower0.push_back(element);  // поместил в вектор экземпляр структы (копию)
	tower1.push_back(element);  // 3 башни
	tower2.push_back(element);

	for (int i = N; i >= 1; i--)  // заполняем башню
	{
		//draw(i, i); // устанавливаем курсор 
		element.size = i+2;
		element.color = i + 1;
		tower0.push_back(element);
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
		draw(lx+i, ly+i); // установить курсор начала отрисовки
		for (int j = 0; j < towers[i].size(); j++)  // внутри каждого вектора = кол-во дисков в векторе
		{
			draw(lx, ly); // установить курсор начала отрисовки
			showRing(towers[i][j], lx, ly); // вывод прямоугольных башен в координатах
			ly--;
			//lx = lx + 1;
		}
		ly = y;
		lx += sx;  // отрисоавть следующую башню левее
	}
}

bool Ring::shiftDisk(int from, int to, int step)
{
	Element element0;
	Element element1;

	from--;
	to--;
	element0 = towers[from][towers[from].size() - 1];
	element1 = towers[to][towers[to].size() - 1];

	if (element0.size < element1.size) // сравниваю размеры 
	{
		towers[from].pop_back();
		towers[to].push_back(element0);
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
