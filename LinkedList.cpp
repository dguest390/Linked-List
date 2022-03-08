#include "LinkedList.h"
#include <iostream>

using namespace std;

void LinkedList::appendNode(double newValue)
{
	ListNode *newNode;
	ListNode *nodePtr;
	
	newNode = new ListNode;
	newNode->value = newValue;
	newNode->next = nullptr;
	
	if(!head)
		head = newNode;
	else
	{
		nodePtr = head;
		
		while(nodePtr->next)
			nodePtr = nodePtr->next;
		
		nodePtr->next = newNode;
	}
}

void LinkedList::displayList() const 
{
	ListNode *nodePtr;
	
	nodePtr = head;
	
	while(nodePtr)
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}


void LinkedList::insertNode(double newValue)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *prevNode = nullptr;
	
	newNode = new ListNode;
	newNode->value = newValue;
	
	if(!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	
	else
	{
		nodePtr = head;
		prevNode = nullptr;
		
		while(nodePtr != nullptr && nodePtr->value < newValue)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if(prevNode == nullptr) // Needs to be == not =
		{
			head = newNode;
			newNode->next = nodePtr; // I had this: nodePtr = newNode->next;
		}
		
		else
		{
		prevNode->next = newNode; // I had this: newNode = prevNode->next;
		newNode->next = nodePtr;  // I had this: nodePtr = newNode->next;   LEARN WHY THIS HAPPENED
		}
	}
}


void LinkedList::deleteNode(double searchValue)
{
	ListNode *nodePtr;
	ListNode *prevNode;
	
	if(!head)
		return;
	
	if(head->value == searchValue)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	
	else
	{
	nodePtr = head;
	
	while(nodePtr != nullptr && nodePtr->value != searchValue)
	{
		prevNode = nodePtr;
		nodePtr = nodePtr->next;
	}
	
	if(nodePtr)
		{
			prevNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

LinkedList::~LinkedList()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	
	nodePtr = head;
	
	while(nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}	

void LinkedList::reverseList()
{
	ListNode *curr = head;
	ListNode *temp = nullptr;
	ListNode *prev = nullptr;
	
	while(curr != nullptr)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
}	