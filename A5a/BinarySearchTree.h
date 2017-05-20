//===============================================================
// * Program Name: Assignnment 5
// * Author: Victor Soriano Mendoza
// * Date Written: 05/10/2017
// * Description: Binary Search Tree with basic functionality
//===============================================================
#pragma once
#include <string>
#include <iostream>
#include <functional>

using namespace std;

struct TreeNode
{
	string data;
	TreeNode* left;
	TreeNode* right;
};

class BinarySearchTree
{
private:
	TreeNode* root;
	TreeNode* getRoot();
	void traverseInOrder(TreeNode* root);
	void traversePreOrder(TreeNode* root);
	void traversePostOrder(TreeNode* root);
	void deleteFromTree(TreeNode* &p);
	void traverseInOrderFuncPtr(TreeNode* root, const function<void(TreeNode*, int)> &printFunction, int nodeLevel = 0);
	void traversePostOrderFuncPtr(TreeNode* root, const function<void(TreeNode*, int)> &printFunction, int nodeLevel = 0);
	void traversePreOrderFuncPtr(TreeNode* root, const function<void(TreeNode*, int)> &printFunction, int nodeLevel = 0);

public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(string newData);
	void printInOrder();
	void printPreOrder();
	void printPostOrder();
	void batchInsert(string data[]);
	void deleteNode(const string deleteItem);
	static void genericPrint(TreeNode* root, int nodeLevel);
	void printInOrderUsingFunctionPointer();
	void printPostOrderUsingFunctionPointer();
	void printPreOrderUsingFunctionPointer();





};


void BinarySearchTree::batchInsert(string data[])
{
	for (int i = 0; i < 12; i++)
	{
		insert(data[i]);
	}
}

inline void BinarySearchTree::deleteNode(const string deleteItem)
{
	TreeNode* current;
	TreeNode* trailCurrent;
	bool found = false;

	if (root == nullptr)
	{
		return;
	}

	else
	{
		current = root;
		trailCurrent = root;

		while (current != nullptr && !found)
		{
			if (current->data == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;

				if (current->data > deleteItem)
					current = current->left;
				else
					current = current->right;
			}
		}
		
		if (current == nullptr)
			return;
		else if (found)
		{
			if (current == root)
				deleteFromTree(root);
			else if (trailCurrent->data > deleteItem)
				deleteFromTree(trailCurrent->left);
			else
				deleteFromTree(trailCurrent->right);
		}
		else
			return;
	}
}

inline void BinarySearchTree::genericPrint(TreeNode * root, int nodeLevel)
{
	cout << root->data << "(" << nodeLevel << ")" << " ";
}

inline void BinarySearchTree::printInOrderUsingFunctionPointer()
{
	traverseInOrderFuncPtr(root, genericPrint);
}

inline void BinarySearchTree::printPostOrderUsingFunctionPointer()
{
	traversePostOrderFuncPtr(root, genericPrint);
}

inline void BinarySearchTree::printPreOrderUsingFunctionPointer()
{
	traversePreOrderFuncPtr(root, genericPrint);
}


TreeNode* BinarySearchTree::getRoot()
{
	return root;
}


void BinarySearchTree::traverseInOrder(TreeNode* root)
{
	if (root != nullptr)
	{
		traverseInOrder(root->left);
		cout << root->data << " ";
		traverseInOrder(root->right);
	}
}

void BinarySearchTree::traversePreOrder(TreeNode* root)
{
	if (root != nullptr)
	{
		cout << root->data << " ";
		traversePreOrder(root->left);
		traversePreOrder(root->right);
	}
}

void BinarySearchTree::traversePostOrder(TreeNode* root)
{
	if (root != nullptr)
	{
		traversePostOrder(root->left);
		traversePostOrder(root->right);
		cout << root->data << " ";
	}
}

inline void BinarySearchTree::deleteFromTree(TreeNode *& p)
{
	TreeNode* current;
	TreeNode* trailCurrent;
	TreeNode* temp;

	if (p == nullptr)
		return;

	else if (p->left == nullptr && p->right == nullptr)
	{
		temp = p;
		p = nullptr;
		delete temp;
	}

	else if (p->left == nullptr)
	{
		temp = p;
		p = temp->right;
		delete temp;
	}

	else if (p->right == nullptr)
	{
		temp = p;
		p = temp->left;
		delete temp;
	}

	else
	{
		current = p->left;
		trailCurrent = nullptr;

		while (current->right != nullptr)
		{
			trailCurrent = current;
			current = current->right;
		}

		p->data = current->data;

		if (trailCurrent == nullptr)
			p->left = current->left;
		else
			trailCurrent->right = current->left;

		delete current;
	}
}

inline void BinarySearchTree::traverseInOrderFuncPtr(TreeNode * root, const function<void(TreeNode*, int)>& printFunction, int nodeLevel)
{
	if (root != nullptr)
	{
		traverseInOrderFuncPtr(root->left, printFunction, ++nodeLevel);
		printFunction(root, --nodeLevel);
		traverseInOrderFuncPtr(root->right, printFunction, ++nodeLevel);
	}
}

inline void BinarySearchTree::traversePostOrderFuncPtr(TreeNode * root, const function<void(TreeNode*, int)>& printFunction, int nodeLevel)
{
	if (root != nullptr)
	{
		traversePostOrderFuncPtr(root->left, printFunction, ++nodeLevel);
		traversePostOrderFuncPtr(root->right, printFunction, nodeLevel);
		printFunction(root, --nodeLevel);
	}
}

inline void BinarySearchTree::traversePreOrderFuncPtr(TreeNode * root, const function<void(TreeNode*, int)>& printFunction, int nodeLevel)
{
	if (root != nullptr)
	{
		printFunction(root, nodeLevel);
		traversePreOrderFuncPtr(root->left, printFunction, ++nodeLevel);
		traversePreOrderFuncPtr(root->right, printFunction, nodeLevel);
	}
}

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

inline BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::insert(string newData)
{
	TreeNode* current = root;
	TreeNode* currentTrail = current;
	TreeNode* newNode = new TreeNode;

	newNode->data = newData;
	newNode->left = nullptr;
	newNode->right = nullptr;

	if (root == nullptr)
		root = newNode;
	else
	{
		while (current != nullptr)
		{
			currentTrail = current;
			if (current->data > newData)
				current = current->left;
			else
				current = current->right;
		}

		if (currentTrail->data > newData)
			currentTrail->left = newNode;
		else
			currentTrail->right = newNode;
	}


}

void BinarySearchTree::printInOrder()
{
	traverseInOrder(root);
}

void BinarySearchTree::printPreOrder()
{
	traversePreOrder(root);
}

void BinarySearchTree::printPostOrder()
{
	traversePostOrder(root);
}

