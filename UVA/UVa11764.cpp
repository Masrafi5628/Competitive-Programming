#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,ara[100],kase=1;

    cin>>t;

    while(t--){
        int l=0,s=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ara[i];
        }
        for(int j=1;j<n;j++){
            if(ara[j-1]<ara[j]) l++;
            else if(ara[j-1]>ara[j]) s++;
        }
        printf("Case %d: %d %d\n",kase++,l,s);
    }

    return 0;
}
