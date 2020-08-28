#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

void Enqueue(int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->next=NULL;

    if(front==NULL && rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
void Dequeue()
{
    Node* temp=front;

    if(front==NULL){
        cout << "Queue is empty\n";
        return;
    }
    else if(front==rear){
        front=rear=NULL;
        return;
    }
    else front=front->next;
    free(temp);
}
int Front()
{
    Node* temp=front;
    if(front==NULL){
        cout << "Queue is empty\n";
        return 0;
    }
    return front->data;
}
void Print()
{
    Node* temp=front;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    Enqueue(5);Print();
    Enqueue(15);Print();
    Enqueue(7);Print();
    Dequeue();Print();
    Enqueue(77);Print();
    cout << "Front is "<<Front();


    return 0;
}
