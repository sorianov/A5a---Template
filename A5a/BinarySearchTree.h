//===============================================================
// * Program Name: Assignnment 5
// * Author: Victor Soriano Mendoza
// * Date Written: 05/10/2017
// * Description: Binary Search Tree with basic functionality
//===============================================================
#pragma once
#include <string>
#include <iostream>

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
	void traverseInOrder(TreeNode* root, int nodeLevel);
	void traversePreOrder(TreeNode* root, int nodeLevel);
	void traversePostOrder(TreeNode* root, int nodeLevel);
	void deleteFromTree(TreeNode* &p);

public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(string newData);
	void printInOrder();
	void printPreOrder();
	void printPostOrder();
	void batchInsert(string data[]);
	void deleteNode(const string deleteItem);





};

void BinarySearchTree::batchInsert(string data[])
{
	for (int i = 0; i < 14; i++)
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


TreeNode* BinarySearchTree::getRoot()
{
	return root;
}

void BinarySearchTree::traverseInOrder(TreeNode* root, int nodeLevel)
{
	if (root != nullptr)
	{
		// Because traversal starts going down a branch, we can't start at 0,
		// so we increment nodeLevel by 1
		traverseInOrder(root->left, ++nodeLevel);

		// We visit the node, but the nodelevel is off by one, so we decrement it
		cout << root->data << "(" << --nodeLevel << ")" << " ";

		// The nodelevel is off by one again, because the above call so we 
		// increment it before going down another branch. This could be avoided 
		// by doing nodeLevel - 1 in the above line instead of --nodeLevel
		// but --nodeLevel looks nicer :)
		traverseInOrder(root->right, ++nodeLevel);
	}
}

void BinarySearchTree::traversePreOrder(TreeNode* root, int nodeLevel)
{
	if (root != nullptr)
	{
		// We visit the node first, so the value of nodeLevel is the level
		// we are at in the tree
		cout << root->data << "(" << nodeLevel << ")" << " ";

		// Only need to increment the nodeLevel once and it has to be
		// during the first time we go down a branch, otherwise it would
		// be wrong when going down the first branch
		traversePreOrder(root->left, ++nodeLevel);
		traversePreOrder(root->right, nodeLevel);
	}
}

void BinarySearchTree::traversePostOrder(TreeNode* root, int nodeLevel)
{
	if (root != nullptr)
	{
		// We don't start at node, so we increment nodeLevel before
		// going down a branch. Only have to do it once since we go
		// down another branch before visiting the node.
		traversePostOrder(root->left, ++nodeLevel);
		traversePostOrder(root->right, nodeLevel);

		// We visit the node, but our nodeLevel is off by one, so we
		// decrement it
		cout << root->data << "(" << nodeLevel << ")" << " ";
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
	// Initial nodeLevel is 0 which is what
	// the second argument is
	traverseInOrder(getRoot(), 0);
}

void BinarySearchTree::printPreOrder()
{
	// Initial nodeLevel is 0 which is what
	// the second argument is
	traversePreOrder(getRoot(), 0);
}

void BinarySearchTree::printPostOrder()
{
	// Initial nodeLevel is 0 which is what
	// the second argument is
	traversePostOrder(getRoot(), 0);
}
