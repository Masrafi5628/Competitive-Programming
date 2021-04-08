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

int node, edge, tim, src;
vector<pii>adj[N];
vector<int>dis;

void DJ()
{
	priority_queue<pii, vector<pii>, greater<pii> >pq;
	pq.push({0, src});// {cost, node}

	dis[src] = 0;

	while(!pq.empty()) {
		int u = pq.top().ss;

		pq.pop();

		for(pii now: adj[u]) {
			int v = now.ff;
			int cost = now.ss;

			if(dis[v] > dis[u] + cost) {
				dis[v] = dis[u] + cost;
				pq.push({dis[u]+cost, v});
			}
		}
	}
}

void solve()
{
	cin >> node >> src >> tim >> edge;

	for(int i = 0; i < edge; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[v].pb({u, w});//adj[node].pb({node, cost})
	}

	DJ();

	int ans = 0;

	for(int i =  1; i <= node; i++) {
		//printf("%d to %d = %d\n", src, i, dis[i]);
		if(dis[i] <= tim) ans++;
	}
	printf("%d\n", ans);
}

int main()
{
    fast_io;

    int tt = 1;

    cin >> tt;

    while(tt--) {

    	dis.clear();
    	dis.assign(N, 999999999);
    	for(int i = 0; i <= N; i++)
    		adj[i].clear();


        solve();
        if(tt) printf("\n");
    }
 
    return 0;
}