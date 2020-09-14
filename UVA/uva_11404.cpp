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

char str[1100];
int len;
int dp[1100][1100];
map<pii, string>mp;
//string a, b;

string solve(int i, int j)
{
	//printf("i %d j %d\n", i, j);
	if(i > j) return "";
	if(dp[i][j] != -1) return mp[{i, j}];

	if(str[i] == str[j]) {
		//printf("%c\n", str[i]);
		dp[i][j] = 1;
		if(i != j) return mp[{i, j}] = str[i]+solve(i+1, j-1)+str[j];
		return mp[{i, j}] = str[i]+solve(i+1, j-1);
	}else {
		string a, b;
		a = solve(i+1, j);
		b = solve(i, j-1);
		dp[i][j] = 1;
		int len1, len2;
		len1 = a.size(), len2 = b.size();
		//printf("ans1 %s\nans2 %s\n", a.c_str(), b.c_str());
		if(len1 > len2) return mp[{i, j}] = a;
		else if(len1 < len2) return mp[{i, j}] = b;
		else {
			//printf("str1 %s str2 %s\n", a.c_str(), b.c_str());
			for(int k=0; k<len1; k++) {
				if(a[k] > b[k]) return mp[{i, j}] = b;
				else if(a[k] < b[k]) return mp[{i, j}] = a;
			}
			return mp[{i, j}] = a;
		}
	}
}

int main()
{
	while(scanf("%s", str) != EOF) {
		//mp.clear();
		memset(dp, -1, sizeof dp);
		len = strlen(str);
		cout << solve(0, len-1) << endl;
	}

    return 0;
}