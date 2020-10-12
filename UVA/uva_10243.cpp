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
const ll mod = 998244353;

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

vector<int>adj[10100];
int dp[10100][10];

int fun(int u, int fire, int par)
{
    if(dp[u][fire] != -1) return dp[u][fire];

    int ans = fire;

    for(int v: adj[u]) {
        if(par != v) {
            if(fire) {
                ans += min(fun(v, 1, u), fun(v, 0, u));
            }else {
                ans += fun(v, 1, u);
            }
        }
    }

    return dp[u][fire] = ans;
}

int main()
{
    int n, k, x;
    while(scanf("%d", &n), n) {

        memset(dp, -1 , sizeof dp);
        for(int i=1; i<=n; i++) adj[i].clear();

        for(int i=1; i <= n; i++) {
            scanf("%d", &k);
            while(k--) {
                scanf("%d", &x);
                adj[i].pb(x);
            }
        }

        printf("%d\n", max(1, min(fun(1, 0, -1), fun(1, 1, -1))));

    }

    return 0;
}