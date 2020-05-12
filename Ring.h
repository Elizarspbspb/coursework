#pragma once
#include <vector>
#include <windows.h>
#include <ctime>
using namespace std;

struct Element  // структура кольца
{
private :  // закрытые переменные
	int size; // размер диска
	int color; // цвет диска
public:
	int get_size() // функция для возврата значения из private
	{ 
		return size; 
	}  
	int get_color() 
	{ 
		return color; 
	}  
	void set_size(int k)  // функция установки значения из private
	{ 
		size = k; 
	}
	void set_color(int k) 
	{ 
		color = k; 
	}
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