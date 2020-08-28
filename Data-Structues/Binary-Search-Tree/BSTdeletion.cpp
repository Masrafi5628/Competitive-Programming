#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* Findmin(Node* root)
{
    while(root->left != NULL){
        root=root->left;
    }
    return root;
}

Node* Delete(Node *root,int data)
{
    if(root==NULL) return root;
    else if(data < root->data) root->left=Delete(root->left,data);
    else if(data > root->data) root->right=Delete(root->right,data);
    else {
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        else if(root->left == NULL)
        {
            Node* temp=root;
            root=root->right;
            delete temp;
            temp=NULL;
        }
        else if(root->right == NULL){
            Node* temp=root;
            root=root->left;
            delete temp;
            temp=NULL;
        }
        else {
            Node* temp=Findmin(root->right);
            root->data=temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}

Node* Insert(Node* root,int data)
{
    if(root==NULL){
        root=new Node();
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data < root->data) root->left=Insert(root->left,data);
    else root->right=Insert(root->right,data);

    return root;
}

void Inorder(Node* root)
{
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

int main()
{
    Node* root=NULL;

    root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,1); root = Insert(root,11);

	root=Delete(root,5);

	cout << "Inorder: ";
	Inorder(root);
	cout <<endl;

    return 0;
}
