#include <bits/stdc++.h>

using namespace std;

int ara[55];
int dp[55][55];

int solve(int s, int e)
{
    if(s+1 == e) return 0;
    if(dp[s][e] != -1)
        return dp[s][e];

    int cost = 0;
    int ans = INT_MAX;
    for(int i=s+1; i<e; i++){
        cost = solve(s, i)+solve(i, e)+ara[e]-ara[s];
        ans = min(ans, cost);
    }
    return dp[s][e] = ans;
}

int main()
{
    int len, n;
    while(cin>>len, len!=0){
        cin>>n;
        memset(dp, -1, sizeof dp);
        
        ara[0] = 0;
        for(int i=1; i<=n ; i++){
            cin>>ara[i];
        }
        ara[n+1] = len;
        printf("The minimum cutting is %d.\n", 
            solve(0, n+1));
    }

    return 0;
}