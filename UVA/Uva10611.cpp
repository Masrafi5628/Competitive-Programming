#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int camp[1005],N,K;

bool Binary_Search(int x,int y)
{
    int c_sum=0,part=0;

    for(int i=0;i<=y;i++){
        c_sum+=camp[i];
        if(c_sum>x){
            ++part;
            c_sum=camp[i];
        }
    }
    cout << "part " <<part<<endl;
    return part<=K;
}

int main()
{
    int i,j,T,sum,low,mid,high,ans,temp;
    int *max1;
    cin>>T;

    for(i=1;i<=T;i++){
        sum=0;
        temp=0;
        cin>>N>>K;
        for(j=0;j<=N;j++){
            cin>>camp[j];
            sum+=camp[j];
        }
        max1=max_element(camp,camp+N);

        low=*max1;
        high=sum;

        while(low<=high){
            mid=(low+high)/2;
            cout << "mid "<<mid<<endl;

            if(Binary_Search(mid,N)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        cout << "Case "<<i<<':'<< ans<<endl;
        for(j=0;j<=K;j++){
            temp=camp[j]+camp[j+1];
            if(temp>ans){
                cout <<camp[j]<<endl;
                temp=0;
            }
            else {
                cout <<ans<<endl;
                temp=0;
            }
        }

    }

    return 0;
}
