///Inserting data at beginning

#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head;


void insert(int x)
{
    Node* temp=new Node();
    temp->data=x;
    temp->next=head;
    head=temp;
}
void print()
{
    Node* temp1=head;
    printf("List is :");
    while(temp1 != NULL){
        printf(" %d",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
}
int main()
{
    head=NULL;
    int n,x;
    printf("How many numbers\n");
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        insert(x);
        print();
    }

    return 0;
}
