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

#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))

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
const ll mod = 1e9+9;

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

vector<pii>adj[10005];
bool vis[10005];
ll cnt;
int node, par;

void dfs(int u, ll sum)
{
    //printf("u %d sum %lld\n", u, sum);
    if(adj[u].size() == 1 && u != par){
        if(cnt < sum) {
            cnt = sum;
            node = u;
        }
        return;
    }
    if(vis[u]) return;
    vis[u] = true;

    for(int i=0; i<adj[u].size(); i++){
        dfs(adj[u][i].ff, sum+adj[u][i].ss);
    }
}

int main()
{
    string str;
    while(getline(cin, str)){

        istringstream ss(str);
        int u, v, w, mx;
        ss >> u; ss >> v; ss >> w;
        mx = max(u, v);

        adj[u].pb({v, w});
        adj[v].pb({u, w});

        while(getline(cin, str)){
            if(str.empty()) break;

            istringstream ss(str);
            ss >> u; ss >> v; ss >> w;
            //printf("%d %d %d\n", u, v, w);
            mx = max({mx, u, v});

            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
        //printf("mx %d\n", mx);
        par = 1;
        cnt = 0;
        memset(vis, false, sizeof vis);
        dfs(1, 0);

        par = node;
        memset(vis, false, sizeof vis);
        dfs(node, 0);

        printf("%lld\n", cnt);

        for(int i=1; i<=mx; i++) adj[i].clear();
    }

    return 0;
}
