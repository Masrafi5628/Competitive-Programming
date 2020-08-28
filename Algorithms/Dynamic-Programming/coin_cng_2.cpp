#include <bits/stdc++.h>

using namespace std;

// Number of unique ways to get n taka using coins infinite times
int main()
{
    int t=4;
    int coin[]={1, 5, 10, 25, 50},dp[100][100];
    int len=sizeof(coin)/sizeof(coin[0]);

    
    memset(dp, 0, sizeof dp);

    for(int i=0;i<=len;i++)
        dp[i][0]=1;

    for(int i=1;i<=len;i++){
        for(int j=1;j<=t;j++){
            if(j>=coin[i-1]) {
                //printf("i-1 %d\n", i);
                dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    printf("dp %d\n", dp[len][t]);
    printf("Number of ways to get %d is %d\n",t,dp[len][t]);

    return 0;
}
