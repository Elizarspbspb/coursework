#include <iostream>
#include <math.h>
#include <stdlib.h>                     
#include <ctype.h>                     

#include <vector>
#include <windows.h>
#include "Ring.h"
#include <string>
using namespace std;
#define ERROR_400 400

int main()
{
	int one = 0;
	while ((one != 3) && (one != 4) && (one != 5) && (one != 6))
	{
		try
		{
			cout << "Enter the number of disks: ";
			cin >> one;
			if (cin.fail())
			{
				cin.clear();
				while (cin.get() != '\n');
				throw 1;
			}
			if (one > 6 || one < 3)
			{
				cin.clear();
				while (cin.get() != '\n');
				throw 2;
			}
		}
		catch (int i)
		{
			cout << "Error # " << i << endl;
			cout << "1 - Incorrect input" << endl;
			cout << "2 - Disks can be from 3 to 6 " << endl;
			cin.clear();
			system("pause");
		}
	}
	Ring ring(one);
	one = 0;
	int from = 0; // � ����� �����
	int to = 0; // �� ����� 
	int c = 0;  // ������� �����
	int i = 0;
	while (true)
	{
		system("cls");
		ring.draw(0, 2); // ������������ ������
		cout << "if you want to exit tap 9 in the FROM field and tap 9 in the TO field" << endl;
		cout << "'Steps' = " << c << endl;
		i++;
		ring.showTowers();  // ���������� �����
		ring.draw(0, 5); // ������������ ������ ������� ����� ������
		try
		{
			cout << "From: "; // ������ ���������
			cin >> from;
			if (cin.fail())
			{
				cin.clear();
				while (cin.get() != '\n');
				throw 2;
			}

			cout << "To: "; // ���� ���������
			cin >> to;
			if (cin.fail())
			{
				cin.clear();
				while (cin.get() != '\n');
				throw 3;
			}
			if ((from == 1 || from == 2 || from == 3) && (to == 1 || to == 2 || to == 3))
			{
				c++;
				if (!ring.shiftDisk(from, to, c)) // ���� �� ������� ����������� ����
				{
					cout << "/ ERROR \ - wrong size " << endl;
					c--;
					system("pause");
				}
				if (ring.win()) // �������� �� ������
				{
					system("cls");
					try
					{
						ring.showTowers();
					}
					catch (int error)
					{
						switch (error)
						{
						case ERROR_400:
							cout << endl << "\n ����� �� �������." << endl;
							break;
						default:
							cout << endl << "\n ����������� ������." << endl;
						}
					}
					try
					{
						ring.draw(55, 12); // ������������ ������
					}
					catch (int error) // ���� ����� �� ������� ����������
					{
						switch (error)
						{
						case ERROR_400:
							cout << endl << "\n ����������� ������� ����������." << endl;
							break;
						default:
							cout << endl << "\n ����������� ������." << endl;
						}
					}
					cout << "! WIN !" << endl;
					cout << "'Steps' = " << c << endl;
					break;
				}
			}
			else if (from == 9 || to == 9) // ����� �� ����
				break;
			else
				throw 1;
		}
		catch (int i)
		{
			cout << "Error # " << i << endl;
			cout << "1 - Error, non-existent pyramid" << endl;
			cout << "2 - Error, Incorrect input FROM " << endl;
			cout << "3 - Error, Incorrect input TO " << endl;
			cin.clear();
			system("pause");
		}
	}
	system("pause");
	return 0;
}