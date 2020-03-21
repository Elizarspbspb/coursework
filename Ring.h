#pragma once
#include <vector>
#include <windows.h>
using namespace std;

struct Element  // структура кольца
{
	int size; // размер кольца
	int color; // цвет кольца
};
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
	void showRing(Element elem, int x, int y); 
	void setColor(int background, int text); // BACKGROUNd - цвет фона, TEXT - цвет символа
	Ring(); // конструктор по умолчанию
	Ring(int pn); // конструктор с параметром
	void showTowers();  
	bool shiftDisk(int sour, int dest, int step);
	bool win();  // функция ПОБЕДЫ
};