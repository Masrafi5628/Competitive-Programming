#include <bits/stdc++.h>

using namespace std;

int st[111] = {1,2,5};//{3, 34, 4, 12, 5,	2};

// Recursive solution 
// Exponential time
bool isPsbl(int n, int sum)
{
	//printf("n %d sum %d\n", n, sum);
	if(sum == 0)
		return true;
	if(sum > 0 && n==0)
		return false;

	// if last element is greater than sum
	// then don't include it
	if(st[n-1] > sum){
		return isPsbl(n-1, sum);
	}
	
	// 1. exclude last element
	// 2. include last element
	return isPsbl(n-1, sum) || isPsbl(n-1, sum-st[n-1]);
}


// DP solution
// O(sum*n)

bool solve(int n, int sum)// n ta elem, sum banate hbe
{
	bool dp[n+1][sum+1];

	for(int i=0; i<=n; i++){
		dp[i][0] = true;// sum = 0 hle
	}
	for(int i=1; i<=sum ; i++){
		dp[0][i] = false;// i = 1, 2, .., sum
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			if(j<st[i-1]){
				dp[i][j] = dp[i-1][j];
			}else {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-st[i-1]];
			}
		}
	}
	return dp[n][sum];
}


// Space Optimization O(sum)

bool solve_2(int n, int sum)
{
	bool dp[2][sum+1];

	for(int i=0; i<=n; i++){
		for(int j=0; j<=sum; j++){
			if(j==0){
				dp[i%2][j] = true;
			}
			else if(i==0){
				dp[i%2][j] = false;
			}
			else if(j<st[i-1]){
				dp[i%2][j] = dp[(i+1)%2][j];
			}
			else {
				dp[i%2][j] = dp[(i+1)%2][j] || 
							dp[(i+1)%2][j-st[i-1]];
			}
		}
	}
	return dp[n%2][sum];
}

int main()
{
	int n=6, sum = 0;

	/*if(isPsbl(n, sum)){
		printf("Found a subset with given sum\n");
	}else {
		printf("subset not found\n");
	}

	if(solve(n, sum)){
		printf("Found a subset with given sum\n");
	}else {
		printf("subset not found\n");
	}
	*/
	if(solve_2(n, sum)){
		printf("Found a subset with given sum\n");
	}else {
		printf("subset not found\n");
	}

	return 0;
}