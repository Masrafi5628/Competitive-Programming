#include <bits/stdc++.h>

using namespace std;

int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
void max_heap(int *heap,int s,int i)
{
    int l,r,lar,t;
    l=left(i);r=right(i);

    if(l<=s && heap[l]>heap[i]) lar=l;
    else lar=i;
    if(r<=s && heap[r]>heap[lar]) lar=r;

    if(lar!=i){
        t=heap[i];
        heap[i]=heap[lar];
        heap[lar]=t;

        s-=1;
        max_heap(heap,s,lar);
    }
}
void buildmaxheap(int *heap,int s)
{
    for(int i=s/2;i>=1;i--){
        max_heap(heap,s,i);
    }
}
int extract_max(int *heap,int s)
{
    int max=heap[1];
    heap[1]=heap[s];

    max_heap(heap,s,1);
    return max;
}
void Insert(int *heap,int s,int node)
{
    s+=1;
    int i=s;
    heap[s]=node;

    while(i>1 && heap[i]>heap[i/2]){
        int p=i/2,t;

        t=heap[p];
        heap[p]=heap[i];
        heap[i]=t;
        i=p;
    }
    return;
}

int main()
{
    int heap[]={0,12,7,1,3,10,17,19,2,5};
    buildmaxheap(heap,9);

    cout <<extract_max(heap,9)<<endl;
    Insert(heap,9,45);

    for(int i=0;i<10;i++) {
        printf("%d ",heap[i]);
    }
    printf("\n");


    return 0;
}
