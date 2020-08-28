#include <bits/stdc++.h>

using namespace std;

const long long sz = 1e5+5;

typedef  long long ll;
typedef  pair<ll, ll> pii;

ll ara[sz];
ll ans=INT_MIN, temp;

pii tree[4*sz];

void build_segment(ll node, ll st, ll ed)
{
	if(st == ed){
		tree[node]= {st, ara[st]};
		return;
	}
	ll mid = st+(ed-st)/2;

	build_segment(node*2, st, mid);
	build_segment(node*2+1, mid+1, ed);

	if(tree[node*2].second > tree[node*2+1].second)
		tree[node] = tree[node*2+1];
	else 
		tree[node] = tree[node*2];
}

ll find_min(ll node, ll st, ll ed, ll l, ll r)
{
	if(r<st || ed<l)
		return 0;
	if(l<=st && ed<=r){
		return tree[node].first;
	}
	ll mid = st+(ed-st)/2;

	ll a = find_min(node*2, st, mid, l, r);
	ll b = find_min(node*2+1, mid+1, ed, l, r);

	if(ara[a]>ara[b]){
		return b;
	}else {
		return a;
	}
}

void largest_rectangle(ll l, ll r, ll n)
{
	if(l<=0 || r>n || l>r || r<=0)
		return ;
	//cout<< "l "<<l << " r "<<r<< "\n";
	ll x = find_min(1, 1, n, l, r);
	//cout<<x<<endl;
	temp = ara[x]*(r-l+1);
	if(temp>ans)
		ans = temp;
	//cout<<ans<<endl;
	largest_rectangle(l, x-1, n);
	largest_rectangle(x+1, r, n);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    ll n;

	while(cin>>n, n!=0){
		ara[0] = 1e10;
		for(ll i=1; i<=n; i++){
			cin>>ara[i];
		}

		build_segment(1, 1, n);

		largest_rectangle(1, n, n);

		cout<<ans<<endl;

		memset(tree, 0, sizeof tree);
		ans = INT_MIN;

	}

	return 0;
}