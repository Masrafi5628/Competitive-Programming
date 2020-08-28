#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n,w;
    int wt[105];
    long long val[105],sum=0;

    cin>>n>>w;
    vector<ll> dp(w+1);

    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    for(int i=0;i<n;i++){
        for(int j=w-wt[i]; j>=0; --j){
            dp[j+wt[i]]=max(dp[j+wt[i]],dp[j]+val[i]);
        }
    }
    ll ans = 0;

    for(ll i=0;i<=w;i++){
        ans=max(ans,dp[i]);
    }
    cout << ans <<endl;

    return 0;
}
