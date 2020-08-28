#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ll n;
	while(scanf("%lld", &n), n) {
		ll cnt = sqrt(n)+1e-9;

		if(cnt*cnt != n)
			printf("no\n");
		else 
			printf("yes\n");
	}

	return 0;
}