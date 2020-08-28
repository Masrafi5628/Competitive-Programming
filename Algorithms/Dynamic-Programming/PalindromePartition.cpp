#include <bits/stdc++.h>

using namespace std;
string str;
int pal[1002][1002];
int dp[1002];

int check(int i, int j)
{
	if(pal[i][j] != 0)
		return pal[i][j];
	if(i>=j) return pal[i][j] = 1;
	if(str[i] == str[j] && check(i+1, j-1)==1){
		return pal[i][j] = 1;
	}
	return pal[i][j] = 2;
}

int solve(int pos)
{
	int ans = INT_MAX;

	if(dp[pos] != -1)
		return dp[pos];

	if(pos == str.size()) 
		return 0;
	
	for(int i=pos; i<str.size(); i++){
		if(check(pos, i) == 1){
			ans = min(ans, 1+solve(i+1));
		}
	}
	return dp[pos] = ans;
}

int main()
{
	int t, kase=1;
	cin>>t;

	while(t--){
		
		memset(dp, -1, sizeof dp);
		memset(pal, 0, sizeof pal);

		cin>>str;
		
		printf("Case %d: %d\n", kase++,
			solve(0));
	}

	return 0;
}