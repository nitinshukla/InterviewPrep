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
	node* curr=root;
	cout<<"List is ";
	while(curr->next)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<curr->data<<" ";
	cout<<endl;
}
node* partitionList(node* root, int k)
{
    if(!root)
        return NULL;
    node* root1=NULL;
    node* root2=NULL;
    node* curr = root;
    while(true)
    {
        if(curr->data < k)
        {
           insertNode(&root1,curr->data); 
        }
        else
        {
           insertNode(&root2,curr->data); 
        }
        curr=curr->next;
        if(curr==NULL)
            break;
    }
    node* joinedList = NULL;
    
    if(root1 && root2)
    {
        node* curr1=root1;
        while(curr1->next)
        {
            curr1=curr1->next;
        }
        joinedList = root1;
        curr1->next = root2;
    }
    else
    {
        if(!root1 && root2)
            joinedList=root2;
        else if(!root2 && root1)
            joinedList=root1;
    }
    return joinedList;
        
}
int main()
{
	node* root = NULL;
	insertNode(&root,1);
	insertNode(&root,4);
	insertNode(&root,10);
	insertNode(&root,2);
	insertNode(&root,5);
	insertNode(&root,3);
	insertNode(&root,7);
	insertNode(&root,8);
	printList(root);
	node* joined = partitionList(root,5);
	printList(joined);
}