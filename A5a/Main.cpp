//===============================================================
// * Program Name: Assignnment 5
// * Author: Victor Soriano Mendoza
// * Date Written: 05/10/2017
// * Description: Binary Search Tree with basic functionality
//===============================================================
#include "BinarySearchTree.h"

using namespace std;



int main()
{

	cout << "CS260 Assignment 5a - Binary Trees, part 1" << endl;
	cout << "Victor Soriano Mendoza" << endl;

	string pokemon[12] = { "Jynx", "Charmander", "Snorlax", "Diglett", "Kakuna", "Meowth",
						   "Pikachu", "Blastoise", "Squirtle", "Ivysaur", "Bulbasaur", "Abra" };
	
	BinarySearchTree tree;

	TreeNode* copycat;
		
	tree.batchInsert(pokemon);
	/*tree.insert("Jynx");
	tree.insert("Charmander");
	tree.insert("Snorlax");
	tree.insert("Diglett")*/;

	tree.deleteNode("Squirtle");
	tree.printInOrder();
	cout << endl;

	tree.deleteNode("Meowth");
	tree.printInOrder();
	cout << endl;

	tree.deleteNode("Blastoise");
	tree.printInOrder();
	cout << endl;

	tree.deleteNode("Jynx");
	tree.printInOrder();
	cout << endl;

	tree.printInOrderUsingFunctionPointer();
	cout << endl;

	tree.printPostOrderUsingFunctionPointer();
	cout << endl;
	
	tree.printPreOrderUsingFunctionPointer();
	cout << endl;



	return 0;
}