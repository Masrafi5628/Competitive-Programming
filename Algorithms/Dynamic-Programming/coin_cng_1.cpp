#include <bits/stdc++.h>

using namespace std;

const int mod = 100000007;


/*void tle()
{
    int dp[10005][105];// runtime error
    scanf("%d%d", &n, &k);// k poriman banate hbe
        int coin[n+1];
        

        memset(dp, 0, sizeof dp);

        for(int i=0; i<n; i++){
            scanf("%d", &coin[i]);
            dp[0][i] = 1;// 0 banano jai sob coin use kore
        }

        for(int i=1; i<=k; i++){
            for(int j=0; j<n; j++){

                int x = (i-coin[j]>=0)?dp[i-coin[j]][j]:0;
                int y = (j>=1)?dp[i][j-1]:0;

                dp[i][j] = ((x%mod)+(y%mod))%mod;
            }
        }
        printf("Case %d: %d\n", kase++, dp[k][n-1]);
}*/

int  kase=1;
void accepted()
{
    int n, k;
    scanf("%d%d", &n, &k);// k poriman banate hbe
    int coin[n+1];

    for(int i=0; i<n; i++){
        scanf("%d", &coin[i]);
    }

    int dp[k+1];

    memset(dp, 0, sizeof dp);

    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j] = ((dp[j]%mod)+(dp[j-coin[i]])%mod)%mod;
        }
    }
    printf("Case %d: %d\n", kase++, dp[k]);
}

int main()
{
    int n, k, t, kase=1;
    scanf("%d", &t);

    while(t--){
        accepted();
    }

    return 0;
}