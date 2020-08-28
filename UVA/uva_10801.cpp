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

int n, k;
int T[111];

// adj[elev_from].pb({{elev_to, floor_from}, {floor_to, cost}})
vector<pair<pii, pii>>adj[111];

// mp[elev] = {floor, .....}
map<int, vector<int>>mp;

// pq.push({{cost, elev}, floor})
priority_queue<pair<pii, int>>pq;

int dis[111][111];

void dijkstra()
{
    //if(!pq.empty()) dis[0] = 0;
    bool vis[111][111];
    memset(vis, false, sizeof vis);

    while(!pq.empty()) {
        //int cur_elev, cur_flor;
        int elev_from, elev_to, floor_to, floor_from;
        elev_from = pq.top().ff.ss; 
        floor_from = pq.top().ss;
        pq.pop();
        //
        //printf("(%d, %d) -> (%d, %d) => %d\n", elev_from, floor_from, elev_to, floor_to, cost);
        //printf("pq =>> elev %d floor %d\n", elev_from, floor_from);
        if(vis[elev_from][floor_from])
            continue;
        vis[elev_from][floor_from] = true;

        for(pair<pii, pii>p: adj[elev_from]) {
            //int elev_from, elev_to, floor_to, floor_from;
            elev_to = p.ff.ff;
            floor_to = p.ss.ff;
            int cost = p.ss.ss;
            if(p.ff.ss != floor_from)
                continue;
            //printf("(%d, %d) -> (%d, %d) => %d\n", elev_from, floor_from, elev_to, floor_to, cost);
            if(elev_to != elev_from)
                if(floor_from != floor_to)
                    continue;
            //floor_from = p.ff.ss;
            
            if(dis[elev_to][floor_to] > dis[elev_from][floor_from]+cost) {
                dis[elev_to][floor_to] = dis[elev_from][floor_from] + cost;
                pq.push({{-dis[elev_to][floor_to], elev_to}, floor_to});
                //printf("psh %d %d\n", elev_to, floor_to);
            }
        }
    }
    int ans = inf;
    for(int i=1; i<=n; i++){
        if(dis[i][k] != inf)
            ans = min(ans, dis[i][k]);
    }

   if(ans == inf) printf("IMPOSSIBLE\n");
   else printf("%d\n", ans);
}

int main()
{
    while(cin>>n>>k){
        for(int i=0; i<n; i++) cin>>T[i];
        for(int i=1; i<=n; i++) 
        for(int j=0; j<111; j++)
            dis[i][j] = inf;

        string str;
        int x;

        getline(cin, str);
        vector<pair<pii, int>>v,edge;
        for(int i=1; i<=n; i++){
            getline(cin, str);
            //printf("str is %s\n", str.c_str());
            istringstream ss(str);
            while(ss >> x) {
                //printf("i %d x %d\n", i, x);
                mp[i].pb(x);
                if(!x) {
                    v.pb({{0, i}, 0});
                }
                for(int j=i-1; j>=1; j--){
                    if(bs(all(mp[j]), x)) {
                        //adj[i].pb({{j, x}, {x, 60}});
                        //adj[j].pb({{i, x}, {x, 60}});
                        edge.pb({{i, j}, x});
                    }
                }
            }
        }
        for(int i=1; i<=n; i++){
            //printf("sz %d\n", mp[i].size());
            for(int j=1; j<mp[i].size(); j++){
                int cost = abs(mp[i][j] - mp[i][j-1])*T[i-1];

                adj[i].pb({{i, mp[i][j-1]}, {mp[i][j], cost}});
                adj[i].pb({{i, mp[i][j]}, {mp[i][j-1], cost}});
            }

        }
        for(pair<pii, int>p: v) {
            pq.push({{p.ff.ff, p.ff.ss}, p.ss});
            dis[p.ff.ss][0] = 0;
        }
        for(pair<pii, int>p: edge) {
            adj[p.ff.ff].pb({{p.ff.ss, p.ss}, {p.ss, 60}});
            adj[p.ff.ss].pb({{p.ff.ff, p.ss}, {p.ss, 60}});
        }
        for(int i=1; i<=n; i++){
            //printf("from %d-th elev\n", i);
            for(pair<pii, pii>p: adj[i]) {
                int elev_from, elev_to, floor_to, floor_from, cost;
                elev_to = p.ff.ff, floor_from = p.ff.ss;
                floor_to = p.ss.ff, cost = p.ss.ss;
                //printf("(%d, %d)->(%d, %d) => %d\n", i, floor_from, elev_to, floor_to, cost);
            }

        }
        dijkstra();
        /*
        for(int i=1; i<=n; i++)
            for(int j=0; j<=k; j++)
                printf("%d ", dis[i][j]);
            printf("\n");
        */
        for(int i=0; i<=n; i++) adj[i].clear();
        mp.clear();
    }

    return 0;
}