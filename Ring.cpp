#include "Ring.h"

#include "graphics.h" // ���������� ����������� ����������
#include <iostream>
#include <math.h>
#include <stdlib.h>                     // Provides exit
#include <ctype.h>                      // Provides toupper

#include <vector>
#include <windows.h>
using namespace std;

void Ring::draw(int x, int y) // ������� �������� ������ ���������� ������ � ����� � ������������ �,�
{
	COORD p = { x, y }; // ���������
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p); // ������� ���������� windows.h
}

void Ring::showRing(Element elem, int x, int y) //
{
	draw(x + 1, y); // ������������� ������
	setColor(WHITE, elem.get_color());  // ��������� ����
	for (int i = 0; i < elem.get_size(); i++) // ����� size ��������
	{
		draw(x + i, y); // ������������� ������
		cout << (char)219; // ����� ����� ������
	}
	setColor(WHITE, BLACK); // ������� ������ ����
}

void Ring::setColor(int background, int text) // ������� ��������� �����
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text)); // ������������ �������
}

Ring::Ring() // ����������� �� ����������
{
	N = 3;   // ������������� �����
	x = 15;
	y = 20;
	sx = 25;

	vector <Element> tower0;
	vector <Element> tower1;
	vector <Element> tower2;

	Element element; // ������ ������
	element.set_size(10);
	element.set_color(1);
}

Ring::~Ring() // ����������
{
	towers.clear();
	cout << "Destructor" << endl;
}

Ring::Ring(const Ring & obj) // ����������� �����
{
	Element *temp;                 //������� ��������� �� ���������  
	vector <vector <Element>> Towers = obj.towers; // ����������� 2-���. �������
	int N = N;
	int x = x;
	int y = y;
	int sx = sx;
}

Ring::Ring(int pn)
{
	N = pn;   // ������������� �����
	x = 15;
	y = 20;
	sx = 25;
	vector <Element> tower0;
	vector <Element> tower1;
	vector <Element> tower2;

	Element element;  // 1 ������ ������
	element.set_size(15);  // �������� ���� ������
	element.set_color(1);  // ������ ����

	tower0.push_back(element);  // �������� � ������ ������ ������ (�����)
	tower1.push_back(element);  // 3 �����
	tower2.push_back(element);  // ������ ����� ���������
	// ���������� ����� ������� ������������� ����� ������ ���������
	for (int i = N; i >= 1; i--)  // ��������� �����
	{
		element.set_size(i + 2); // ������� ������
		element.set_color(i + 1); // ������� ����
		tower0.push_back(element); // ���������� �����
	}

	towers.push_back(tower0);  // �������� � ����������� ������ ���������� �������
	towers.push_back(tower1);
	towers.push_back(tower2);
}

void Ring::showTowers()  // ����� ���� �����
{
	int lx = x;
	int ly = y;  // ��������� ����������
	draw(lx, ly); // ���������� ������ ������ ���������
	for (int i = 0; i < towers.size(); i++) // ���� �� ���� �������� - ���������� ���������� �������� � ���� �������
	{
		draw(lx + i, ly + i); // ���������� ������ ������ ���������
		for (int j = 0; j < towers[i].size(); j++)  // ������ ������� ������� = ���-�� ������ � �������
		{
			draw(lx, ly); // ���������� ������ ������ ���������
			showRing(towers[i][j], lx, ly); // ����� ������������� ����� � �����������
			ly--;
		}
		ly = y;
		lx += sx;  // ���������� ��������� ����� �����
	}
}

bool Ring::shiftDisk(int from, int to, int step) // ���. ����. ������
{
	Element element0; // ��������� 2 �������, ������� ��������� �������� ������� ������
	Element element1;
	from--;
	to--;
	element0 = towers[from][towers[from].size() - 1]; // ������� ������ �������
	element1 = towers[to][towers[to].size() - 1]; // ������ �������

	if (element0.get_size() < element1.get_size()) // ��������� ������� 
	{
		towers[from].pop_back(); // ������� ��������� �������
		towers[to].push_back(element0); // �������� � ����� (������) ����
		return true;
	}
	else
		return false;
}

bool Ring::win()  // ������� ������
{
	if (towers[1].size() == N + 1 || towers[2].size() == N + 1) // ���� ����� ��������� �� 2 ��� 3 ������� �� ������
		return true;
	else
		return false;
}