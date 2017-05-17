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

	string pokemon[14] = { "Jynx", "Charmander", "Snorlax", "Clefairy", "Diglett", "Kakuna", "Meowth",
						   "Nidorino", "Pikachu", "Blastoise", "Squirtle", "Ivysaur", "Bulbasaur", "Abra" };
	
	BinarySearchTree<string> tree;
	
	//tree.batchInsert(pokemon);
	tree.insert("Jynx");
	tree.insert("Charmander");
	tree.insert("Snorlax");
	tree.insert("Clefairy");

	tree.printInOrder();
	cout << endl;

	tree.printPreOrder();
	cout << endl;

	tree.printPostOrder();
	cout << endl;

	


	return 0;
}