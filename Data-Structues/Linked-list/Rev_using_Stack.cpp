#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* link;
};

Node* head;

void Insert(int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->link=nullptr;
    if(head==nullptr){
        head=temp;
        return;
    }
    Node* temp1=head;
    while(temp1->link != nullptr) temp1=temp1->link;
    temp1->link=temp;
}

void Reverse()
{
    if(head==nullptr) return;
    stack <Node*> s;
    Node* temp=head;

    while(temp != nullptr){
        s.push(temp);
        temp=temp->link;
    }
    temp=s.top();
    head=temp;
    s.pop();

    while(!s.empty()){
        temp->link=s.top();
        s.pop();
        temp=temp->link;
    }
    temp->link=nullptr;

}
void Print()
{
    Node* temp=head;
    while(temp != nullptr){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");

}
int main()
{
    head=nullptr;
    Insert(12);
    Insert(7);
    Insert(-1);
    Insert(27);
    Insert(5);

    Print();
    Reverse();
    Print();


    return 0;
}
