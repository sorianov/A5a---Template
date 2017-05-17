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

template <typename Type>
struct TreeNode
{
	Type data;
	TreeNode<Type>* left;
	TreeNode<Type>* right;
};

template <typename Type>
class BinarySearchTree
{
private:
	TreeNode<Type>* root;
	TreeNode<Type>* getRoot();
	void traverseInOrder(TreeNode<Type>* root, int nodeLevel);
	void traversePreOrder(TreeNode<Type>* root, int nodeLevel);
	void traversePostOrder(TreeNode<Type>* root, int nodeLevel);

public:
	BinarySearchTree();
	void insert(Type newData);
	void printInOrder();
	void printPreOrder();
	void printPostOrder();
	void batchInsert(Type data[]);



};

template<typename Type>
inline void BinarySearchTree<Type>::batchInsert(Type data[])
{
	for (int i = 0; i < 14; i++)
	{
		insert(data[i]);
	}
}


template <typename Type>
TreeNode<Type> * BinarySearchTree<Type>::getRoot()
{
	return root;
}

template <typename Type>
void BinarySearchTree<Type>::traverseInOrder(TreeNode<Type> * root, int nodeLevel)
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

template <typename Type>
void BinarySearchTree<Type>::traversePreOrder(TreeNode<Type> * root, int nodeLevel)
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

template <typename Type>
void BinarySearchTree<Type>::traversePostOrder(TreeNode<Type> * root, int nodeLevel)
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

template <typename Type>
BinarySearchTree<Type>::BinarySearchTree()
{
	root = nullptr;
}

template <typename Type>
void BinarySearchTree<Type>::insert(Type newData)
{
	TreeNode<Type>* current = root;
	TreeNode<Type>* currentTrail = current;
	TreeNode<Type>* newNode = new TreeNode<Type>;

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

template <typename Type>
void BinarySearchTree<Type>::printInOrder()
{
	// Initial nodeLevel is 0 which is what
	// the second argument is
	traverseInOrder(getRoot(), 0);
}

template <typename Type>
void BinarySearchTree<Type>::printPreOrder()
{
	// Initial nodeLevel is 0 which is what
	// the second argument is
	traversePreOrder(getRoot(), 0);
}

template <typename Type>
void BinarySearchTree<Type>::printPostOrder()
{
	// Initial nodeLevel is 0 which is what
	// the second argument is
	traversePostOrder(getRoot(), 0);
}
