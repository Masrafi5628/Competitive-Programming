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

    if(front==NULL) return;
    if(front==rear) front=rear=NULL;
    else front=front->next;

    free(temp);
}
int Front()
{
    return front->data;
}

int main()
{
    Enqueue(5);cout <<Front()<<endl;
    Enqueue(12);cout <<Front()<<endl;
    Enqueue(1);cout <<Front()<<endl;
    Dequeue();cout <<Front()<<endl;
    Enqueue(7);cout <<Front()<<endl;

    return 0;
}
