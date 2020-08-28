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

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;

const int inf = 2e9;
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

vector<pii>adj[20010];
int m, n, src, des;
int dis[20010];

void dijkstra()
{
    priority_queue<pii>pq;
    pq.push({0, src});

    for(int i=0; i<=m; i++) dis[i] = inf;
    dis[src] = 0;

    while(!pq.empty()) {
        int u = pq.top().ss; //w = pq.top().ss*(-1);
        pq.pop();

        for(pii x: adj[u]) {
            int v = x.ff, w = x.ss;
            if(dis[v] > dis[u]+w) {
                dis[v] = dis[u]+w;
                // minimum cost er edge ta age
                // takbe
                pq.push({-dis[v], v});
            }
        }
    }
}

int main()
{
    int t, kase = 1;
    cin>>t;
    while(t--){

        cin>>m>>n>>src>>des;
        for(int i=0; i<n; i++){
            int u, v, w;
            cin>>u>>v>>w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
        dijkstra();
        
        printf("Case #%d: ", kase++);
        if(dis[des] == inf) printf("unreachable\n");
        else printf("%d\n", dis[des]);

        for(int i=0; i<m; i++) adj[i].clear();
    }
    
    return 0;
}