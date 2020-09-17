#pragma once
#include <vector>
template <class T>
class BinarySearchTree
{
protected:
	static class Node
	{
	public:
		T item;
		int key;
		Node* left;
		Node* right;
		Node(int key, T item)
		{
			this->item = item;
			this->key = key;
			left = nullptr;
			right = nullptr;
		}
	};
private:
	int size;
	Node* root;
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T>&);
	~BinarySearchTree();
	int getSize();
	bool clear();
	bool isEmpty();
	T& operator[](int key);
	bool append(int key, T val);
	bool erase(int key);
	std::vector<int> keys();
	T& getAfterkey(int val);

	class Iterator
	{
	private:
		Node* cur;

	public:
		Iterator(Node* node)
		{
			cur = node;
		}

		//TODO: functions;
		T& operator++(int)
		{
			
		}
		T& operator--(int)
		{

		}
		T& operator*()
		{
			
		}


		bool operator==(Iterator it)
		{
			
		}
		bool operator!=(Iterator it)
		{
			
		}
	};

	Iterator begin();
	Iterator rBegin();
	Iterator end();
	Iterator rEnd();

};
