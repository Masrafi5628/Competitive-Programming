#include <bits/stdc++.h>

using namespace std;

const int sz = 400000016;

typedef long long ll;

ll cnt_zero(ll n)
{
	ll cnt = 0;
	for(ll i = 5; n/i>=1; i *=5){
		cnt += n/i;
	}
	return cnt;
}

ll bnsrc(ll trgt)
{
	ll lo = 1, hi = 900000000, mid;
	while(lo<=hi){
		mid = lo+(hi-lo)/2;
		ll temp = cnt_zero(mid); 
		if(temp==trgt){
			return mid;
		}
		else if(temp<trgt){
			lo = mid+1;
		}else {
			hi = mid-1;
		}
	}
	return -1;
}

int main()
{
	int t, kase= 1;
	cin>>t;

	while(t--){
		ll q;
		cin>>q;
		ll ans = bnsrc(q);
		if(ans != -1){
			printf("Case %d: %lld\n", kase++, ans-(ans%5));
		}else {
			printf("Case %d: impossible\n", kase++);
		}
	}

	return 0;
}