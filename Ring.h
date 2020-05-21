#pragma once
#include <vector>
#include <windows.h>
#include <ctime>
#include "Element.h"
using namespace std;

class Ring
{
private:
	int N; // количесвто колец
	vector <vector <Element>> towers;  // двумерный вектор
	int x;  // определяет нижнюю координату начала
	int y; // определяет координату по у курсора
	int sx; // смещение между башнями
public:
	void draw(int x, int y); // установка курсора по координатам
	void showRing(Element elem, int x, int y); // вывод дисков
	void setColor(int background, int text); // BACKGROUNd - цвет фона, TEXT - цвет символа
	Ring(); // конструктор по умолчанию
	Ring(int pn); // конструктор с параметром
	~Ring(); // деструктор
	Ring(const Ring &obj);    // Конструктор копии 
	void showTowers();  // вывод башен
	bool shiftDisk(int sour, int dest, int step); // удаление и добавление элементов в вектор
	bool win();  // функция ПОБЕДЫ
};
