#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

node* createNewNode(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next=NULL;
	return newNode;
}
void insertNode(node** root,int data)
{
	if(*root == NULL)
	{
		*root = createNewNode(data);
	}
	else
	{
		node* curr = *root;
		while(curr->next != NULL)
		{
			curr=curr->next;			
		}
		curr->next = createNewNode(data);
	}
}
void printList(node* root)
{
    if(!root)
        return;
	node* curr=root;
	cout<<"List is ";
	while(curr)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}}
void removeKthToLastElem(node** root, int k)
{
	int length=0;
	node* curr = *root;
	
	while(curr->next)
	{
		length++;
		curr=curr->next;
	}
	length++;
	cout<<"Length of list "<<length<<endl;
	int gotoNode=length-k+1;
	cout<<"delete "<<k<<"th node from last which is "<<gotoNode<<"th node from beginning."<<endl;
	curr=*root;
	node* prev=NULL;
	while(curr->next && gotoNode != 1)
	{	
		prev=curr;
		curr=curr->next;
		gotoNode--;
	}
	cout<<"deleting data "<<curr->data<<endl;
	prev->next = curr->next;
	delete curr;	
}
int main()
{
	node* root = NULL;
	insertNode(&root,1);
	insertNode(&root,2);
	insertNode(&root,3);
	insertNode(&root,4);
	insertNode(&root,5);
	insertNode(&root,6);
	insertNode(&root,7);
	insertNode(&root,8);
	printList(root);
	removeKthToLastElem(&root,3);
	printList(root);
}