#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    map<string,int> mp;
    char str[15][20];
    char temp[20];

    bool ck=false;
    while(scanf("%d",&n) != EOF){

        if(ck) printf("\n");
        for(int i=0;i<n;i++){
            cin>>str[i];
            mp[str[i]]=0;
        }
        int a,b;
        for(int j=0;j<n;j++){
            cin>>temp>>a>>b;

            if(b) mp[temp]-=((a/b)*b);

            for(int l=0;l<b;l++){
                cin>>temp;
                mp[temp]+=(a/b);
            }
        }
        for(int p=0;p<n;p++){
            printf("%s %d\n",str[p],mp.at(str[p]));
        }
        ck=true;
    }

    return 0;
}
