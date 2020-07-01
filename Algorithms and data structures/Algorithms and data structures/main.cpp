#include <iostream>
#include "CircularSinglyLinkedList.h"

using namespace std;

int main()
{
	CircularSinglyLinkedList<int> list;

	list.append(1);
	list.append(2);
	list.append(3);
	cout << (list[2]) << endl;
	list[2] = 5;
	cout << (list[2]) << endl;
	CircularSinglyLinkedList<int>::Iterator it = list.begin();
	for (int i = 0; i < list.getSize(); cout << it++ << " ", i++);
	return 0;
}