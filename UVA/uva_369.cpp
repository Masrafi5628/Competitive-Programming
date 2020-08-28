#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define lb lower_bound
#define up upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

#define inf 1<<30


using namespace std;
using ll = long long;
using pii = pair<int, int>;

int ncr[105][105];

void solve()
{
	ncr[1][0] = ncr[1][1] = 1;
	for(int i=2; i<=100; i++){
		for(int j=0; j<=i; j++){
			ncr[i][j] = ncr[i-1][j]+ncr[i-1][j-1];
		}
	}
}

int main()
{
	int n, m;
	solve();

	while(cin>>n>>m, n || m){
		printf("%d things taken %d at a time is %d exactly.\n", n, m, ncr[n][m]);
	}
	
	return 0;
}