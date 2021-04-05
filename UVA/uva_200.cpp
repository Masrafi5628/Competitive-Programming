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

const int N = 1100;

vector<int>adj[N];
bool vis[N];
deque<int>ans;

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
    string a, b;
    //cout << a << endl;
    //while(cin >> a) {
    cin >> a;
    map<int, char>num;
    map<char, int>mp;
    int node = 1;
    while(cin >> b) {
        if(b == "#") break;
        int len1 = a.size();
        int len2 = b.size();
        //cout << a << endl;
        //cout << len1 << endl;
        //cout << b << endl;
        //cout << len2 << endl;
        for(int i = 0; i < min(len1, len2); i++) {
            int u, v;
            //printf("char %c %c %d %d\n", a[i], b[i], mp[a[i]], mp[b[i]]);
            int ck = mp[a[i]];
            // /*
            if(!mp[a[i]]) {
                //printf("ndoe %d\n", node+1);
                num[node] = a[i];
                mp[a[i]] = node++;
            }
            if(!mp[b[i]]) {
                num[node] = b[i];
                mp[b[i]] = node++;
            }
            u = mp[a[i]], v = mp[b[i]];

            if(u != v) {
                adj[u].eb(v);
                break;
            }
            // */
            //printf("ndoe %d\n", node);
        }
        
        a = b;
    }
    
    memset(vis, false, sizeof vis);

    for(int i = 1; i < node; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    
    for(int x: ans) {
        printf("%c", num[x]);
    }
    printf("\n");
    ans.clear();
    for(int i = 1; i <= node; i++) adj[i].clear();
    //}
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