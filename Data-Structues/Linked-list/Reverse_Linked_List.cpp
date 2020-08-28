#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head;

void Insert(int data)
{
    Node* temp=new Node();
    temp->data=data;
    temp->next=nullptr;

    if(head==NULL){
        head=temp;
        return;
    }
    Node* temp2=head;

    while(temp2->next != nullptr){
        temp2=temp2->next;
    }
    temp2->next=temp;
}

void Print()
{
    Node* temp=head;

    while(temp != nullptr){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

Node* Reverse_Link(Node* p)
{
    if(p->next == nullptr) {
        head=p;
        return head;
    }
    Reverse_Link(p->next);
    Node* q=p->next;
    q->next=p;
    p->next=nullptr;

}

int main()
{
    head=nullptr;
    Insert(2);
    Insert(7);
    Insert(17);
    Insert(-1);

    Print();
    cout <<endl;
    Reverse_Link(head);
    Print();

    return 0;
}
