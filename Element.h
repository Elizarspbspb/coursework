#pragma once

using namespace std;
class Element  // ��������� ������
{
private:  // �������� ����������
	int size; // ������ �����
	int color; // ���� �����
public:
	Element();  // �����������
	~Element();  // ����������
	Element(int pn); // ����������� � ����������
	int get_size(); // ������� ��� �������� �������� �� private
	int get_color();
	void set_size(int k);  // ������� ��������� �������� �� private
	void set_color(int k);
};