/* strtok example */
#include <vector>
#include <stack>
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
bool isPalindrome(node* root)
{
    bool isPalin = true;
    if(!root)
        return true;
    node* fast = root;
    node* slow = root;
    stack<int> stck;
    while(fast && fast->next)
    {
        stck.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast)
    {
        slow=slow->next;
    }
    while(slow)
    {
        if(stck.top() != slow->data)
        {
            isPalin=false;
            break;
        }
        stck.pop();
        slow=slow->next;
    }
    return isPalin;
}
int main ()
{
    node* root=NULL;
    insertNode(&root,1);
    insertNode(&root,2);
    insertNode(&root,3);
    insertNode(&root,3);
    insertNode(&root,2);
    insertNode(&root,1);
    printList(root);
    if(isPalindrome(root))
    cout<<"Is palin"<<endl;
    else
    cout<<"Is not palin"<<endl;
    return 0;
}