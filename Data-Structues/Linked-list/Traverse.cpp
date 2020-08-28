#include <bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* Insert(Node* root,char data)
{
    if(root==NULL){
        root=new Node();
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data<=root->data){
        root->left=Insert(root->left,data);
    }
    else {
        root->right=Insert(root->right,data);
    }
    return root;
}

void LevelOrder(Node* root)
{
    if(root==NULL) return;
    queue <Node*> Q;
    Q.push(root);

    while(!Q.empty()){
        Node* current=Q.front();
        Q.pop();
        cout << current->data<<" ";

        if(current->left != NULL) Q.push(current->left);
        if(current->right!= NULL) Q.push(current->right);
    }
}

int main()
{
    Node* root = NULL;
    char ch;

   /* root=Insert(root,'M');root=Insert(root,'B');root=Insert(root,'Q');
    root=Insert(root,'Z');root=Insert(root,'A');root=Insert(root,'C');*/

    for(int i=0;i<6;i++){
        cin>>ch;
        root=Insert(root,ch);
    }

    LevelOrder(root);

    return 0;
}
