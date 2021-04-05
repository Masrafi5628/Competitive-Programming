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

const int N = 111;

vector<int>adj[N];
queue<int>kue;
vector<int>inDeg(N, 0);

int ans, task;

void kahn(int kaj)
{
    int vis[N], cnt = 0;
    //printf("ki holo\n");
    vector<int>Deg(N);
    Deg = inDeg;
    memset(vis, 0, sizeof vis);

    while(!kue.empty()) {
        int u = kue.front();
        kue.pop();

        //printf("u %d cnt %d\n", u, cnt);

        if(vis[u]) continue;
        //else continue;
        vis[u] = 1;
        cnt++;

        for(int v: adj[u]) {
            if(vis[v]) continue;
            Deg[v]--;
            if(!Deg[v]) {
                kue.push(v);
            }
        }
    }

    //printf("cnt %d task %d\n", cnt, kaj);
    if(ans < cnt ) {
        ans = cnt;
        task = kaj;
    }
}

void solve()
{
    int node;
    while(cin >> node, node) {
        
        inDeg[0] = 0;
        for(int i = 1; i <= node; i++) {
            adj[i].clear();
            inDeg[i] = 0;
        }
        ans = 0;

        for(int i = 1; i <= node; i++) {
            int edge;
            cin >> edge;

            for(int j = 0; j < edge; j++) {
                int v;
                cin >> v;
                //printf("u %d v %d\n", i, v);
                adj[i].eb(v);
                inDeg[v]++;
            }
        }

        for(int i  = 1; i <= node; i++) {
            if(!inDeg[i]) {
                kue.push(i);
                kahn(i);
                //printf("tsk %d ans %d\n", i, task);
            }
        }

        printf("%d\n", task);
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