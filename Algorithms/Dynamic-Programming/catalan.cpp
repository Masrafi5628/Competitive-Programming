#include <bits/stdc++.h>

using namespace std;

//Time Complexity O(n^2)
long long findCatalanNumber(int n)
{

	long long dp[n+1];
	dp[0]=dp[1]=1;// base case

	for(int i=2;i<=n;i++){
		dp[i]=0;

		for(int j=0;j<i;j++){
			dp[i] += dp[j]*dp[i-j-1];// formula of catalan number
		}
	}
	return dp[n];
}
//Time Complexity O(n)

int nCr(int n,int r)
{
	int res=1;
	if(r>n-r)
		r=n-r;

	for(int i=0;i<r;i++){
		res = res*(n-i);
		res = res/(i+1);
	}
	return res;
}

long long catalan(int n)
{
	return nCr(2*n,n)/(n+1);
}

int main()
{
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
		cout << catalan(i) <<endl;

	return 0;
}