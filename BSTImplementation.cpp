#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	node* right;
	node* left;
	int data;
};

node* createNode(int data)
{
	node * newNode = new node;
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->data = data;
	return newNode;
}
node* FindMin(node* root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}
void insertNode(node** root, int data)
{
	if (*root == NULL)
	{
		*root = createNode(data);
	}
	else if (data > (*root)->data)
	{
		insertNode(&(*root)->right, data);
	}
	else
	{
		insertNode(&(*root)->left, data);
	}
}
void deleteNode(node** root, int data)
{
	if (*root == NULL)
		return;
	if (data > (*root)->data)
	{
		deleteNode(&(*root)->right, data);
	}
	else if (data < (*root)->data)
	{
		deleteNode(&(*root)->left, data);		
	}
	else // found node to be deleted
	{
		//case 1: node has 0 children
		if ((*root)->right == NULL && (*root)->left == NULL)
		{
			delete *root;
			*root = NULL;
		}
		//case 2: node has 1 child
		else if ((*root)->right == NULL || (*root)->left == NULL)
		{
			if ((*root)->right == NULL)
			{
				node* temp = *root;
				*root = (*root)->left;
				delete temp;
				temp = NULL;
			}
			else if ((*root)->left == NULL)
			{
				node* temp = *root;
				*root = (*root)->right;
				delete temp;
				temp = NULL;
			}
		}
		//case 3: node has two children
		else
		{
			node* temp = FindMin((*root)->right);
			(*root)->data = temp->data;
			deleteNode(&(*root)->right, temp->data);
		}
	}
}

void inorderTraversal(node* root)
{
	if (root == NULL)
		return;
	inorderTraversal(root->left);
	cout << root->data << endl;
	inorderTraversal(root->right);
	cout << "******************************" << endl;
}

int main()
{

	node* root = NULL;
	insertNode(&root, 10);
	insertNode(&root, 5);
	insertNode(&root, 12);
	insertNode(&root, 4);
	insertNode(&root, 8);
	insertNode(&root, 11);
	insertNode(&root, 15);
	insertNode(&root, 3);
	insertNode(&root, 13);
	inorderTraversal(root);
	deleteNode(&root, 3);
	deleteNode(&root, 15);
	deleteNode(&root, 12);
	inorderTraversal(root);
	return	0;
}

