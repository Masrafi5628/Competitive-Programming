/// Add value to sorted linked list

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};
struct Node* head;

void Insert(int data)
{
    struct Node* temp=new Node();
    temp->data=data;
    temp->next=NULL;

    if(head==NULL) head=temp;
    else {
        struct Node* temp2=head;
        while(temp2->next != NULL) temp2=temp2->next;
        temp2->next=temp;
    }
}

void print()
{
    Node* temp=head;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void insert(int val)
{
    Node* temp=new Node();
    temp->data=val;

    if(head==NULL || temp->data < head->data){
        temp->next=head;
        head=temp;
    }else {
        struct Node* pred=head;
        struct Node* p=pred->next;

        while(p!=NULL && temp->data > p->data){
            pred=p;
            p=p->next;
        }
        pred->next=temp;
        temp->next=p;
    }
}

int main()
{
    head=NULL;
    Insert(4);
    Insert(10);
    Insert(13);

    print();
    insert(20);
    print();

    return 0;
}
