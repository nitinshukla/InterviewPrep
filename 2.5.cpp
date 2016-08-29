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
}
node* addLists(node* first,node* second)
{
	node* curr1=first;
	node* curr2=second;
	node* resultant=NULL;
	int sum=0;
	while(curr1 && curr2)
	{
		sum = curr1->data + curr2->data + sum;
		if(sum>9)
		{
			sum = sum%10;
			insertNode(&resultant,sum);
			sum=1;
		}
		else
		{
		    insertNode(&resultant,sum); 
		    sum=0;
		}
		curr1=curr1->next;	
		curr2=curr2->next;
	}
	while(curr1)
	{
	   int data=0;
	   if(sum>0)
	   {
	      data = sum + curr1->data;  
	      if(data>9)
	      {
	          data=data%10;
	          sum=1;
	      }
	   }
	   insertNode(&resultant,data);
	   curr1=curr1->next;
	}
	while(curr2)
	{
	   int data=0;
	   if(sum>0)
	   {
	      data = sum + curr1->data;  
	      if(data>9)
	      {
	          data=data%10;
	          sum=1;
	      }
	   }
	   insertNode(&resultant,data);
	   curr2=curr2->next;
	}
	if(sum>0)
	{
	  insertNode(&resultant,1);  
	}
	return resultant;
}
int main()
{
	node* first = NULL;
	insertNode(&first,1);
	insertNode(&first,4);
	insertNode(&first,9);
	insertNode(&first,9);
	insertNode(&first,9);
	node* second = NULL;
	insertNode(&second,2);
	insertNode(&second,3);
	insertNode(&second,9);	
	
	printList(first);
	printList(second);
	node* result = addLists(first,second);
	printList(result);
}