#pragma once
#include <vector>
#include <iostream>
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

	bool clear(Node*& root);
	static T& getItemByKey(Node*& root, int key);
	bool append(Node*& root, int key, T val);
	bool erase(Node*& root, Node* parent, int key);
	void copy(Node* root);
	static void collectKeys(Node* root, std::vector<int>& keys);
	int getAfterkeyRecurs(Node* root, int key, bool& isFinded);
	void show(Node* root, int level);

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
	T getAfterkey(int val);
	void show();

	class Iterator
	{
	private:
		int cur;
		Node* root;
		std::vector<int> iterKeys;

	public:
		Iterator(Node* root)
		{
			collectKeys(root, iterKeys);
			cur = 0;
			if (root == nullptr) cur = -1;
			this->root = root;
		}

		T& operator++(int)
		{
			T& temp = getItemByKey(root, iterKeys[cur]);
			cur++;
			return temp;
		}
		T& operator--(int)
		{
			T& temp = getItemByKey(root, iterKeys[cur]);
			cur--;
			return temp;
		}
		T& operator*()
		{
			return getItemByKey(root, iterKeys[cur]);
		}


		bool operator==(Iterator it)
		{
			return cur == it.cur;
		}
		bool operator!=(Iterator it)
		{
			return cur != it.cur;
		}
	};

	Iterator begin()
	{
		return Iterator(root);
	}
	Iterator rBegin()
	{
		Iterator it(root);
		for (int i = 0; i < size-1; i++, it++);
		return it;
	}
	Iterator end()
	{
		Iterator it(root);
		for (int i = 0; i < size; i++, it++);
		return it;
	}
	Iterator rEnd()
	{
		Iterator it(root);
		it--;
		return it;
	}

};

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
	size = 0;
	root = nullptr;
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& obj)
{
	clear();
	copy(obj->root);
}
template<class T>
void BinarySearchTree<T>::copy(Node* root)
{
	if (root != nullptr)
	{
		append(root->key, root->val);
		copy(root->left);
		copy(root->right);
	}
}
template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	clear();
}

template<class T>
int BinarySearchTree<T>::getSize()
{
	return size;
}

template<class T>
bool BinarySearchTree<T>::clear()
{
	return clear(root);
}

template<class T>
inline bool BinarySearchTree<T>::clear(Node*& root)
{
	if (root != nullptr)
	{
		clear(root->left);
		clear(root->right);
		delete root;
		root = nullptr;
		size--;
	}
	return true;
}

template<class T>
bool BinarySearchTree<T>::isEmpty()
{
	return (root == nullptr) ? true : false;
}

template<class T>
T& BinarySearchTree<T>::operator[](int key)
{
	return getItemByKey(root, key);
}

template<class T>
T& BinarySearchTree<T>::getItemByKey(Node*& root, int key)
{
	if (root == nullptr)
	{
		throw std::exception("Unknowing key");
	}
	if (root->key == key) return root->item;

	if (key < root->key) return getItemByKey(root->left, key);
	if (key > root->key) return getItemByKey(root->right, key);

}

template<class T>
bool BinarySearchTree<T>::append(int key, T val)
{
	return append(root, key, val);
}

template<class T>
bool BinarySearchTree<T>::append(Node*& root, int key, T val)
{
	if (root == nullptr)
	{
		root = new Node(key, val);
		size++;
		return true;
	}

	if (root->key == key) return false;

	if (key < root->key) return append(root->left, key, val);
	if (key > root->key) return append(root->right, key, val);

	return false;
}

template<class T>
bool BinarySearchTree<T>::erase(int key)
{
	return erase(root, nullptr, key);
}

template<class T>
bool BinarySearchTree<T>::erase(Node*& root, Node* parent, int key)
{
	if (root == nullptr) return false;
	if (root->key == key)
	{
		Node* left = root->left;
		Node* right = root->right;

		delete root;
		root = nullptr;
		size--;

		if (left == nullptr && right == nullptr)
		{
		}
		else if (left == nullptr && right != nullptr)
		{
			if (parent == nullptr)
			{
				this->root = right;
			}
			else
			{
				if (right->key < parent->key)
					parent->left = right;
				else
					parent->right = right;
			}
		}
		else if (left != nullptr && right == nullptr)
		{
			if (parent == nullptr)
			{
				this->root = left;
			}
			else
			{
				if (left->key < parent->key)
					parent->left = left;
				else
					parent->right = left;
			}
		}
		else
		{
			if (right->left == nullptr)
			{

				right->left = left;
				if (parent == nullptr)
				{
					this->root = right;
				}
				else
				{

					if (right->key < parent->key)
						parent->left = right;
					else
						parent->right = right;
				}
			}
			else
			{
				Node* temp = right;
				while (temp->left->left != nullptr)
				{
					temp = temp->left;
				}
				Node* nRoot = temp->left;
				temp->left = nRoot->right;
				nRoot->right = right;
				nRoot->left = left;

				if (parent == nullptr)
				{
					this->root = nRoot;
				}
				else
				{
					if (nRoot->key < parent->key)
						parent->left = nRoot;
					else
						parent->right = nRoot;
				}
			}
		}

		return true;
	}
	if (key < root->key) return erase(root->left, root, key);
	if (key > root->key) return erase(root->right, root, key);

	return false;
}

template<class T>
std::vector<int> BinarySearchTree<T>::keys()
{
	std::vector<int> keys;
	collectKeys(root, keys);
	return keys;
}

template<class T>
void BinarySearchTree<T>::collectKeys(Node* root, std::vector<int>& keys)
{
	if (root != nullptr)
	{
		collectKeys(root->left, keys);
		keys.push_back(root->key);
		collectKeys(root->right, keys);
	}
}


template<class T>
T BinarySearchTree<T>::getAfterkey(int val)
{
	bool isFinded = false;
	int key = getAfterkeyRecurs(root, val, isFinded);
	if(!isFinded)
		throw std::exception("Unknowing key");
	return operator[](key);
}



template<class T>
int BinarySearchTree<T>::getAfterkeyRecurs(Node* root, int key, bool& isFinded)
{
	int result = 0;
	if (root == nullptr)
	{
		throw std::exception("Unknowing key");
	}
	if (root->left != nullptr)
		result = getAfterkeyRecurs(root->left, key, isFinded);
	if (isFinded)
		return result;
	if (root->key > key)
	{
		isFinded = true;
		return root->key;
	}
	if (root->right != nullptr)
		result = getAfterkeyRecurs(root->right, key, isFinded);
	return result;
}

template<class T>
void BinarySearchTree<T>::show()
{
	show(root, 0);
}

template<class T>
void BinarySearchTree<T>::show(Node* root, int level)
{
	if (root == nullptr)
		return;
	show(root->right, level + 1);
	for (int i = 0; i < 3 * level; i++)
		std::cout << " ";
	std::cout << root->key <<":"<< root->item << std::endl;
	show(root->left, level + 1);
}
