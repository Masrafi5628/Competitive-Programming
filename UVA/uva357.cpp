#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(cin>>n){
		int coin[]={1, 5, 10, 25, 50};
		long long dp[6][n+1];

		memset(dp, 0, sizeof dp);
		for(int i=0; i<=6; i++)
			dp[i][0] = 1;

		for(int i=1; i<=5; i++){
			for(int j=1; j<=n; j++){
				if(j>=coin[i-1]){
					dp[i][j] = dp[i-1][j]+
							dp[i][j-coin[i-1]];
				}else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		if(dp[5][n] == 1){
			printf("There is only 1 way to produce %d cents change.\n", n);
		}else {
			printf("There are %lld ways to produce %d cents change.\n", dp[5][n], n );
		}
	}

	return 0;
}