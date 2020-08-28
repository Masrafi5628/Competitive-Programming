#include <bits/stdc++.h>

using namespace std;

struct BSTnode{
    int data;
    BSTnode* left;
    BSTnode* right;
};
BSTnode* getnewNode(int data)
{
    BSTnode* newNode=new BSTnode();
    newNode->data=data;
    newNode->left=newNode->right=NULL;

    return newNode;
}

BSTnode* Insert(BSTnode* root,int data)
{
    if(root==NULL){
        root=getnewNode(data);
    }
    else if(data<=root->data){
        root->left=Insert(root->left,data);
    }
    else {
        root->right=Insert(root->right,data);
    }

    return root;
}
bool Search(BSTnode* root,int data)
{
    if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(data<=root->data) return Search(root->left,data);
    else Search(root->right,data);
}

int main()
{
    BSTnode* root = NULL;//creating a empty tree

    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);

    int num;
    printf("Enter number for search\n");
    cin>>num;

    if(Search(root,num)) {
        printf("%d found in the BST\n",num);
    }
    else {
        printf("Not found\n");
    }

    return 0;
}
