#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t,n,a,b,c;
    long long ans;

    cin>>t;
    while(scanf("%lld",&n)!=EOF){
        ans=0;
        while(n--){
            cin>>a>>b>>c;
            ans+=a*c;
        }
        cout <<ans<<endl;
    }

    return 0;
}
