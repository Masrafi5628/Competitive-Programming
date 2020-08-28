#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX;

void solve(vector<int>v, int k)
{
	int lo=0, hi=0, sz = v.size();
	set<int>ans;
	int cnt[1111];
	memset(cnt, 0, sizeof cnt);

	int len = inf;
	
	while(lo < sz) {
		while(hi < sz && ans.size() < k) {
			if(v[hi]<=k) {
				ans.insert(v[hi]);
				cnt[v[hi]]++;
			}
			hi++;
		}
		if(ans.size() == k){
			len = min(len, hi-lo);
		}
		if(cnt[v[lo]] == 1) {
			ans.erase(v[lo]);
		}
		cnt[v[lo]]--;
		lo++;
	}
	if(len == inf) printf("sequence nai\n");
	else printf("%d\n", len);
}

int main()
{
	int t, kase=1, n, m, k;
	cin>>t;

	while(t--){
		cin>>n>>m>>k;
		vector<int>v(n);

		v[0] = 1, v[1] =2, v[2] = 3;
		for(int i=3; i<n; i++){
			v[i] = (v[i-1]+v[i-2]+v[i-3])%m+1;
		}

		printf("Case %d: ", kase++);
		solve(v, k);
	}

	return 0;
}