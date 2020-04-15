#include "graphics.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>                     
#include <ctype.h>                     

#include <vector>
#include <windows.h>
#include "Ring.h"

#include <string>
#include <fstream>
#include <sstream>
#include <exception> 
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
	int from = 0; // с какой башни
	int to = 0; // на какую 

	Element element0;
	Element element1;
	int c = 0;  // счетчик шагов
	int i = 0;
	while (true)
	{
		system("cls");
		ring.draw(0, 2); // перекидывает курсор
		cout << "if you want to exit tap 9 in the FROM field and tap 9 in the TO field" << endl;
		cout << "'Steps' = " << c << endl;
		i++;
		ring.showTowers();  // прорисовка башен
		ring.draw(0, 5); // перекидывает курсор запроса ввода вывода
		try
		{
			cout << "From: "; // откуда переносим
			cin >> from;
			if (cin.fail())
			{
				cin.clear();
				while (cin.get() != '\n');
				throw 2;
			}

			cout << "To: "; // куда переносим
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
				if (!ring.shiftDisk(from, to, c)) // если не удалось переместить диск
				{
					cout << "/ ERROR \ - wrong size " << endl;
					c--;
					system("pause");
				}
				if (ring.win())
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
							cout << endl << "\n Башни не найдены." << endl;
							break;
						default:
							cout << endl << "\n Неизвестная ошибка." << endl;
						}
					}
					try
					{
						ring.draw(55, 12); // перекидывает курсор
					}
					catch (int error)
					{
						switch (error)
						{
						case ERROR_400:
							cout << endl << "\n Передвинуть курсоср невозможно." << endl;
							break;
						default:
							cout << endl << "\n Неизвестная ошибка." << endl;
						}
					}
					cout << "! WIN !" << endl;
					cout << "'Steps' = " << c << endl;
					break;
				}
			}
			else if (from == 9 || to == 9)
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