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

list<int>ans;
vector<int>adj[111];
bool vis[111];
int kase = 1;

void dfs(int u)
{
    if(vis[u]) return;
    vis[u] = true;

    for(int v: adj[u]) {
        if(!vis[v]) dfs(v);
    }
    ans.pf(u);
}

void solve()
{
    int node;
    while(cin >> node) {
        map<string, int>mp;
        map<int, string>name;
        int now = 0;
        vector<string>ara;
        int inDeg[node+10];

        memset(inDeg, 0, sizeof inDeg);

        memset(vis, false, sizeof vis);
        ans.clear();

        for(int i = 0; i < node; i++) {
            string str;
            cin >> str;
            ara.eb(str);
            if(!mp[str]) {
                name[now] = str;
                mp[str] = now++;
            }

        }
        int edge;
        cin >> edge;

        for(int i = 0; i < edge; i++) {
            string a, b;
            cin >> a >> b;
            int u = mp[a], v = mp[b];

            adj[u].pb(v);
            inDeg[v]++;
        }
        bool take[node+10];
        memset(take, false, sizeof take);

        for(int i = 0; i < node; i++) {
            for(int j = 0; j < node; j++) {
                if(!inDeg[j] && !take[j]) {
                    take[j] = true;
                    ans.pb(j);
                    for(int x: adj[j]) {
                        inDeg[x]--;
                    }
                    break;
                }   
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", kase++);

        for(int x: ans) {
            printf(" %s", name[x].c_str());
        }
        printf(".\n\n");

        for(int i = 0; i <= node; i++)
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
