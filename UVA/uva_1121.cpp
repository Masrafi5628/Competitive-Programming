#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int inf = 2000000;

void solve(vector<int> v, ll trgt)
{
	int lo=0, hi = 0, sz = v.size();
	int ans = inf;
	ll sum = 0;

	while(lo < sz) {
		while(hi < sz && sum < trgt) {
			sum += v[hi];
			hi++;
		}
		if(sum >= trgt){
			ans = min(ans, hi-lo);
		}
		sum -= v[lo];
		lo++;
	}
	if(ans == inf) printf("0\n");
	else printf("%d\n", ans);
}

int main()
{
	ll n;
	ll sum;

	while(scanf("%lld%lld", &n, &sum)!=EOF) {
		vector<int>v(n+1);
		for(int i=0; i<n; i++)
			cin>>v[i];

		solve(v, sum);
		v.clear();
	}

	return 0;
}