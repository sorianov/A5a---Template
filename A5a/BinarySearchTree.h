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

template <typename DataType>
struct TreeNode
{
	DataType data;
	TreeNode* left;
	TreeNode* right;
};

template <typename DataType>
class BinarySearchTree
{
private:
	TreeNode<DataType>* root;
	void traverseInOrder(TreeNode<DataType>* root);
	void traversePreOrder(TreeNode<DataType>* root);
	void traversePostOrder(TreeNode<DataType>* root);
	void removeNode(TreeNode<DataType>* &root);
	void deleteTree(TreeNode<DataType>* &root);
	void traverseInOrderFuncPtr(TreeNode<DataType>* root, const function<void(TreeNode<DataType>*, int)> &printFunction, int nodeLevel = 0);
	void traversePostOrderFuncPtr(TreeNode<DataType>* root, const function<void(TreeNode<DataType>*, int)> &printFunction, int nodeLevel = 0);
	void traversePreOrderFuncPtr(TreeNode<DataType>* root, const function<void(TreeNode<DataType>*, int)> &printFunction, int nodeLevel = 0);

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<DataType> &copyTree);
	~BinarySearchTree();
	void insert(DataType newData);
	void copy(TreeNode<DataType>* originalRoot, TreeNode<DataType>* &copyRoot);
	void printInOrder();
	void printPreOrder();
	void printPostOrder();
	void batchInsert(DataType data[]);
	void remove(const DataType deleteItem);
	void removeAll();
	static void genericPrint(TreeNode<DataType>* root, int nodeLevel);
	void printInOrderUsingFunctionPointer();
	void printPostOrderUsingFunctionPointer();
	void printPreOrderUsingFunctionPointer();





};


template <typename DataType>
void BinarySearchTree<DataType>::batchInsert(DataType data[])
{
	for (int i = 0; i < 12; i++)
	{
		insert(data[i]);
	}
}

template <typename DataType>
inline void BinarySearchTree<DataType>::remove(const DataType deleteItem)
{
	TreeNode<DataType>* current;
	TreeNode<DataType>* currentTrail;
	bool found = false;

	// Empty Tree
	if (root == nullptr)
	{
		return;
	}

	else
	{
		current = root;
		currentTrail = root;

		// Searching for a node that contains
		// deleteItem as the data
		while (current != nullptr && !found)
		{
			if (current->data == deleteItem)
				found = true;
			else
			{
				currentTrail = current;

				if (current->data > deleteItem)
					current = current->left;
				else
					current = current->right;
			}
		}
		
		// Didn't find a node
		// because current is null
		// and found isn't true
		if (current == nullptr)
			return;

		else if (found)
		{
			cout << "Deleting " << deleteItem << "..." << endl;
			
			// Current didn't move
			// which means the node
			// to delete is root
			if (current == root)
				removeNode(root);

			// Have to use the parent node (currentTrail)
			// to call removeNode since pointer adjustments
			// are necessary
			else if (currentTrail->data > deleteItem)
				removeNode(currentTrail->left);
			else
				removeNode(currentTrail->right);
		}
		else
			return;
	}
}

template <typename DataType>
inline void BinarySearchTree<DataType>::removeAll()
{
	deleteTree(root);
}

template <typename DataType>
inline void BinarySearchTree<DataType>::genericPrint(TreeNode<DataType>* root, int nodeLevel)
{
	cout << root->data << "(" << nodeLevel << ")" << " ";
}

template <typename DataType>
inline void BinarySearchTree<DataType>::printInOrderUsingFunctionPointer()
{
	traverseInOrderFuncPtr(root, genericPrint);
}

template <typename DataType>
inline void BinarySearchTree<DataType>::printPostOrderUsingFunctionPointer()
{
	traversePostOrderFuncPtr(root, genericPrint);
}

template <typename DataType>
inline void BinarySearchTree<DataType>::printPreOrderUsingFunctionPointer()
{
	traversePreOrderFuncPtr(root, genericPrint);
}

template <typename DataType>
void BinarySearchTree<DataType>::traverseInOrder(TreeNode<DataType>* root)
{
	if (root != nullptr)
	{
		traverseInOrder(root->left);
		cout << root->data << " ";
		traverseInOrder(root->right);
	}
}

template <typename DataType>
void BinarySearchTree<DataType>::traversePreOrder(TreeNode<DataType>* root)
{
	if (root != nullptr)
	{
		cout << root->data << " ";
		traversePreOrder(root->left);
		traversePreOrder(root->right);
	}
}

template <typename DataType>
void BinarySearchTree<DataType>::traversePostOrder(TreeNode<DataType>* root)
{
	if (root != nullptr)
	{
		traversePostOrder(root->left);
		traversePostOrder(root->right);
		cout << root->data << " ";
	}
}

