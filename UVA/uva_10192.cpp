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

string a, b;
int dp[1005][1005];

int solve(int i, int j, int len1, int len2)
{
	if(i < 0 || j < 0 || i >= len1 || j >= len2)
		return 0;

	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	if(a[i] == b[j]){
		return dp[i][j] = 1+solve(i+1, j+1, len1, len2);
	}else {
		return dp[i][j] = max(solve(i+1, j, len1, len2), 
			solve(i, j+1, len1, len2));
	}
}

int main()
{
	int kase = 1;
	while(getline(cin, a)){
		if(a[0] == '#')
			break;
		memset(dp, -1, sizeof dp);

		getline(cin, b);

		printf("Case #%d: you can visit at most %d cities.\n", kase++, solve(0, 0, a.size(), b.size()));
	}    
    
    return 0;
}