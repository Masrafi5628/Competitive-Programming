#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,ara[105];
    char str[100];
    cin>>t;

    while(t--){
        int a,ans=0;
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>str;
            if(str[0]=='S') {
                cin>>str;
                cin>>a;
                ara[i]=ara[a-1];
            }
            else if(str[0]=='L') ara[i]=-1;
            else ara[i]=1;

            ans+=ara[i];
        }
        cout << ans<<endl;
    }

    return 0;
}


