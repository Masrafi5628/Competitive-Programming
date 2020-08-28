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

const int inf = 9999999;
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

int ara[111], n, wt;
int dp[105][25005];
//int dp[105][505][505];

int solve(int idx, int profit)
{
    if(idx == n)
        return profit;

    if(dp[idx][profit] != -1)
        return dp[idx][profit];

    int ans = 0;

    if(profit+ara[idx] <= wt){
        return ans = dp[idx][profit] = max({ans, solve(idx+1, profit+ara[idx]), 
            solve(idx+1, profit)});
    }else {
        return ans = dp[idx][profit] = max(ans, solve(idx+1, profit));
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int sum = 0;
        cin>>n;
        //int ara[n+2];
        memset(dp, -1, sizeof dp);

        for(int i=0; i<n; i++) {
            cin>>ara[i];
            sum += ara[i];
        }
        wt = sum/2;
        cout <<  sum - 2*solve(0, 0) << endl;
    }

    return 0;
}