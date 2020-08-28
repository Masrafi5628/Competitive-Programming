#include <iostream>

using namespace std;

int partition (int *A,int start,int end)
{
    int pivot=A[end];
    int partition_index=start;

    for(int i=start;i<end;i++){
        if(A[i]<=pivot){
            swap(A[i],A[partition_index]);
            partition_index++;
        }
    }
    swap(A[partition_index],A[end]);
    return partition_index;
}
void quicksort(int *A,int start,int end)
{
    if(start<end){
        int partition_index=partition(A,start,end);
        quicksort(A,start,partition_index-1);
        quicksort(A,partition_index+1,end);
    }
}
int main()
{
    int A[]={7,6,5,4,3,2,1,0};
    quicksort(A,0,7);

    for(int i=0;i<8;i++)
        cout<<A[i]<< " ";
}
