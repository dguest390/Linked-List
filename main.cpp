#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() 
{
	LinkedList list;
	
	cout << "Adding nodes \n";
	list.appendNode(1);
	list.appendNode(2);
	list.appendNode(3);
	list.appendNode(4);
	list.displayList();
	cout << "\n";
	
	cout << "Inserting node \n";
	list.insertNode(3.5);
	list.displayList();
	cout << "\n";
	
	cout << "Deleting node \n";
	list.deleteNode(3.5);
	list.displayList();
	cout << "\n";
	
	cout << "Reversing nodes \n";
	list.reverseList();
	list.displayList();
	cout << "\n";
	
	cout << "Reversing nodes \n";
	list.reverseList();
	list.displayList();
	
	
	return 0;
}