template <typename DataType>
inline void BinarySearchTree<DataType>::removeNode(TreeNode<DataType>* &nodeToDelete)
{
	TreeNode<DataType>* current;
	TreeNode<DataType>* currentTrail;
	TreeNode<DataType>* temp;

	// Empty tree
	if (nodeToDelete == nullptr)
		return;

	// Leaf Node
	else if (nodeToDelete->left == nullptr && nodeToDelete->right == nullptr)
	{
		temp = nodeToDelete;
		nodeToDelete = nullptr;
		delete temp;
	}

	// Empty left subtree, right child
	else if (nodeToDelete->left == nullptr)
	{
		temp = nodeToDelete;
		nodeToDelete = temp->right;
		delete temp;
	}

	// Empty right subtree, left child
	else if (nodeToDelete->right == nullptr)
	{
		temp = nodeToDelete;
		nodeToDelete = temp->left;
		delete temp;
	}


	// Parent of two children
	else
	{
		// Going left...
		current = nodeToDelete->left;
		currentTrail = nullptr;

		// ...and then a hard right
		// to find the biggest child
		// to replace the parent that's
		// going to be deleted
		while (current->right != nullptr)
		{
			currentTrail = current;
			current = current->right;
		}

		// Swapping data with predecessor
		nodeToDelete->data = current->data;

		// Left child of root has no right children		
		if (currentTrail == nullptr)
			nodeToDelete->left = current->left;
		
		// Make parent of predecessor point to null
		else
			currentTrail->right = current->left;

		delete current;
	}
}

template <typename DataType>
inline void BinarySearchTree<DataType>::deleteTree(TreeNode<DataType>* &root)
{
	// Post order traversal to delete tree
	if (root != nullptr)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
		root = nullptr;
	}
}

template <typename DataType>
inline void BinarySearchTree<DataType>::traverseInOrderFuncPtr(TreeNode<DataType>* root, const function<void(TreeNode<DataType>*, int)>& printFunction, int nodeLevel)
{
	if (root != nullptr)
	{
		// Because traversal starts going down a branch, we can't start at 0,
		// so we increment nodeLevel
		traverseInOrderFuncPtr(root->left, printFunction, ++nodeLevel);
		
		// We visit the node, but the nodelevel is off by one, so we decrement it
		printFunction(root, --nodeLevel);
	
		// The nodelevel is off by one again, because of the above line so we 
		// increment it before going down another branch. This could be avoided 
		// by doing nodeLevel - 1 in the above line instead of --nodeLevel
		// but --nodeLevel looks nicer :)
		traverseInOrderFuncPtr(root->right, printFunction, ++nodeLevel);
	}
}

template <typename DataType>
inline void BinarySearchTree<DataType>::traversePostOrderFuncPtr(TreeNode<DataType>* root, const function<void(TreeNode<DataType>*, int)>& printFunction, int nodeLevel)
{
	if (root != nullptr)
	{
		// We don't start at node, so we increment nodeLevel before
		// going down a branch. Only have to do it once since we go
		// down another branch before visiting the node
		traversePostOrderFuncPtr(root->left, printFunction, ++nodeLevel);
		traversePostOrderFuncPtr(root->right, printFunction, nodeLevel);

		// We visit the node, but our nodeLevel is off by one because
		// of an attempted traversal so we decrement it
		printFunction(root, --nodeLevel);
	}
}

template <typename DataType>
inline void BinarySearchTree<DataType>::traversePreOrderFuncPtr(TreeNode<DataType>* root, const function<void(TreeNode<DataType>*, int)>& printFunction, int nodeLevel)
{
	if (root != nullptr)
	{
		// We visit the node first, so the value of nodeLevel is the level
		// we are at in the tree
		printFunction(root, nodeLevel);

		// Only need to increment the nodeLevel once because the right
		// branch shoould be on the same level as the left if it exists
		traversePreOrderFuncPtr(root->left, printFunction, ++nodeLevel);
		traversePreOrderFuncPtr(root->right, printFunction, nodeLevel);
	}
}

template <typename DataType>
BinarySearchTree<DataType>::BinarySearchTree()
{
	root = nullptr;
}

template <typename DataType>
inline BinarySearchTree<DataType>::BinarySearchTree(const BinarySearchTree<DataType> & copyTree)
{
	if (copyTree.root == nullptr)
		root = nullptr;
	else
		copy(copyTree.root, root);
}

template <typename DataType>
inline BinarySearchTree<DataType>::~BinarySearchTree()
{
	removeAll();
}

template <typename DataType>
void BinarySearchTree<DataType>::insert(DataType newData)
{
	TreeNode<DataType>* current = root;
	TreeNode<DataType>* currentTrail = current;
	TreeNode<DataType>* newNode = new TreeNode<DataType>;

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

template <typename DataType>
inline void BinarySearchTree<DataType>::copy(TreeNode<DataType>* originalRoot, TreeNode<DataType>* &copyRoot)
{
	if (originalRoot == nullptr)
		copyRoot = nullptr;
	else
	{
		// PreOrder to copy the tree
		copyRoot = new TreeNode<DataType>;
		copyRoot->data = originalRoot->data;
		copy(originalRoot->left, copyRoot->left);
		copy(originalRoot->right, copyRoot->right);
	}
}

template <typename DataType>
void BinarySearchTree<DataType>::printInOrder()
{
	traverseInOrder(root);
}

template <typename DataType>
void BinarySearchTree<DataType>::printPreOrder()
{
	traversePreOrder(root);
}

template <typename DataType>
void BinarySearchTree<DataType>::printPostOrder()
{
	traversePostOrder(root);
}

