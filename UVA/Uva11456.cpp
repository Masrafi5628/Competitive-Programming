#include <bits/stdc++.h>

using namespace std;

const long long inf = 99999999999999;

int ara[111111];
int lis[111111];
int lds[111111];

void find_lis(int n)
{
	for(int i=0; i<n; i++)
		lis[i] = 1;

	for(int i=n-1; i>=0; i--){
		for(int j=i+1; j<n; j++){
			if(ara[i]>ara[j]){
				lis[i] = max(lis[i], lis[j]+1);
			}
		}
	}
}

void find_lds(int n)
{
	for(int i=0; i<n; i++)
		lds[i] = 1;

	for(int i=n-1; i>=0; i--){
		for(int j=i+1; j<n; j++) {
			if(ara[j]>ara[i]){
				lds[i] = max(lds[i], 1+lds[j]);
			}
		}
	}
}

void solve(int n)
{
	find_lis(n);
	find_lds(n);

	int ans = 0;
	for(int i=0; i<n; i++){
		ans = max(ans, lis[i] + lds[i]-1);
	}
	cout<<ans<<endl;
}

int main()
{
	int t, n;
	cin>>t;

	while(t--){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>ara[i];
		}
		solve(n);

		memset(lis, 0, sizeof lis);
		memset(lds, 0, sizeof lds);
	}

	return 0;
}