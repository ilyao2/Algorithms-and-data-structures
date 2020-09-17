#include <iostream>
#include "CircularSinglyLinkedList.h"

using namespace std;

int main()
{
	CircularSinglyLinkedList<int> list;
	int m0 = -1;
	
	while (m0 != 0)
	{

		int m1 = -1;
		system("cls");
		cout << "1 - CircularSinglyLinkedList\n"
			<< "0 - Exit\n";
		cin >> m0;
		switch (m0)
		{
		case 1:
			while (m1 != 0)
			{
				system("cls");
				cout << "1 - append value\n"
					<< "2 - appen value in index\n"
					<< "3 - erase by value\n"
					<< "4 - erase by index\n"
					<< "5 - clear\n"
					<< "6 - show\n"
					<< "7 - getByIndex\n"
					<< "8 - changeByIndex\n"
					<< "9 - getIndex\n"
					<< "10 - contains\n"
					<< "11 - getSize\n"
					<< "12 - isEmpty\n"
					<< "0 - Back\n";

				cin >> m1;
				int val;
				int index;
				CircularSinglyLinkedList<int>::Iterator it = list.begin();
				switch (m1)
				{

				case 1:
					system("cls");
					cout << "input value: ";
					cin >> val;
					system("cls");
					cout << list.append(val);
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "input value: ";
					cin >> val;
					cout << "input index: ";
					cin >> index;
					system("cls");
					cout << list.append(val, index);
					system("pause");
					break;
				case 3:
					system("cls");
					cout << "input value: ";
					cin >> val;
					system("cls");
					cout << list.eraseValue(val);
					system("pause");
					break;
				case 4:
					system("cls");
					cout << "input index: ";
					cin >> index;
					system("cls");
					cout << list.erase(index);
					system("pause");
					break;
				case 5:
					system("cls");
					cout << list.clear();
					system("pause");
					break;
				case 6:
					system("cls");
					for (int i = 0; i < list.getSize(); i++, cout << it++ << " ");
					cout << endl;
					system("pause");
					break;
				case 7:
					system("cls");
					cout << "input index: ";
					cin >> index;
					system("cls");
					try
					{
						cout << list[index] << endl;
					}
					catch (const std::exception&)
					{
						cout << "Bad index";
					}
					system("pause");
					break;
				case 8:
					system("cls");
					cout << "input value :";
					cin >> val;
					cout << "input index: ";
					cin >> index;
					try
					{
						list[index] = val;
					}
					catch (const std::exception&)
					{
						cout << "Bad index";
					}
					break;
				case 9:
					system("cls");
					cout << "input value: ";
					cin >> val;
					system("cls");
					cout << list.getIndex(val) << endl;
					system("pause");
					break;
				case 10:
					system("cls");
					cout << "input value: ";
					cin >> val;
					system("cls");
					cout << (list.contains(val) ? "true" : "false") << endl;
					system("pause");
					break;
				case 11:
					system("cls");
					cout << list.getSize() << endl;
					system("pause");
					break;
				case 12:
					system("cls");
					cout << (list.isEmpty() ? "true" : "false") << endl;
					system("pause");
					break;
				case 0:
					break;
				default:
					break;
				}

			}
		case 0:
			break;
		default:
			break;
		}
	}
	
	return 0;
}