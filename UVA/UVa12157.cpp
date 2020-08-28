#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,ara[25],kase=1;

    cin>>t;

    while(t--){
        long long cnt1=0,cnt2=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ara[i];
        }
        for(int j=0;j<n;j++){
             cnt1+=(ara[j]/30)+1;

            cnt2+=(ara[j]/60)+1;

        }
        cnt1*=10,cnt2*=15;

        printf("Case %d: ",kase++);
        if(cnt1==cnt2) printf("Mile Juice %d\n",cnt1);
        else if(cnt1>cnt2) printf("Juice %d\n",cnt2);
        else printf("Mile %d\n",cnt1);
    }

    return 0;
}

