#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> >v(n,vector<int>(m)),dp(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    for(int i=0;i<m;i++) dp[0][i]=1;// karon 1st row te ekvabe jawa jai
    for(int i=1;i<n;i++) dp[i][0]=1;// karon 1st col ee ekvabe jawa jai

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }

    printf("Number of ways to reach [n,m] %d\n",dp[n-1][m-1]);

    return 0;
}

