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
const ll mod = 1e8;

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

/*
    minimise the maximum jump range(edge cost)
*/

ll sqr(ll a)
{
    return a*a; 
}

int main()
{
    int n, kase = 1;
    //int adj[202][202];
    double dp[202][202];

    while(scanf("%d", &n), n) {
        //memset(adj, 0, sizeof adj);
        pii adj[n+1];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                dp[i][j] = (double)inf;
        }
        for(int i=0; i<n; i++){
            scanf("%d%d", &adj[i].ff, &adj[i].ss);
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++) {
                dp[i][j] =dp[j][i]= sqrt(sqr(adj[i].ff-adj[j].ff)+sqr(adj[i].ss-adj[j].ss));
            }
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dp[i][j] = min(dp[i][j], 
                        max(dp[i][k], dp[k][j]));
                }
            }
        }
            
        printf("Scenario #%d\n", kase++);
        printf("Frog Distance = %.3f\n\n", dp[0][1]);
    }

    return 0;
}
