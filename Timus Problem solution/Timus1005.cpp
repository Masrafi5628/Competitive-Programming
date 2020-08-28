#include <bits/stdc++.h>

using namespace std;

int ans=0,sum=0,n,ara[20];

void backtrack(int at,int group1sum)
{
    if(at==n){
        ans=min(ans,abs(sum-group1sum*2));
        return;
    }
    backtrack(at+1,group1sum);
    backtrack(at+1,group1sum+ara[at]);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
        sum+=ara[i];
    }
    ans=sum;

    backtrack(0,0);
    cout <<ans<<endl;

    return 0;
}
