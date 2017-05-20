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

	cout << "CS260, A5-Binary Trees " << endl;
	cout << "Victor Soriano Mendoza" << endl << endl;

	string pokemon[12] = { "Jynx", "Charmander", "Snorlax", "Diglett", "Kakuna", "Meowth",
						   "Pikachu", "Blastoise", "Squirtle", "Ivysaur", "Bulbasaur", "Abra" };
	
	BinarySearchTree tree;
	tree.batchInsert(pokemon);
	BinarySearchTree treeCopy(tree);

	tree.printInOrderUsingFunctionPointer();
	cout << endl << endl;

	tree.remove("Squirtle");

	tree.printInOrderUsingFunctionPointer();;
	cout << endl << endl;
	tree.remove("Meowth");

	tree.printInOrderUsingFunctionPointer();
	cout << endl << endl;
	tree.remove("Blastoise");

	tree.printInOrderUsingFunctionPointer();
	cout << endl << endl;
	tree.remove("Jynx");

	tree.printInOrderUsingFunctionPointer();
	cout << endl << endl;

	treeCopy.printInOrderUsingFunctionPointer();
	cout << endl << endl;

	treeCopy.printPostOrderUsingFunctionPointer();
	cout << endl << endl;
	
	treeCopy.printPreOrderUsingFunctionPointer();
	cout << endl << endl;

	treeCopy.removeAll();
	treeCopy.printInOrderUsingFunctionPointer();

	return 0;
}