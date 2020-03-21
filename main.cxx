#include "graphics.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>                     
#include <ctype.h>                     

#include <vector>
#include <windows.h>
#include "Ring.h"
using namespace std;

int main()
{
	int one = 0;
	cout << "Enter the number of disks: ";
	cin >> one;
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
		ring.draw(0, 10); // перекидывает курсор запроса ввода вывода
		cout << "From: "; // откуда переносим
		cin >> from; 
		cout << "To: "; // куда переносим
		cin >> to;
		if ((from == 1 || from == 2 || from == 3) || (to == 1 || to == 2 || to == 3)) 
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
				ring.showTowers();
				ring.draw(55, 12); // перекидывает курсор
				cout << "! WIN !" << endl;
				cout << "'Steps' = " << c << endl;
				break;
			}
		}
		else if (from == 9 || to == 9)
			break;
		else
		{
			cout << "!  Invalid input !" << endl;
			system("pause");
		}
	}
	system("pause");
	return 0;
}