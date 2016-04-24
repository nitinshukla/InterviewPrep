
#include <iostream>
using namespace std;
struct node
{
	node* next;
	node* prev;
	int data;
};

node* createNode(int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void insertNode(node** root, int data)
{
	if (!*root)
	{
		*root = createNode(data);
	}
	else
	{
		node* cur = *root;
		node* prev = *root;
		while (cur->next != NULL)
		{
			cur = cur->next;			
		}
		cur->next = createNode(data);
		cur->next->prev = cur;
	}

}
void removeNode(node** root, int data)
{
	if (!*root)
		return;	
	node* cur = *root;
	while (cur && cur->data != data)
	{
		cur = cur->next;
	}
	if (!cur)
		return;
	else if (cur == *root)
	{
		*root = cur->next;
		(*root)->prev = NULL;
		delete cur;
	}
	else
	{
		cur->prev->next = cur->next;
		if (cur->next)//only if not last node
		{
			cur->next->prev = cur->prev;
		}
		delete cur;
	}
}

void printListForward(node* root)
{
	node* cur = root;
	while (cur)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
	cout << "*************************" << endl;
}

void printListBackwards(node* root)
{
	node* cur = root;
	node* prev = root;
	while (cur && cur->next != NULL)
	{
		cur = cur->next;
	}
	while (cur)
	{
		cout << cur->data << endl;
		cur = cur->prev;
	}
	cout << "*************************" << endl;
}

int main()
{
	node * root;
	insertNode(&root,10);
	insertNode(&root,20);
	insertNode(&root,45);
	insertNode(&root,87);
	insertNode(&root,29);
	insertNode(&root,15);
	insertNode(&root,35);
	insertNode(&root,90);
	insertNode(&root,56);
	printListForward(root);
	printListBackwards(root);
	removeNode(45);
	printListForward(root);
	return;
}