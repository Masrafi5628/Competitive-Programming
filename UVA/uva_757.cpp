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

int n, h, f[33], d[33], t[33];
int dp[33][200][200];
int path[33];

int solve(int idx, int rem, int cnt)
{
    if(idx == n) return 0;
    int &mamo = dp[idx][rem][cnt];

    if(mamo != -1) return mamo;
    int ans1 = 0, ans2 = 0;


    if(rem > 0){
        int fish = f[idx]-(d[idx]*cnt);
        if(fish < 0) fish = 0;
        ans1 = fish+solve(idx, rem-1, cnt+1);
    }
    if(rem >= t[idx]){
        ans2 = solve(idx+1, rem-t[idx], 0);
    }

    return mamo = max(ans1, ans2);
}

void build(int idx, int rem, int cnt)
{
    if(idx == n) return;
    int ans1 = -1, ans2 = -1;

    if(rem > 0){
        int fish = f[idx]-(d[idx]*cnt);
        if(fish < 0) fish = 0;
        ans1 = fish+dp[idx][rem-1][cnt+1];
    }
    if(rem >= t[idx]) {
        ans2 = dp[idx+1][rem-t[idx]][0];
    }

    int mamo = dp[idx][rem][cnt];

    if(mamo == ans1) {
        path[idx]++;
        build(idx, rem-1, cnt+1);
    }else if(ans2 != -1) {
        build(idx+1, rem-t[idx], 0);
    }
}

int main()
{
    bool ok = false;
    while(cin>>n){
        memset(dp, -1, sizeof dp);
        memset(path, 0, sizeof path);

        cin>>h;
        for(int i=0; i<n; i++)   
            cin>>f[i];
        for(int i=0; i<n; i++)   
            cin>>d[i];
        for(int i=0; i<n-1; i++) 
            cin>>t[i];

        if(ok && !n) {
            break;
        }else {
            if(ok) printf("\n"); 
            ok = true;
        }

        int ans = solve(0, h*12, 0);
        build(0, h*12, 0);
        
        for(int i=0; i<n; i++) {
            if(i) printf(", ");
            printf("%d", path[i]*5);
        }
        printf("\n");
        printf("Number of fish expected: %d\n", ans);
    }

    return 0;
}
