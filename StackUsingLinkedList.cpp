//Implementation of Stack using linked list

#include <iostream>
using namespace std;
struct node
{
	node* next;
	node* prev;
	int data;
};
struct LinkedList
{
	node* head = NULL;
	node* tail = NULL;
	int size = 0;
	void insertNode(int data)
	{
		if (!head)
		{
			head = createNode(data);
			tail = head;
		}
		node* cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = createNode(data);
		tail = cur->next;
		tail->prev = cur;
		size++;
	}
	void removeLast()
	{
		node* cur = tail;
		tail->prev->next = NULL;
		tail = tail->prev;
		delete cur;
		size--;
	}
	int getLastNodeData()
	{
		return tail->data;
	}
	node* createNode(int data)
	{
		node* newNode = new node;
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->data = data;
		return newNode;
	}
};
struct Stack
{
	LinkedList list;
	bool isEmpty()
	{
		if (list.size == 0)
			return true;
		else
			return false;
	}
	void push(int data)
	{
		list.insertNode(data);
	}
	void pop()
	{
		list.removeLast();
	}
	int top()
	{
		return list.getLastNodeData();
	}
	int size()
	{
		return list.size;
	}
};
int main()
{
	Stack stck;
	stck.push(10);
	stck.push(20);
	stck.push(30);
	stck.push(14);
	stck.push(56);
	stck.push(89);
	stck.push(36);
	stck.push(24);
	stck.push(58);
	stck.push(68);
	stck.pop();
	stck.pop();
	stck.push(90);
	stck.pop();
	stck.pop();
	cout << "********" << endl << stck.top() << "   Size is "<<stck.size()<<endl << "*******" << endl;
	return 0;
}