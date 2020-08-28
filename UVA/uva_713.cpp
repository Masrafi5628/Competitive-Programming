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
	int t;
	cin>>t;
	while(t--){
		string a, b;
		cin>>a>>b;

		reverse(all(a));
		reverse(all(b));
		
		int la = a.size(), llb = b.size();
		vector<int>stk;
		int carry=0, sum = 0;

		for(int i=la-1, j=llb-1 ; i>=0 || j>=0 ; i--, j--){
			sum = 0;
			if(i>=0) {
				sum += a[i]-'0';
			}
			if(j>=0) {
				sum += b[j]-'0';
			}
			//printf("sum %d carry %d\n", sum , carry);
			sum += carry;
			if(!stk.empty()) {
				stk.pb(sum%10);
			}else {
				if(sum%10 != 0) {
					stk.pb(sum%10);
				}
			}
			carry = sum/10;
		}
		if(carry>0) {
			stk.pb(carry);
		}
		for(int x: stk) {
			cout<<x;
		}
		cout<<endl;
		//cout<<ans<<endl;
		}
	
	return 0;
}