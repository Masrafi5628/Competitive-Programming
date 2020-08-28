#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;

vector<ll>v;

ll LCM(ll a, ll b)
{
	return (a*b)/__gcd(a , b);
}

int solve(int idx, int cnt , ll r, ll lcm)
{
	if(idx == v.size()) {
		if(!cnt) return 0;
		else if(cnt%2) return r/lcm;
		return -r/lcm;
	}
	int ans  = 0;
	ans += solve(idx+1, cnt+1, r, LCM(lcm, v[idx]));
	ans += solve(idx+1, cnt, r, lcm);

	return ans;
}

int main()
{
	
	int t;
	scanf("%d", &t);

	while(t--){
		ll n, m, a, d;
		//vector<ll>v;

		scanf("%lld%lld%lld%lld", &n, &m, &a, &d);
		for(ll i=0; i<5; i++){
			v.pb(a+(i*d));
		}
		int ans1= solve(0, 0, m, 1);
		int ans2=solve(0, 0, n-1, 1);

		printf("%d\n", (m-n+1) - (ans1-ans2));
		v.clear();
		
	}

	return 0;
}