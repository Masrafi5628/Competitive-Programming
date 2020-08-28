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


int main()
{
    ll n;
    while(cin>>n, n!=0){
        ll a, x, b, y;
        cin>>a>>x;
        cin>>b>>y;
        if(n%x == 0 || n%y == 0 || (n%x)%y == 0 || (n%y)%x == 0){
            pii ans1, ans2;
            ans1 = {n/x, (n%x)/y};
            ans2 = {n/y, (n%y)/x};
            ll cost1 = ans1.ff*a+ans1.ss*a;
            ll cost2 = ans2.ff*b+ans2.ss*b;
            if(cost1 < cost2){
                cout << ans1.ff << ' '<<ans1.ss <<endl;
            }else {
                cout << ans2.ff << ' '<<ans2.ss <<endl;
            }
        }else {
            printf("failed\n");
        }
    }

    return 0;
}