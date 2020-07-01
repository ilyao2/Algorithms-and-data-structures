#pragma once
template <class T>
class CircularSinglyLinkedList
{
protected:
	class Node
	{
	public:
		T item;
		Node* next;
		Node(T item)
		{
			this->item = item;
			next = nullptr;
		}
	};

	

	
private:
	int size;
	Node* root;
public:
	CircularSinglyLinkedList();
	CircularSinglyLinkedList(const CircularSinglyLinkedList<T>&);
	~CircularSinglyLinkedList();
	int getSize();
	bool clear();
	bool isEmpty();
	bool contains(T value);
	T& operator[](unsigned int index);
	int getIndex(T value);
	bool append(T value);
	bool append(T value, unsigned int index);
	bool eraseValue(T value);
	bool erase(unsigned int index);

	class Iterator
	{
	private:
		Node* cur;
	public:
		Iterator(Node* node)
		{
			cur = node;
		}

		T operator++(int)
		{
			T val = cur->item;
			cur = cur->next;
			return val;
		}
		T operator*()
		{
			return cur->item;
		}


		bool operator==(Iterator it)
		{
			return cur->item == *it;
		}
		bool operator!=(Iterator it)
		{
			return cur->item != *it;
		}
	};

	

	Iterator begin()
	{
		return Iterator(root);
	}
	Iterator end()
	{
		return Iterator(root);
	}

};

template<class T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList()
{
	size = 0;
	root = nullptr;
}

template<class T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList(const CircularSinglyLinkedList<T>& obj)
{
	obj.clear();
	for (int i = 0; i < size; i++)
	{
		obj.append(operator[](i));
	}
}

template<class T>
CircularSinglyLinkedList<T>::~CircularSinglyLinkedList()
{
	clear();
}

template<class T>
int CircularSinglyLinkedList<T>::getSize()
{
	return size;
}

template<class T>
bool CircularSinglyLinkedList<T>::clear()
{
	while(size != 0)
		erase(0);
	return true;
}

template<class T>
bool CircularSinglyLinkedList<T>::isEmpty()
{
	return (size == 0) ? true : false;
}

template<class T>
bool CircularSinglyLinkedList<T>::contains(T value)
{
	for (int i = 0; i < size; i++)
	{
		if (operator[](i) == value)
			return true;
	}
	return false;
}

template<class T>
T& CircularSinglyLinkedList<T>::operator[](unsigned int index)
{
	if (size == 0)
		throw ("CircularSinglyLinkedList is empty");
	if (index >= size)
		throw("Out of size");
	Node* temp = root;
	for (int i = 0; i < index; i++)
		temp = temp->next;
	return temp->item;
}

template<class T>
int CircularSinglyLinkedList<T>::getIndex(T value)
{
	for (int i = 0; i < size; i++)
	{
		if (operator[](i) == value)
			return i;
	}
	return -1;
}

template<class T>
bool CircularSinglyLinkedList<T>::append(T value)
{
	Node* item = new Node(value);
	if (size == 0)
	{
		root = new Node(value);
		root->next = root;
		size++;
		return true;
	}
	item->next = root;
	Node* temp = root;
	for (int i = 0; i < size-1; i++)
	{
		temp = temp->next;
	}
	temp->next = item;
	size++;
	return true;
}

template<class T>
bool CircularSinglyLinkedList<T>::append(T value, unsigned int index)
{
	if (index > size)
		throw("Out of size");
	if (index == size)
		return append(value);

	Node* temp = root;
	Node* item = new Node(value);
	if (index == 0)
	{
		item->next = root;
		for (int i = 0; i < size-1; i++)
		{
			temp = temp->next;
		}
		temp->next = item;
		root = item;
		size++;
		return true;
	}
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}
	item->next = temp->next;
	temp->next = item;
	size++;
	return true;
}


template<class T>
bool CircularSinglyLinkedList<T>::eraseValue(T value)
{
	if (size == 0)
		return false;
	Node* temp = root;
	for (int i = 0; i < size + 1; i++)
	{
		if (temp->next->item == value)
		{
			if (size == 1)
			{
				delete root;
				root = nullptr;
				size--;
				return true;
			}
			Node* dItem = temp->next;
			temp->next = dItem->next;
			if (dItem == root)
				root = dItem->next;
			delete dItem;
			dItem = nullptr;
			size--;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template<class T>
bool CircularSinglyLinkedList<T>::erase(unsigned int index)
{
	if (index >= size)
		throw("Out of size");
	Node* temp = root;


	if (size == 1)
	{
		delete root;
		root = nullptr;
		size--;
		return true;
	}


	if (index == 0)
	{
		for (int i = 0; i < size-1; i++)
		{
			temp = temp->next;
		}
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}
	}

	Node* dItem = temp->next;
	temp->next = dItem->next;
	if (index == 0)
		root = dItem->next;
	delete dItem;
	dItem = nullptr;
	size--;
	return true;
}


