#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int>v;

int losagu(int a, int b)
{
	return (a*b)/__gcd(a, b);
}

int solve(int idx, int cnt, int r, int lcm)
{
	// idx->kon element nici
	// cnt->koita element nice
	if(idx == v.size()) {
		printf("cnt %d lcm %d\n", cnt , lcm);
		if(cnt == 0)
			return 0;
		if(cnt%2) 
			return r/lcm;
		return -(r/lcm);
	}
	int ans = 0;
	ans += solve(idx+1, cnt+1, r, losagu(lcm, v[idx]));
	ans += solve(idx+1, cnt, r, lcm);

	return ans;
}

int main()
{
	int n, r;
	cin>>n>>r;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v.pb(x);
	}

	printf("ans = %d\n", solve(0, 0, r, 1));

	return 0;
}