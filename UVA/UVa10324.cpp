#include <bits/stdc++.h>

using namespace std;

int main()
{
    int kase=1;
    char str[1000005];

    while(scanf("%s",str) != EOF){
        int l=strlen(str);
        if(!l) break;

        vector<int>v(l);

        int cnt=1;
        for(int i=0;i<l;i++){
            if(i+1<l && str[i]==str[i+1]) v[i]=cnt++;
            else {
                v[i]=cnt++;
                cnt=1;
            }
        }

        int n,a,b;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a>>b;
            if(!j) printf("Case %d:\n",kase++);

            if(a>b){
                if(a-b == v[a]-v[b]) printf("Yes\n");
                else printf("No\n");
            }
            else {
                if(b-a == v[b]-v[a]) printf("Yes\n");
                else printf("No\n");
            }
        }
        v.clear();
    }

    return 0;
}

