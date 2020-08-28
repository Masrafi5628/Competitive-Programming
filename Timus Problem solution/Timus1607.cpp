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
	int a, b, c, d;
	cin>>a>>b>>c>>d;

	bool ck = false;
	while(a < c){
		a += b;
		c -= d;
		ck = true;
	}
	if(ck)
		printf("%d\n", min(a, c+d));
	else 
		printf("%d\n", a);
	
	return 0;
}