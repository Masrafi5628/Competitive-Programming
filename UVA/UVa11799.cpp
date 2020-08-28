#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,kase=1,n,ara[100];
    cin>>t;

    while(t--){
        int ans = INT_MIN;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ara[i];
            if(ara[i]>=ans) ans = ara[i];
        }
        printf("Case %d: %d\n",kase++,ans);
    }

    return 0;
}

