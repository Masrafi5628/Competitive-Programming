#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define pi acos(-1)
#define inf 1<<30


using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main()
{
	int n, q;
	cin>>n;
	vector<int>v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	cin>>q;
	while(q--) {
		int x;
		cin>>x;

		int lo=0, hi=n-1, mid;
		int a = -1;
		while(lo <= hi) {
			mid = lo+(hi-lo)/2;
			if(v[mid] < x) {
				a = v[mid];
				lo = mid+1;
			}else {
				
				hi = mid-1;
			}
		}
		auto b = ub(v.begin(), v.end(), x);

		a==-1?printf("X "):printf("%d ", a);
		if(b != v.end()) {
			printf("%d\n", *b);
		}else {
			printf("X\n");
		}
	}

	return 0;
}