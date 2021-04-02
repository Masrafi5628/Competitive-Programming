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

string str[111];
bool vis[111][111];
int n, m;

bool ok(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m && str[r][c] == '@';
}

void dfs(int r, int c)
{
    if(vis[r][c]) return;
    vis[r][c] = true;

    
    for(int i = 0; i < 8; i++) {
        int rr = r+dr[i];
        int cc = c+dc[i];

        if(ok(rr, cc) && !vis[rr][cc]) dfs(rr, cc);
    }
}

void solve()
{
    while(cin >> n >> m, n) {
        for(int i = 0; i < n; i++) {
            cin >> str[i];
        }

        int ans = 0;
        memset(vis, false, sizeof vis);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && str[i][j] == '@') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    fast_io;

    int tt = 1;

    //cin >> tt;

    while(tt--) {
        solve();
    }
 
    return 0;
}
