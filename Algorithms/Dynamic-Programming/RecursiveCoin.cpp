#include <bits/stdc++.h>

using namespace std;

const int inf = 11111;

vector<int>coins;
int dp[111];
int soln[111];// kon kon coin use korci
int cnt[111]; // koto vabe banano jai

// Time Complexity of all solution is O(nk)
// n = joto banate hbe
// k = coin sonka

// n banate minimum koita coin lagbe
// recursive solution
int solve(int n)
{
	if(n<0) return inf;
	if(n == 0) return 0;
	if(dp[n] != -1)
		return dp[n];

	int best = inf;
	for(auto c:coins){
		best = min(best, solve(n-c)+1);
	}
	return dp[n] = best;
}

// iterative solution
int solve2(int n)
{
	int dp2[n+1];
	//memset(dp2, 0, sizeof dp2);

	dp2[0] = 0;
	for(int x=1; x<=n; x++){// x hocee 1 teke n tk banano
		dp2[x] = inf;
		for(auto c: coins){
			if(x-c>=0){
				dp2[x] = min(dp2[x], dp2[x-c]+1);
				soln[x] = c;// c niye x banaici
			}
		}
	}
	return dp2[n];
}

// constructing solution
// print which coin is used

void print(int n)
{
	while(n>0){
		cout<<soln[n]<< ' ';
		n -= soln[n];
	}
}


// counting number of solutions
// how many ways to build n tk
// recursive solution

int rec_ways(int n)
{
	if(n<0) return 0;
	if(n==0) return 1;
	if(cnt[n] != -1)
		return cnt[n];

	int ans = 0;
	for(auto c: coins){
		ans += rec_ways(n-c);
	}
	return cnt[n] = ans;
}

int itr_ways(int n)
{
	int count[n+1];
	memset(count, 0, sizeof count);

	count[0] = 1;

	for(int x=1; x<=n ; x++){
		for(auto c: coins){
			if(x-c>=0) {
				count[x] += count[x-c];
			}
		}
	}
	return count[n];
}


int main()
{
	int n, coin;
	cin>>coin>>n;// n banate hbe

	memset(dp, -1, sizeof dp);
	memset(cnt, -1, sizeof cnt);

	for(int i=0; i<coin; i++){
		int inp;
		cin>>inp;
		coins.push_back(inp);
	}

	//cout<<solve2(n)<<endl;
	//print(n);

	//cout<<rec_ways(n)<<endl;
	cout<<itr_ways(n)<<endl;

	return 0;
}