/// Insert node
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* head;

void insert(int data,int n)
{
    Node* temp1=new Node();
    temp1->data=data;
    temp1->next=NULL;

    if(n==1){
       // temp1->next=head;
        head=temp1;
        return;
    }
    Node* temp2=head;
    for(int i=0;i<n-2;i++){
        temp2=temp2->next;
    }
    //temp1->next=temp2->next;
    temp2->next=temp1;
}
void print()
{
    Node* temp=head;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    head=NULL;
    insert(12,1);
    insert(10,2);
    insert(2,3);
    insert(7,4);
    insert(15,5);

    print();

    return 0;
}
