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
// stoi("...") -> decimal
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

const int N = 1010;
vector<pii>adj[N];
ll dis[N], dp[N];
int vis[N], kase = 1, node, edge;

void DJ(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>>pq;

    pq.push({0, src});

    // dis[i] = shortest path from source to node i
    fill(dis, dis+N, inf);

    dis[src] = 0;

    while(!pq.empty()) {
        int u = pq.top().ss;
        //int w = pq.top().ss;
        pq.pop();

        for(pii p: adj[u]) {
            int v = p.ff;
            int cost = p.ss;
            //printf("%d -> %d = %d\n", u, v, cost);
            //printf("dis[v] %d dis[u] %d\n", dis[v], dis[u]);
            if(dis[v] > dis[u] + cost) {
                dis[v] = dis[u] + cost;
                pq.push({dis[v], v}); 
            }
        }
    }
    /*
    for(int i = 1; i <= node; i++) {
        printf("src %d -> %d = %d\n", src, i, dis[i]);
    }
    */
}

ll fun(int u)
{
    if(u == 1) return 1;

    ll &mami = dp[u];
    if(vis[u] == kase) return mami;
    vis[u] = kase;

    ll ans = 0;

    for(pii p: adj[u]) {
        int v = p.ff;

        if(dis[v] > dis[u]) {
            ans += fun(v);
        }
    }
    return mami = ans;
}

void solve()
{
    while(cin >> node >> edge, node) {

        for(int i = 1; i <= node; i++)
            adj[i].clear();

        for(int i = 0; i < edge; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }

        DJ(2);

        printf("%lld\n", fun(2));
        kase++;
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