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
// istringstream ss(str) while(ss >> n)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;

const ll inf = 2e18;
const ll mod = 1e9+7;

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

vector<ll>pos, pref;
int n, k;

// dp[i][j] => minimum distance from i to n select j point 
ll dp[202][33];//

// idx tomo position ee aci
// rem => ta point baki ace

ll solve(int idx, int rem)
{
    //printf("idx %d rem %d\n", idx, rem);
    if(idx > n) return 0;
    if(rem <= 0) return inf; 
    ll &mam = dp[idx][rem];

    if(mam != -1) return mam;
    mam = inf;

    for(int i=idx; i<=n; i++) {
        int mid = idx+((i-idx)/2);// idx => left, i => right

        // carefully handle this
        ll cost = abs(((mid-idx)*pos[mid]) - (pref[mid-1]-pref[idx-1]));
        cost += abs(((i-mid)*pos[mid]) - (pref[i] - pref[mid]));
        
        mam = min(mam, cost+solve(i+1, rem-1));
    }
    return mam;
}

void build(int idx, int rem)
{
    if(idx > n) return;

    for(int i=idx; i<=n; i++) {
        int mid = idx+((i-idx)/2);// idx => left, i => right

        ll cost = abs(((mid-idx)*pos[mid]) - (pref[mid-1]-pref[idx-1]));
        cost += abs(((i-mid)*pos[mid]) - (pref[i] - pref[mid]));
        
        if(solve(idx, rem) == cost+solve(i+1, rem-1)) {
            if((i-idx+1) > 1) {
                printf("Depot %d at restaurant %d serves restaurants %d to %d\n", k-rem+1, mid, idx, i);
            }else {
                printf("Depot %d at restaurant %d serves restaurant %d\n", k-rem+1, mid, i);
            }
            build(i+1, rem-1);
            return;
        }
    }
}

int main()
{
    int kase = 1;
    while(cin>>n>>k, n || k){
        pos.clear();
        pref.clear();
        pos.resize(n+2);
        pref.resize(n+2);
        memset(dp, -1, sizeof dp);

        for(int i=0; i<n; i++){
            cin>>pos[i+1];
            pref[i+1] = pref[i]+pos[i+1];
        }
        
        ll ans = solve(1, k);
        printf("Chain %d\n", kase++);
        build(1, k);
        printf("Total distance sum = %lld\n\n", ans);
    }

    return 0;
}
