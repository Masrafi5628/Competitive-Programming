/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
*/

#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

//#define inf 1<<30

// isupper() -> upper case check
// tolower() -> convert upper to lower case
// idx = str.find("bear", pos)) != string::npos =>substring find
// Tuple access -> get<0>(v[i])
// cmnt - ctrl []
// stoi("...") -> decimel
// istringstream ss(str) while(ss >> n)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;

const ll inf = 2e18;
const ll mod = 1e9+7;

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

string str;
int dp[1010][1010];

int editDist(int l, int r)
{
	if(l >= r) return 0;

	int &ret = dp[l][r];
	if(ret != -1) return ret;

	if(str[l] == str[r]) return ret = editDist(l+1, r-1);
	return ret = 1+min(editDist(l+1, r), editDist(l, r-1));
}
// store idx of palindrome
vector<int>v;
// is seq contain one/two mid
int mid;

void sol(int l, int r)
{
	if(l == r) v.pb(l), mid = 1;
	if(l >= r) return;

	if(str[l] == str[r]) {
		v.pb(l);
		sol(l+1, r-1);
	}
	else if(dp[l][r] == 1+dp[l+1][r]) {
		v.pb(l);
		sol(l+1, r);
	}
	else {
		v.pb(r);
		sol(l, r-1);
	}
}

int main()
{
	while(cin>>str) {
		memset(dp, -1, sizeof dp);
		v.clear(), mid = 0;
		int len = str.size();

		printf("%d ", editDist(0, len-1));
		sol(0, len-1);
		for(int i=0; i<v.size(); i++)
			printf("%c", str[v[i]]);

		for(int i=v.size()-1-mid; i>=0; i--)
			printf("%c", str[v[i]]);
		printf("\n");
	}

    return 0;
}