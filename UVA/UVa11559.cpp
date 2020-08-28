
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,b,h,w,p;
    long long ans,ara[15],t;

    while(scanf("%d%d%d%d",&n,&b,&h,&w) != EOF){

        ans= INT_MAX,t=INT_MAX;
        while(h--){
            cin>>p;
            for(int i=0;i<w;i++){
                cin>>ara[i];
                if(ara[i]>=n) t=n*p;
                ans = min(ans,t);
            }
        }

        if(ans<=b) cout << ans<<endl;
        else cout << "stay home\n";

    }

    return 0;
}
