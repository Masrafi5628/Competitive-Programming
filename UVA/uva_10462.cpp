#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define sz(x) (int)x.size()
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

struct edge
{
	int u, v, w;
};

bool comp(edge a, edge b)
{
	return a.w < b.w;
}

vector<edge>adj;
int par[111];
int siz[111];

void init(int n)
{
	for(int i=0; i<=n; i++) par[i] = i, siz[i] = 1;
}

int find(int x)
{
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

bool same(int a, int b)
{
	return find(a) == find(b);
}

void unite(int a, int b)
{
	a = find(a); b = find(b);
	if(siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b];
	par[b] = a;
}
vector<int>edg[111];
bool vis[111];

void dfs(int u)
{
	//printf("u %d\n", u+1);
	if(vis[u]) return;
	vis[u] = true;
	for(int v: edg[u]){
		if(!vis[v]) dfs(v);//printf("v %d \n", v+1), dfs(v);
	}
}

int main()
{
    int t, v, m, kase = 1;
    cin>>t;
    while(t--){
    	cin>>v>>m;
    	memset(par, 0, sizeof par);
    	memset(siz, 0, sizeof siz);
    	memset(vis, false, sizeof vis);

    	adj.clear();

    	init(v);

    	for(int i=0; i<m; i++){
    		edge e;
    		cin>>e.u>>e.v>>e.w;
    		e.u--, e.v--;

    		edg[e.u].pb(e.v);
    		edg[e.v].pb(e.u);

    		adj.pb(e);
    	}
    	sort(adj.begin(), adj.end(), comp);
    	int mst = 0;
    	
    	int cnt = 0;
    	for(int i=0; i<v; i++){
    		if(!vis[i]) {
    			dfs(i);
    			cnt++;
    		}
    	}
    	//printf("cnt %d\n", cnt);
    	for(int i=0; i<v; i++) edg[i].clear();
    	printf("Case #%d : ", kase++);
    	if(cnt > 1) {
    		printf("No way\n");
    		continue;
    	}
    	vector<int>ans;

    	for(int i=0; i<m; i++){
    		edge e = adj[i];
    		if(!same(e.u, e.v)) {
    			mst += e.w;
    			unite(e.u, e.v);
    			ans.pb(i);
    		}
    	}
    	int mst_2 = inf;
    	bool ys = false;
    	for(int j=0; j<ans.size(); j++){
    		int sum = 0, edg = 0;
    		init(v);

    		for(int i=0; i<m; i++){
    			if(i == ans[j]) continue;
    			edge e = adj[i];
    			if(!same(e.u, e.v)) {
    				sum += e.w;
    				unite(e.u, e.v);
    				edg++;
    			}
    		}
    		if(edg != v-1) continue;
    		ys = true;
    		//printf("sum %d\n", sum);
    		if(sum >= mst) mst_2 = min(mst_2, sum); 
    	}
    	if(ys) printf("%d\n", mst_2);
    	else printf("No second way\n");
    	
    }

    return 0;
}