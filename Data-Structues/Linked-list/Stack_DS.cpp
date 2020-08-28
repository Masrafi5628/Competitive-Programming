#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* link;
};
Node* top=NULL;

void Push(int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->link=top;
    top=temp;
}
void Pop()
{
    Node* temp=top;
    if(top==nullptr) return;
    top=top->link;
    free(temp);
}
int Top()
{
    return top->data;
}
void Print()
{
    Node* temp=top;
    printf("Stack: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main()
{

    Push(5);Print();
    Push(-1);Print();
    Push(97);Print();
    Push(4);Print();
    Pop();Print();
    Push(17);Print();
    printf("%d\n",Top());

    return 0;
}
