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



int main()
{
	int n;
	while(cin>>n, n){
		int cnt =0, pr = n*(n-1)/2;
		int ara[n+2];

		for(int i=0; i<n; i++){
			cin>>ara[i];
		}
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(__gcd(ara[i], ara[j]) == 1) {
					cnt++;
				}
			}
		}
		if(cnt) {
			double ans = sqrt((6*pr*1.0)/cnt);
			printf("%.6f\n", ans);
		}else {
			printf("No estimate for this data set.\n");
		}
	}
	
	return 0;
}