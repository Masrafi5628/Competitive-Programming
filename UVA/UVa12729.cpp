#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,kase=1;

    while(scanf("%d",&n)){
        if(!n) break;
        int cnt=0,a;

        for(int i=0;i<n;i++){
            cin>>a;
            if(!a) cnt++;
        }
        printf("Case %d: %d\n",kase++,(n-cnt)-cnt);
    }

    return 0;
}
