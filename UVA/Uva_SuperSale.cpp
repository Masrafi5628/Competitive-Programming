#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,w;
    int wt[1050];
    int val[1050];
    int t;

    cin>>t;

    while(t--) {
        cin>>n;
        //vector< vector<long long> >dp(n+1,vector<long long> (w+1));
        int dp[n+1][32];// dp[i][j] = 

        for(int i=0;i<n;i++){
            cin>>val[i+1]>>wt[i+1];
        }

        int p;
        cin>>p;

        int ans = 0;
        while(p--){
            memset(dp, 0, sizeof dp);
            cin>>w;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=w;j++){
                    if(j<wt[i]) {
                        dp[i][j]=dp[i-1][j];
                    }
                    else {
                        dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i]]);
                    }
                }
            }
            ans += dp[n][w];
        }
        
        cout<<ans<<endl;
    }

    return 0;
}
