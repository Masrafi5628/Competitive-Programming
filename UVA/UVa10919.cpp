#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,m;
    char str[105][5],temp[5];

    while(scanf("%d",&k), k && 1){
        map<string,bool> mp;

        cin>>m;
        for(int i=0;i<k;i++){
            cin>>str[i];
            mp[str[i]]=true;
        }

        int r,c;
        bool ck = true;
        for(int j=0;j<m;j++){
            cin>>r>>c;
            for(int p=0;p<r;p++){
                cin>>temp;
                if(mp[temp]) {
                    c--;
                }
            }
            if(c<=0) continue;
            else {
                ck=false;
            }
        }
        if(ck) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
