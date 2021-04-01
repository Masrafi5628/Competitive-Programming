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

vector<int>adj[110];
bool vis[111];
int src;

void dfs(int u)
{
    if(vis[u]) return;
    if(u != src) vis[u] = true;

    for(int v: adj[u]) {
        if(v == src) vis[v] = true;
        if(!vis[v]) dfs(v);
    }
}

void solve()
{
    int vertex;
    while(cin >> vertex, vertex) {
        string str;
        getline(cin, str);
        while(getline(cin, str), str[0] != '0') {
            //printf("ed %s\n", str.c_str());
            istringstream ss(str);
            int u, v;
            ss >> u;
            //printf("u %d\n", u);
            while(ss >> v) {
                //printf("v %d\n", v);
                if(!v) break;
                adj[u].eb(v);
            }
        }
        getline(cin, str);
        //printf("bb %s\n", str.c_str());

        istringstream ss(str);
        int len;// src;
        ss >> len;
        vector<int>ans;

        while(ss >> src) {
            memset(vis, false, sizeof vis);
            //printf("src %d\n", src);
            dfs(src);
            for(int i = 1; i <= vertex; i++) {
                if(!vis[i]) {
                    ans.eb(i);
                }
            }
            printf("%d", ans.size());
            for(int x: ans) {
                printf(" %d", x);
            }
            printf("\n");
            ans.clear();
        }
        for(int i=1; i<=vertex; i++)
            adj[i].clear();
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
