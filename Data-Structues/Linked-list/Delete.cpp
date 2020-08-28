/// Delete node

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* head;

void insert(int data)
{
    Node* temp=new Node();
    temp->data=data;
    temp->next=head;
    head=temp;
}
void print()
{
    Node* temp1=head;

    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
}
void Delete(int n)
{
    Node* temp1=head;
    if(n==1){
        head=temp1->next;
        free(temp1);
        return;
    }
    for(int i=0;i<n-2;i++){
        temp1=temp1->next;
    }
    Node* temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
}
int main()
{
    head=NULL;

    insert(2);
    insert(4);
    insert(6);
    insert(5);

    print();
    int n;
    cout << "Enter position\n";
    cin>>n;
    Delete(n);
    print();

    return 0;
}
