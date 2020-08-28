#include <bits/stdc++.h>

using namespace std;
int front=-1,rear=-1,size,ara[100];

void Deque(int n)
{
    rear=0;
    size=n;
}
bool isFull()
{
    if((front==0 && rear=size-1)||front=rear+1) return true;
    return false;
}
bool isEmpty()
{
    return front==-1;
}
void insertFront(int key)
{
    if(isFull()) {
        cout << "Overflow\n";return;
    }
    if(front==-1) front=rear=0;
    else if(front==0) front=size-1;
    else front-=1;

    ara[front]=key;

}
void insertRear(int key)
{
    if(isFull()) {
        cout << "Overflow\n";return;
    }
    if(front==-1){
        front=rear=0;
    }
    else if(rear==size-1) rear=0;
    else rear+=1;
    ara[rear]=key;
}
void deleteFront()
{
    if(isEmpty()) {
        cout << "Underflow\n";
        return;
    }
    if(front==rear) front=rear=-1;
    else {
        if(front==size-1) front=0;
        else front+=1;
    }
}
void deleteRear()
{
    if(isEmpty()) {
        cout << "Underflow\n";return;
    }
    if(front==rear) front=rear=-1;
    else if(rear==0) rear=size-1;
    else rear -=1;
}

int getFront(){
    if(isEmpty()) return -1;
    return ara[front];
}
int getRear(){
    if(isEmpty() || rear<0) return -1;
    return ara[rear];
}

int main()
{
    Deque(5);

    insertFront(10);
    insertFront(7);
    insertFront(15);

    for(int i=0;)

    return 0;
}
