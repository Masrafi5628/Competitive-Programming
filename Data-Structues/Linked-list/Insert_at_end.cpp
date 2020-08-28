/// Inserting value at end

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};
struct Node* head;

void Insert(int data)
{
    Node* temp=new Node();
    temp->data=data;
    temp->next=NULL;

    if(head== NULL){
        head=temp;
    }
    else {
        Node* temp1=head;
        while(temp1->next != NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;

    }
}

void Print()
{
    Node* temp=head;

    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    Insert(12);
    Insert(5);
    Insert(7);
    Insert(0);

    Print();

    return 0;
}
