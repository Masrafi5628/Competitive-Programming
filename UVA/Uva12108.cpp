#include <bits/stdc++.h>

using namespace std;

int n,ara[100][100],status[100];

bool update()
{
    int cnt=0;
    for(int i=0;i<n;i++){
        if(status[i]<=ara[i][0]) cnt++;
    }
    if(cnt==n) return true;

    for(int i=0;i<=n;i++){
        if(status[i]==ara[i][0]+ara[i][1] || (status[i]==ara[i][0] && n<=cnt*2)) status[i]=1;
        else status[i]++;
    }
    return false;
}

int main()
{
    int kase=1;
    while(1){
        cin>>n;

        if(n==0) break;
        int l=1;
        for(int i=0;i<n;i++){
            cin>>ara[i][0]>>ara[i][1]>>ara[i][2];
            status[i]=ara[i][2];
            l=(l*(ara[i][0]+ara[i][1]))/__gcd(l,ara[i][0]+ara[i][1]);
        }
        bool fnd;
        for(int j=1;j<=l;j++){
            fnd=update();

            if(fnd){
                printf("Case %d: %d\n",kase++,j);
                break;
            }
        }
        if(!fnd) printf("Case %d: %d\n",kase++,-1);
    }

    return 0;
}
