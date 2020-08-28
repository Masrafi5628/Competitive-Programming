#include <bits/stdc++.h>

using namespace std;

struct bstnode {
    int data;
    bstnode* left;
    bstnode* right;
};

bstnode* getnewNode(int data)
{
    bstnode* newnode = new bstnode();
    newnode->data=data;
    newnode->left=newnode->right=NULL;

    return newnode;
}
bstnode* Insert(bstnode* root,int data)
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

int Findmin(bstnode* root)
{
    if(root==NULL){
        cout << "Error\n";
        return -1;
    }
    else if(root->left==NULL){
        return root->data;
    }
    Findmin(root->left);
}
int Findmax(bstnode* root)
{
    if(root==NULL){
        cout << "Error\n";
        return -1;
    }
    else if(root->right==NULL)
        return root->data;
    Findmax(root->right);
}

int main()
{
    int num;
    bstnode* root=NULL;
    for(int i=0;i<7;i++){
        cin>>num;
        root=Insert(root,num);
    }

    cout << "Min num is "<<Findmin(root)<<endl;
    cout << "Max num is "<<Findmax(root)<<endl;

    return 0;
}
