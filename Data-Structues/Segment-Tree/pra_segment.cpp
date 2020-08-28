#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int sz = 100005;
ll ara[sz];
ll tree[4*sz];
ll lazy[4*sz];

void updateRange(int node, int st, int ed, int l, int r, int val)
{
	if(lazy[node] != 0){
		tree[node] += (ed-st+1)*lazy[node];
		if(st != ed){
			lazy[node*2+1] += lazy[node];
			lazy[node*2+2] += lazy[node];
		} 
		lazy[node]=0;
	}
	if(ed<l || r<st)
		return;
	if(st>=l && ed<=r){
		tree[node] += (ed-st+1)*val;
		if(st != ed){
			lazy[node*2+1] += val;
			lazy[node*2+2] += val;
		}
		return;
	}
	int mid = st+(ed-st)/2;
	updateRange(node*2+1, st, mid, l, r, val);
	updateRange(node*2+2, mid+1, ed, l, r, val);

	tree[node] = tree[node*2+1]+tree[node*2+2];
}

ll query(int node, int st, int ed, int l, int r)
{
	if (r<st || ed<l)
		return 0;
	if(lazy[node] != 0){
		tree[node] += (ed-st+1)*lazy[node];
		if(st != ed){
			lazy[node*2+1] += lazy[node];
			lazy[node*2+2] += lazy[node]; 
		}
		lazy[node] = 0;
	}
	if(st>=l && ed<=r){
		return tree[node];
	}
	int mid = st+(ed-st)/2;
	ll p1=query(node*2+1, st, mid, l, r);
	ll p2=query(node*2+2, mid+1, ed, l, r);

	return p1+p2;
}



int main()
{
	int t, n, q, kase=1;
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &q);
		int a, x, y, v;
		//printf("Case %d:\n", kase++);
		while(q--){
			scanf("%d", &a);
			if(a==0){
				scanf("%d%d%d", &x, &y, &v);
				updateRange(0, 0, n-1, x, y, v);
			}else {
				scanf("%d%d", &x, &y);
				printf("%lld\n", query(0, 0, n-1, x, y));
			}
		}
		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
	}

	return 0;
}