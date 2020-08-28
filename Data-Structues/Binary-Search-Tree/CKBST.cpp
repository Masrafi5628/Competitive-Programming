#include <bits/stdc++.h>
#define MAX 5000
#define MIN -5000

using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};

Node* Insert(Node* root,int data)
{

    root=new Node();
    root->data=data;
    root->left=root->right=NULL;

    return root;

}
bool IsBstUtil(Node* root,int min_v,int max_v)
{
    if(root==NULL) return true;
    if(root->data < min_v || root->data > max_v)
        return false;
    return IsBstUtil(root->left,min_v,root->data) && IsBstUtil(root->right,root->data,max_v);
}

bool IsBST(Node* root)
{
    return IsBstUtil(root,MIN,MAX);
}

int main()
{
    Node* root=NULL;
    root=Insert(root,4);
    root->left=Insert(root->left,2);
    root->right=Insert(root->right,5);
    root->left->left=Insert(root->left->left,1);
    root->left->right=Insert(root->left->right,3);

    cout <<root->left->left->data<<endl;

    if(IsBST(root))
        cout << "This Binary tree is a BST\n";
    else
        cout << "This is not a BST\n";

    return 0;
}
