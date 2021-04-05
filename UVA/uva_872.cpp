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

int node, edge, kase;
vector<string>ans;
map<int, char> num;
map<char, int> mp;

int clr[N];

bool dfs(int u)
{
    clr[u] = 1;

    for(int v: adj[u]) {
        if(clr[v] == 1) return true;
        else if(!clr[v] && dfs(v)) return true;
    }
    clr[u] = 2;
    return false;
}

void fun(int cnt, string str, int *indeg, bool *take)
{
    if(cnt == node) {
        ans.eb(str);
        return;
    }

    for(int i = 0; i < node; i++) {
        if(!indeg[i] && !take[i]) {
            take[i] = true;
            for(int v: adj[i]) {
                indeg[v]--;
            }
            char now = num[i];

            fun(cnt+1, str.empty()?str+now:str+' '+now, indeg, take);

            for(int v: adj[i]) {
                indeg[v]++;
            }
            take[i] = false;
        }
    }
}

void solve()
{
    string a, b;
    //getline(cin, a);
    getline(cin, a);
    getline(cin, a);
    getline(cin, b);

    //cout << a << endl;
    //cout << b << endl;

    if(kase) printf("\n");
    
    node = 0;

    mp.clear();
    num.clear();

    for(int i = 0; i < a.size(); i += 2) {
        num[node] = a[i];
        mp[a[i]] = node++;
    }

    stringstream ss(b);

    string aa;

    int indeg[33];
    bool take[33];

    memset(indeg, 0, sizeof indeg);
    memset(take, false, sizeof take);
    memset(clr, 0, sizeof clr);

    while(ss >> aa) {

        int u = mp[aa[0]];
        int v = mp[aa[2]];
        //printf("u %d v %d\n", u, v);
        adj[u].eb(v);
        indeg[v]++;
    }

    for(int i = 0; i < node; i++) {
        if(!clr[i] && dfs(i)) {
            printf("NO\n");
            return;
        }
    }

    fun(0, "", indeg, take);

    sort(all(ans));

    for(string str: ans) {
        printf("%s\n", str.c_str());
    }
    
    
}

int main()
{
    fast_io;

    int tt = 1;

    cin >> tt;
    string amne;
    getline(cin, amne);

    while(tt--) {
        ans.clear();

        for(int i = 0; i < node; i++)
            adj[i].clear();

        solve();
        kase++;
    }
 
    return 0;
}