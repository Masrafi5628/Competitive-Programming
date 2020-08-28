#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

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
    if(root==NULL) return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

Node* Find(Node* root,int data)
{
    if(root==NULL) return NULL;
    else if(root->data==data) return root;
    else if(data < root->data) Find(root->left,data);
    else Find(root->right,data);
}

Node* Findmin(Node* root)
{
    if(root==NULL) return NULL;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* getSuccessor(Node* root,int data)
{
    Node* current=Find(root,data);
    if(current == NULL) return NULL;
    if(current->right != NULL) {
        return Findmin(current->right);
    }
    else {
        Node* successor = NULL;
        Node* ancestor = root;

        while(ancestor != current){
            if(current->data < ancestor->data){
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else ancestor=ancestor->right;
        }
        return successor;
    }

}

int main()
{
    Node* root = NULL;
`	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,1); root = Insert(root,11);

    cout << "Inorder traversal: ";
    Inorder(root);
    cout <<endl;

    Node* successor=getSuccessor(root,4 );
    if(successor==NULL) cout << "No successor found\n";
    else cout << "Successor is "<<successor->data<<endl;

    return 0;
}
