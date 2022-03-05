#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;


class LinkedList
{
	private:
		struct ListNode
		{
			double value;
			ListNode *next;
		};
		
		ListNode *head;
		
	public:
		LinkedList()
		{
			head = nullptr;
		}
		~LinkedList();
		
		void appendNode(double);
		void insertNode(double);
		void deleteNode(double);
		void displayList() const;
		void reverseList();
		
};
#endif