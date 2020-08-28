#include <bits/stdc++.h>

using namespace std;

const int mod = 100000007;
int dp[102][1002];
int coin[102],cnt[102];
int n;

int f(int in, int rem) {

    if(rem < 0) return 0;
    if(in == n) {
        if(rem == 0) return 1;
        else return 0;
    }

    if(dp[in][rem] != -1) return dp[in][rem];

    int ans = 0;
    for(int i=0; i<=cnt[in]; i++) {
        ans = ans + f(in+1, rem-i*coin[in])%mod;
    }

    return dp[in][rem] = ans;
}


int main()
{
	int  k, t, kase=1;
	cin>>t;

	while(t--){
		cin>>n>>k;
		memset(dp, -1, sizeof dp);
		
		for(int i=0; i<n; i++)
			cin>>coin[i];
		for(int i=0; i<n; i++)
			cin>>cnt[i];

		printf("Case %d: %d\n", kase++, f(0, k));
	}

	return 0;
}

















/*#include <bits/stdc++.h>

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

#include <bits/stdc++.h>

using namespace std;

// Minimum number of coins required to build n taka
int main()
{
    int tk=21,coin[]={0,1,5,6,8};

    int dp[100][100];

    for(int i=0;i<=tk;i++)
        dp[i][0]=0,dp[0][i]=INT_MAX;

    for(int i=1;i<=4;i++){
        for(int j=1;j<=tk;j++){

            if(j>=coin[i]) 
                dp[i][j]=min(dp[i-1][j],dp[i][j-coin[i]]+1);

            else 
                dp[i][j]=dp[i-1][j];

            printf("%2d ",dp[i][j]);
        }
        cout <<endl;
    }

    printf("\n Minimum %d coins are required\n",dp[4][tk]);
    printf("Coins are ");
    int n=4;
    for(int i=tk; i>=1;){
        if(dp[n][i]>=dp[n-1][i]) {
            n--;
        }else {
            cout <<coin[n]<< ' ';
            i-=coin[n];
        }
    }
    printf("\n");

    return 0;
}

*/