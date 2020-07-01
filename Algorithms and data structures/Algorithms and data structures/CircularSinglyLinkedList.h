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
		next = nullptr;
	}

	Node::~Node()
	{
		delete next;
		next = nullptr;
	}
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

