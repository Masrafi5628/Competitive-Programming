#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int num[200005],temp[200005];
long long cnt;

void merge_sort(int low,int high)
{
    if(low==high) return;
    int mid=(low+high)/2;

    merge_sort(low,mid);
    merge_sort(mid+1,high);

    int i,j,k;
    for(i=low,j=mid+1,k=low;k<=high;k++){

        if(i==mid+1) temp[k]=num[j++];
        else if (j==high+1) temp[k]=num[i++];
        else if (num[i]>num[j]) {
            temp[k]=num[i++];
            cnt+=high-j+1;
        }
        else temp[k]=num[j++];
    }
    for(int i=low;i<=high;i++)
        num[i]=temp[i];
}

int main()
{
    int n,t;
    cin>>t;

    cout<< " "<<endl;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>num[i];
        cout<< " "<<endl;
        merge_sort(0,n-1);

        cout<<cnt<<endl;
        cnt=0;
    }

    return 0;
}
