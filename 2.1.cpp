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
		cout<<"creating root node"<<endl;
	}
	else
	{
		node* curr = *root;
		while(curr->next != NULL)
		{
			curr=curr->next;			
		}
		curr->next = createNewNode(data);
		cout<<"adding new node"<<endl;
	}
}
void removeDuplicates(node** root)
{
	int tempdata=0;
	node * curr = *root;
	node * lookahead = *root;
	node* prev = NULL;
	while(curr->next != NULL)
	{
		tempdata=curr->data;
		lookahead=curr->next;
		prev = curr;		
		while(lookahead->next != NULL)
		{
			if(lookahead->data == tempdata)
			{
				prev->next=lookahead->next;
				node* temp=lookahead;
				lookahead=prev->next;
				delete temp;
			}
			else
			{
				prev=lookahead;
				lookahead=lookahead->next;
			}
		}
		curr=curr->next;
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
}
int main()
{
	node* root = NULL;
	insertNode(&root,1);
	insertNode(&root,1);
	insertNode(&root,1);
	insertNode(&root,1);
	insertNode(&root,3);
	insertNode(&root,1);
	insertNode(&root,1);
	insertNode(&root,1);
	printList(root);
	removeDuplicates(&root);
	printList(root);
}