#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

//#define inf 1<<30

// isupper() -> upper case check
// tolower() -> convert upper to lower case
// idx = str.find("bear", pos)) != string::npos =>substring find
// Tuple access -> get<0>(v[i])
// cmnt - ctrl []
// stoi("...") -> decimel

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;

const int inf = 9999999;
const int mod = 1e9+7;

int dr[] = {-1, 0, 1,  0};// up, right, down, left
int dc[] = { 0, 1, 0, -1};

// King moves similar to 8 direction
//int dr[] = {-1, -1, 0, 1, 1,  1, 0, -1};
//int dc[] = { 0,  1, 1, 1, 0, -1,-1, -1};

// Knight moves
int kr[] = {-1,  1, -2, -2, -1, 1,  2,  2};
int kc[] = {-2, -2, -1,  1,  2, 2, -1,  1};
// diagonal moves
int dgr[] = {-1, -1,  1, 1};
int dgc[] = { 1, -1, -1, 1};

int n, k;
int ara[100005];
int dp[100005][105];

bool solve(int idx, int rem, ll sum)// rem -> remainder
{
	//printf("idx %d sum %lld rem %d\n", idx, sum, rem);
	if(idx == n)
		return rem == 0;

	if(dp[idx][rem] != -1)
		return dp[idx][rem];

	ll tmp1, tmp2, rem1, rem2;

	tmp1 = sum + ara[idx];
	rem1 = tmp1 % k;
	if(rem1 < 0)
		rem1 += k;

	tmp2 = sum - ara[idx];
	rem2 = tmp2 % k;
	if(rem2 < 0)
		rem2 += k;
	
	if(solve(idx+1, rem1, tmp1) || solve(idx+1, rem2, tmp2))
		return dp[idx][rem] = 1;

	return dp[idx][rem] = 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    	int val;
    	memset(dp, -1, sizeof dp);

    	cin>>n>>k;
    	for(int i=0; i<n; i++)
    		cin>>ara[i];

    	val = ara[0]%k;

    	if(val < 0){
    		val += k;
    	}
    	if(solve(1, val, ara[0]))
    		printf("Divisible\n");
    	else 
    		printf("Not divisible\n");
    }
    
    return 0;
}