#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k, t, kase=1;
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &k);// k poriman banate hbe
		int coin[n+1];
		int dp[k+1][n+1];

		memset(dp, 0, sizeof dp);

		for(int i=0; i<n; i++){
			scanf("%d", &coin[i]);
			dp[0][i] = 1;// 0 banano jai sob coin use kore
		}

		for(int i=1; i<=k; i++){
			for(int j=0; j<n; j++){
				if(i-coin[j] >=0){
					dp[i-coin[j]][j] = 0;
				}
				if(j>=1){
					dp[i][j-1] = 0;
				}
				dp[i][j] = dp[i-coin[j]][j] + dp[i][j-1];
			}
		}
		printf("Case %d: %d\n", kase++, dp[k][n-1]);
	}

	return 0;
}