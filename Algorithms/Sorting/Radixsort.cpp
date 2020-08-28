#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void count_sort(long long ara[],int n,long long place)
{
    int freq[10]={0},output[n];

    for(int i=0;i<n;i++)
        freq[(ara[i]/place)%10]++;

    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
        //cout <<freq[i]<< ' ';
    }

    for(int i=n-1;i>=0;i--){
        output[freq[(ara[i]/place)%10]-1]=ara[i];
        freq[(ara[i]/place)%10]--;
    }
    cout <<endl;
    for(int i=0;i<n;i++){
        ara[i]=output[i];
        cout <<ara[i]<< ' ';
    }

    cout <<endl;
}

void radix_sort(long long ara[],int n,long long maxx)
{
    int mul=1;
    while(maxx){
        count_sort(ara,n,mul);
        mul=mul*10;
        maxx=maxx/10;
    }
}

int main()
{
    long long ara[1005],max=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
        if(max<ara[i]) max=ara[i];
    }
    radix_sort(ara,n,max);

    return 0;
}
