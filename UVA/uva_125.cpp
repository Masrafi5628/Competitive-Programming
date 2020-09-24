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
    count the all possible path's between two nodes
*/

int main()
{
    int n, kase = 0;
    while(cin>>n){
        int adj[202][202], mx = -1;
        //int dp[202][202];
        memset(adj, 0, sizeof adj);
        //memset(dp, 0, sizeof adj);

        for(int i=0; i<n; i++){
            int u, v;
            cin>>u>>v;
            adj[u][v] = 1;
            mx = max({mx, u, v});
        }
        mx++;

        for(int k=0; k<mx; k++){
            for(int i=0; i<mx; i++){
                for(int j=0; j<mx; j++){
                    adj[i][j] += adj[i][k]*adj[k][j];
                }
            }
        }

        for(int k=0; k<mx; k++){
            if(adj[k][k]) {
                for(int i=0; i<mx; i++){
                    for(int j=0; j<mx; j++)
                        if(adj[i][k] && adj[k][j])
                            adj[i][j] = -1;
                }
            }
        }

        printf("matrix for city %d\n", kase++);
        for(int i=0; i<mx; i++){
            for(int j=0; j<mx; j++){
                if(j)   
                    printf(" ");
                printf("%d", adj[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
