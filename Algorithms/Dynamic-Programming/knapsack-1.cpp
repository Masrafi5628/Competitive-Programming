#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,w;
    int wt[105];
    long long val[105];

    cin>>n>>w;
    vector< vector<long long> >dp(n+1,vector<long long> (w+1));

    for(int i=0;i<n;i++){
        cin>>wt[i+1]>>val[i+1];
        dp[i][0]=0;
        dp[0][i]=0;
    }
    dp[n][0]=dp[0][n]=0;

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

    cout << dp[n][w] <<endl;

    return 0;
}
