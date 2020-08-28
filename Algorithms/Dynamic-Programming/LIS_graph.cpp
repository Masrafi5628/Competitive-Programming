#include <bits/stdc++.h>

using namespace std;

const int inf = 111111;
int ara[]={-inf, 5, 0, 9, 2, 7, 3, 4};
int dp[111], dir[111];
int n = 7;


// longest path in DAG will give the
// longest increasing subsequence of array
// 1 2 3 4 5 6 7
// 5 0 9 2 7 3 4
int Longest(int u)
{
	if(dp[u] != -1 ) return dp[u];
	int maxi = 0;

	for(int v=u+1; v<=n; v++){
		if(ara[u]<ara[v]){//edge check
			if(Longest(v)>maxi){
				printf("v %d len %d\n", v, Longest(v));
				maxi = Longest(v);
				dir[u] = v;
			}
		}
	}
	printf("u %d maxi %d\n", u, maxi);
	dp[u] = 1+maxi;
	return dp[u];
}

void soln_print(int start)
{
	while(dir[start] != -1){
		printf("%d ", ara[start]);
		start = dir[start];
	}
	printf("%d\n", ara[start]);
}

int main()
{
	memset(dp, -1, sizeof dp);
	memset(dir, -1, sizeof dir);

	int lis = 0, start;

	for(int i=1; i<=n; i++){
		printf("Longest path from %d is %d\n", i, Longest(i));
		if(Longest(i) > lis){
			lis = Longest(i);
			start = i;
		}
	}
	printf("LIS = %d starting point %d\n", lis, start);
	soln_print(start);

    return 0;
}
