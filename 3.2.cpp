#include <iostream>
using namespace std;
class stack
{
	struct node
	{
		node* next;
		int data;
		int min;
	};
	node* root;
	int min;
	public:
	stack()
	{
		root = NULL;
		min=0;
	}
	node* createNewNode(int data=0)
	{
		node* newNode = new node();
		newNode->data = data;
		newNode->min = min;
		newNode->next = NULL;
		return newNode;
	}
	void push(int nodedata)
	{
		if(root == NULL)
		{
			root = createNewNode(nodedata);
			min = nodedata;				
			root->min = nodedata;
		}
		else
		{
			node* curr = root;
			root = createNewNode(nodedata);
			root->next = curr;
			if(min > nodedata)
			{
				min = nodedata;				
			}
			root->min = min;
		}
	}
	void pop()
	{
		if(root == NULL)
		{
			return;
		}
		else
		{
			node* curr = root;
			root=curr->next;
			min = root->min;
			delete curr;
		}
	}
	int minval()
	{
		return min;
	}
	void print()
	{
		if(!root)
		return;
		node* curr = root;
		cout<<"Stack top -> bottom is: ";
		while(curr)
		{
			cout<<curr->data<<" ";
			curr= curr->next;
		}
		cout<<endl;
	}
};
int main ()
{
    stack stck;
	stck.push(10);
	stck.push(7);
	stck.push(1);
	stck.push(3);
	stck.push(2);
    stck.print();
    cout<<"Min = "<<stck.minval()<<endl;
	stck.pop();
	cout<<"Min = "<<stck.minval()<<endl;
	stck.pop();
	cout<<"Min = "<<stck.minval()<<endl;
	stck.pop();
	cout<<"Min = "<<stck.minval()<<endl;
    return 0;
}