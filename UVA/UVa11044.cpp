#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n,m,ans=1;

        cin>>n>>m;
        if((n-2)%3==0) ans*=(n-2)/3;
        else ans*=((n-2)/3)+1;
        if((m-2)%3==0) ans*=(m-2)/3;
        else ans*=((m-2)/3)+1;

        cout <<ans<<endl;

    }

    return 0;
}
