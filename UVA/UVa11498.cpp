#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    while(scanf("%d",&t)){
        if(!t) break;
        int n,m,k=t;
        cin>>n>>m;

        while(k--){
            int a,b;
            cin>>a>>b;

            if(a==n || b==m) printf("divisa\n");
            else if(a>n && b>m) printf("NE\n");
            else if(a<n && b<m) printf("SO\n");
            else if(a<n && b>m) printf("NO\n");
            else if(a>n && b<m) printf("SE\n");

        }
    }

    return 0;
}
