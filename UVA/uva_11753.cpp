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

int n, k;
vector<int>s;

int solve(int i, int j, int cnt)
{
    if(cnt > k)
        return inf;
    if(i >= j)
        return cnt;
    if(s[i] == s[j]) {
        return solve(i+1, j-1, cnt);
    }else {
        return min(solve(i+1, j, cnt+1), solve(i, j-1, cnt+1));
    }
}

int main()
{
    int t, kase=1;
    cin>>t;
    while(t--){
        
        //memset(dp, -1, sizeof dp);
        //tmp = 0;
        cin>>n>>k;
        //vector<int>v(n), x(n);
        s.resize(n);

        for(int i=0; i<n; i++){
            cin>>s[i];
        }

        int ans = solve(0, n-1, 0);
        if(ans == 0) printf("Case %d: Too easy\n", kase++);
        else if(ans > k) printf("Case %d: Too difficult\n", kase++);
        else printf("Case %d: %d\n", kase++, ans);
    }
    
    return 0;
}