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
		Node(T item);
		~Node();
	};

	Node::Node(T item)
	{
		this->item = item;
	}

	Node::~Node()
	{
		delete next;
		next = nullptr;
	}
private:
	int size;
	bool isEmpty;
	Node* root;
	Node* current;
public:
	CircularSinglyLinkedList();
	CircularSinglyLinkedList(const CircularSinglyLinkedList<T>&);
	~CircularSinglyLinkedList();
	int getSize();
	bool clear();
	bool isEmpty();
	bool contains();
	T& operator[](int index);
	int getIndex(T value);
	bool append();
	bool append(int index);
	bool erase(T value);
	bool erase(int index);

	class Iterator
	{
	private:
		Node* cur;
	public:
		Iterator(Node*);
		T operator++();
		T operator--();
		bool operator==();
		bool operator!=();
	};

	Iterator::Iterator(Node* node)
	{
		cur = node;
	}

	Iterator begin();
	Iterator end();

};

