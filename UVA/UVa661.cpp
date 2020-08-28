#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,c,ara[25],kase=1;
    bool ck[25];

    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);

    while(scanf("%d%d%d",&n,&m,&c), n && m && c){

        for(int i=0;i<n;i++){
            cin>>ara[i];
            ck[i]=false;
        }
        int a,ans=INT_MIN,sum=0;
        bool b=false;
        while(m--){
            cin>>a;

            if(ck[a-1]){
                sum-=ara[a-1];
                ck[a-1]=false;
            }else {
                sum+=ara[a-1];
                ck[a-1]=true;
            }

            ans = max(ans,sum);
            if(sum>c) {
                b=true;
            }
        }
        printf("Sequence %d\n",kase++);
        if(b){
            printf("Fuse was blown.\n\n");
        }else {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n",ans);
        }
    }

    return 0;
}

