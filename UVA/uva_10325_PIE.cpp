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

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;

const int inf = 9999999;
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

int len, n;
ll ara[20];

ll LCM(ll a, ll b)
{
    return (a*b)/(__gcd(a, b));
}

ll fun(int idx, int cnt, ll prod)
{
    if(idx == len) {
        //printf("lcm %lld cnt %d \n", prod, cnt );
        if(cnt == 0) return 0;
        if(cnt%2) return n/prod;
        return -n/prod;
    }

    ll ans = 0;

    ans += fun(idx+1, cnt+1, LCM(prod, ara[idx]));
    ans += fun(idx+1, cnt, prod);

    return ans;
}


int main()
{
    int m;
    while(cin >> n >> m){
        len = m;
        for(int i=0; i < m; i++)
            cin>>ara[i];

        ll ans = fun(0, 0, 1LL);

        printf("%lld\n", n - ans);
    }

    return 0;
}