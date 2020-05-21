#pragma once

using namespace std;
class Element  // структура кольца
{
private:  // закрытые переменные
	int size; // размер диска
	int color; // цвет диска
public:
	Element();  // конструктор
	~Element();  // деструктор
	Element(int pn); // конструктор с параметром
	int get_size(); // функция для возврата значения из private
	int get_color();
	void set_size(int k);  // функция установки значения из private
	void set_color(int k);
};