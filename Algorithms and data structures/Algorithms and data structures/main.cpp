#include <iostream>
#include "CircularSinglyLinkedList.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	CircularSinglyLinkedList<int> list;
	BinarySearchTree<int> tree;
	int m0 = -1;
	
	while (m0 != 0)
	{

		int m1 = -1;
		system("cls");
		cout << "1 - CircularSinglyLinkedList\n"
			<< "2 - BST\n"
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
			break;
		case 2:
			while (m1 != 0)
			{
				system("cls");
				cout << "1 - append value\n"
					<< "2 - erase\n"
					<< "3 - show\n"
					<< "4 - getAfterkey\n"
					<< "5 - size\n"
					<< "6 - isEmpty\n"
					<< "7 - keys\n"
					<< "8 - showByIndex\n"
					<< "9 - changeByIndex\n"
					<< "10 - clear\n"
					<< "0 - Back\n";

				cin >> m1;
				int key;
				int val;
				BinarySearchTree<int>::Iterator it = tree.begin();
				std::vector<int> keys;
				switch (m1)
				{
				case 1:
					system("cls");
					cout << "input key: ";
					cin >> key;
					system("cls");
					cout << "input value: ";
					cin >> val;
					system("cls");
					cout << tree.append(key, val) << endl;
					system("pause");
					break;
				case 2:
					system("cls");
					cout << "input key: ";
					cin >> key;
					system("cls");
					cout << tree.erase(key) << endl;
					system("pause");
					break;
				case 3:
					system("cls");
					keys = tree.keys();
					cout << "Key:Value\n";
					//for (std::vector<int>::iterator it = keys.begin(); it != keys.end(); cout << *it << ":" << tree[*it] << " ", it++);
					tree.show();
					cout << endl;
					system("pause");
					break;
				case 4:
					system("cls");
					cout << "input value: ";
					cin >> key;
					system("cls");
					try
					{
						cout << tree.getAfterkey(key);
					}
					catch (const std::exception&)
					{
						cout << "Bad key";
					}
					cout << endl;
					system("pause");
					break;
				case 5: 
					system("cls");
					cout << tree.getSize() << endl;
					system("pause");
					break;
				case 6:
					system("cls");
					cout << (tree.isEmpty()) ? "true" : "false";
					cout << endl;
					system("pause");
					break;
				case 7:
					system("cls");
					keys = tree.keys();
					for (std::vector<int>::iterator it = keys.begin(); it != keys.end(); cout << *it << " ", it++);
					cout << endl;
					system("pause");
					break;
				case 8:
					system("cls");
					cout << "input key: ";
					cin >> key;
					system("cls");
					try
					{
						cout << tree[key];
					}
					catch (const std::exception&)
					{
						cout << "Unknowing key";
					}
					cout << endl;
					system("pause");
					break;
				case 9:
					system("cls");
					cout << "input key: ";
					cin >> key;
					system("cls");
					cout << "input value: ";
					cin >> val;
					system("cls");
					try
					{
						tree[key] = val;
						cout << "true";
					}
					catch (const std::exception&)
					{
						cout << "Unknowing key";
					}
					cout << endl;
					system("pause");
					break;
				case 10:
					system("cls");
					cout << tree.clear() << endl;
					system("pause");
					break;
				case 0:
					break;
				default:
					break;
				}
			}
			break;
		case 0:
			break;
		default:
			break;
		}
	}
	
	return 0;
}

