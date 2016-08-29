/* strtok example */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct node
{
    node* next;
    int data;
};

node* createNewNode(int data)
{
    node* newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertNode(node** root, int nodedata)
{
    if(*root == NULL)
    {
        *root = createNewNode(nodedata);
    }
    else
    {
        node* curr = *root;
        while(curr->next)
        {
            curr=curr->next;
        }
        curr->next = createNewNode(nodedata);
    }
}
bool findNode(const vector<node*>& vec,node* check)
{
    vector<node*>::const_iterator it = vec.begin(); 
    for(;it!=vec.end();it++)
    {
        if(*it == check)
            return true;
    }
    return false;
}
void printList(node* root)
{
    if(!root)
    return;
    node* curr = root;
    cout<<"List is: ";
    while(curr)
    {
        cout<<curr->data<<" ";
        curr= curr->next;
    }
}
void printListAndCheckLoop(node* root)
{
    if(root == NULL)
        return;
    node* curr = root;
    vector<node*> visited;
    cout<<"List is: ";
    vector<node*>::iterator it;
    while(curr)
    {
        if(!findNode(visited,curr))
        {
            visited.push_back(curr);
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        else
        {
            cout<<"Loop is at "<<curr->data<<endl;
            break;
        }
    }
}
void createLoopAt(node** root, int n)
{
    if(*root == NULL)
        return;
    node* curr = *root;
    node* temp = NULL;
    int count=0;
    while(curr->next)
    {
        count++;
        if(count == n)
        {
            temp = curr;
        }
        curr = curr->next;
    }
    curr->next = temp;
}
int main ()
{
    node* root=NULL;
    insertNode(&root,1);
    insertNode(&root,2);
    insertNode(&root,3);
    insertNode(&root,4);
    insertNode(&root,5);
    insertNode(&root,6);
    printList(root);
    createLoopAt(&root,4);
    printListAndCheckLoop(root);
    return 0;
}