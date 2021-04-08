#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
 
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
//#define inf 1<<30
 
// isupper() -> upper case check
// tolower() -> convert upper to lower case
// idx = str.find("bear", pos)) != string::npos =>substring find
// Tuple access -> get<0>(v[i])
// cmnt - ctrl []
// stoi("...") -> decimal
// istringstream ss(str) while(ss >> n)
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;
 
const ll inf = 2e18+100;
const ll mod = 1e9+7;
const double epsilon = 0.001;
 
//int dr[] = {-1, 0, 1,  0};// up, right, down, left
//int dc[] = { 0, 1, 0, -1};
 
// King moves similar to 8 direction
int dr[] = {-1, -1, 0, 1, 1,  1, 0, -1};
int dc[] = { 0,  1, 1, 1, 0, -1,-1, -1};
 
// Knight moves
int kr[] = {-1,  1, -2, -2, -1, 1,  2,  2};
int kc[] = {-2, -2, -1,  1,  2, 2, -1,  1};
// diagonal moves
int dgr[] = {-1, -1,  1, 1};
int dgc[] = { 1, -1, -1, 1};

const int N = 110;

vector<string>grid;
int des_row, des_col, row, col;
queue<pair<pii, int> >kue;

bool ok(int r, int c)
{
	return r >= 0 && r < row && c >= 0 && c < col;
}

int bfs()
{
	bool vis[N][N];

	memset(vis, false, sizeof vis);

	while(!kue.empty()) {
		int r = kue.front().ff.ff;
		int c = kue.front().ff.ss;
		int cnt = kue.front().ss;

		kue.pop();

		if(r == des_row && c == des_col) return cnt;

		if(vis[r][c]) continue;
		vis[r][c] = true;

		for(int i = 0; i < 8; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];

			if(ok(rr, cc) && grid[rr][cc] != '#' && grid[rr][cc] != 'Z' && !vis[rr][cc]) {
				kue.push({{rr, cc}, cnt+1});
			}
		}
	}
	return 999999999;
}

void solve()
{
	cin >> row >> col;
	grid.clear();
	grid.resize(row+5);
	kue = queue<pair<pii, int> > ();

	vector<pii>horse;

	for(int i = 0; i < row; i++) cin >> grid[i];

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(grid[i][j] == 'A') {
				kue.push({{i, j}, 0});
			}
			if(grid[i][j] == 'B') {
				des_row = i;
				des_col = j;
			}
			if(grid[i][j] == 'Z') {
				horse.pb({i, j});
			}
		}
	}

	for(pii x: horse) {
		for(int i = 0; i < 8; i++) {
			int r = x.ff + kr[i];
			int c = x.ss + kc[i];

			if(ok(r, c) && grid[r][c] == '.') {
				grid[r][c] = '#';
			}
		}
	}
	/*
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
	*/
	
	int ans = bfs();

	if(ans == 999999999) printf("King Peter, you can't go now!\n");
	else printf("Minimal possible length of a trip is %d\n", ans);
}

int main()
{
    fast_io;

    int tt = 1;

    cin >> tt;

    while(tt--) {
        solve();
    }
 
    return 0;
}