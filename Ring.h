#pragma once
#include <vector>
#include <windows.h>
#include <ctime>
#include "Element.h"
using namespace std;

class Ring
{
private:
	int N; // ���������� �����
	vector <vector <Element>> towers;  // ��������� ������
	int x;  // ���������� ������ ���������� ������
	int y; // ���������� ���������� �� � �������
	int sx; // �������� ����� �������
public:
	void draw(int x, int y); // ��������� ������� �� �����������
	void showRing(Element elem, int x, int y); // ����� ������
	void setColor(int background, int text); // BACKGROUNd - ���� ����, TEXT - ���� �������
	Ring(); // ����������� �� ���������
	Ring(int pn); // ����������� � ����������
	~Ring(); // ����������
	Ring(const Ring &obj);    // ����������� ����� 
	void showTowers();  // ����� �����
	bool shiftDisk(int sour, int dest, int step); // �������� � ���������� ��������� � ������
	bool win();  // ������� ������
};
