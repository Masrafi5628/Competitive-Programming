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

vector<int>adj[30000];
vector<string>mat[22];

bool ok(string a, string b)
{
    int len1 = a.size(), len2 = b.size();
    int cnt = abs(len2-len1);

    for(int i = 0; i < min(len1, len2); i++) {
        if(a[i] != b[i]) cnt++;
    }
    /*
    if(cnt == 1) {
        cout << a << " " << b << endl;
    }
    */
    return cnt == 1;
}
vector<int>ans;

bool bfs(int src, int des)
{
    queue<int>kue;
    kue.push(src);
    int vis[30000];
    int par[30000];

    memset(par, -1, sizeof par);
    memset(vis, false, sizeof vis);
    bool ck = false;
    //cout << "src " << src << " des " << des << endl;
    while(!kue.empty()) {
        int u = kue.front();
        kue.pop();
        //cout << "u " << u << endl;
        if(u == des) {
            ck = true;break;
        }

        if(vis[u]) continue;
        vis[u] = true;


        for(int v: adj[u]) {
            if(!vis[v]) {
                if(par[v] == -1) par[v] = u;
                kue.push(v);
            }
        }
    }
    //cout << "ses " <<endl;
    if(ck) {
        
        while(des != -1) {
            //cout << des << endl;
            ans.pb(des);
            des = par[des];
        }
        reverse(all(ans));

        return true;
    }
    return false;
}

void solve()
{
    string str, a, b;
    map<string, int>mp;
    int node = 1;
    map<int, string>ara;

    vector<string>bec;

    while(getline(cin, str)) {
        //cout << str << endl;
        int len = str.size();
        if(len == 0) break;
        if(!mp[str]) {
            ara[node] = str;
            mp[str] = node++;
        }
        mat[len].pb(str);
        bec.pb(str);
        //if(bec.size() == 9) break;
    }
    int len = bec.size();
    //cout << len << endl;
    
    for(int i = 1; i <= 16; i++) {
        int now = mat[i].size();
        for(int j = 0; j < now; j++) {
            for(int k = j+1; k < now; k++) {
                if(ok(mat[i][j], mat[i][k])) {
                    adj[mp[mat[i][j]]].pb(mp[mat[i][k]]);
                    adj[mp[mat[i][k]]].pb(mp[mat[i][j]]);
                }
            }
        }
    }
    int kase = 0;
    while(cin >> a >> b) {
        if(kase) cout << endl;
        //cout << a << " " << b << endl;
        
        if(bfs(mp[a], mp[b])) {
            for(int x: ans) {
                cout << ara[x] << endl;
            }
        }else {
            cout << "No solution.\n";
        }
        ans.clear();
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
