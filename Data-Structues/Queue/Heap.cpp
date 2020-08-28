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
int parent(int i)
{
    return i/2;
}

void max_heap(int *heap,int heap_size,int i)
{
    int l,r,largest,t;
    l=left(i);
    r=right(i);

    if(l<=heap_size && heap[l]>heap[i])
        largest=l;
    else
        largest=i;

    if(r<=heap_size && heap[r]>heap[largest])
        largest=r;

    if(largest!=i){
        t=heap[i];
        heap[i]=heap[largest];
        heap[largest]=t;

        max_heap(heap,heap_size,largest);
    }
}

void buildmaxheap(int *heap,int heap_size)
{
    for(int i=heap_size/2;i>=1;i--){
        max_heap(heap,heap_size,i);
    }
}

int main()
{
    int heap[]={0,12,7,1,3,10,17,19,2,5};
    buildmaxheap(heap,9);

    for(int i=0;i<10;i++)
        cout <<heap[i]<< " ";

    return 0;
}
