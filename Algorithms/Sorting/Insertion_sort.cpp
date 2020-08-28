#include <bits/stdc++.h>

using namespace std;

void insertionSort(int *a,int n)
{
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int ara[]={5,9,0,-1,1,4,10,6};

    insertionSort(ara,8);

    printf("Ascending order: ");
    for(int i=0;i<8;i++){
        cout<< ara[i] << ' ';
    }
    cout <<endl;

    return 0;
}
