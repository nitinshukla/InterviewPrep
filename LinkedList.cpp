#include <iostream>

struct Node
{
	Node* next;
	int data;
};

Node* createNode(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertNode(Node** root,int data)
{
	if(*root == NULL)
	{
		*root = createNode(data);
	}
	else
	{
		Node* curNode = *root;
		while(curNode->next != NULL)
		{
			curNode=curNode->next;
		}
		curNode->next = createNode(data);
	}
}

void removeNode(Node** root,int data)
{
	if(*root == NULL)
	{
		return;
	}
	else
	{
		Node* prev=*root;
		Node* cur=*root;
		while(cur && cur->data != data)
		{
			prev=cur;
			cur=cur->next;			
		}
		if(!cur) // node with given data not found
		{
			return;
		}
		if(cur == *root)//head node to be removed
		{
			*root = cur->next;			
		}
		else if(cur->next == NULL)//tail node to be removed
		{
			prev->next = NULL;			
		}
		else // anywhere in the middle
		{
			prev->next = cur->next;			
		}
		delete cur;
	}
}

void printList(Node* root)
{
	if(!root)
		return;
	Node* cur = root;
	while(true)
	{
		cout<<cur->data<<endl;
		cur=cur->next;
		if(cur->next == NULL)
			break;
	}	
}

int main()
{
	Node* root=NULL;
	insertNode(&root,10);
	insertNode(&root,20);
	insertNode(&root,30);
	insertNode(&root,7);
	insertNode(&root,90);
	insertNode(&root,45);
	insertNode(&root,23);
	insertNode(&root,67);
	insertNode(&root,57);
	
	printList(root);
	
	removeNode(&root,10);
	removeNode(&root,30);
	removeNode(&root,57);
	removeNode(&root,67);
	
	printList(root);

	return	0;	
}