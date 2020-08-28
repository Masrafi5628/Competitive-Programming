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

ll binexp(ll a, ll b)
{
    if(!b) return 1;
    if(b%2) return a*binexp(a*a, (b-1)/2);
    return binexp(a*a, b/2);
}

int main()
{
    string line;
    istringstream ss;
    while(getline(cin, line)){
        ss.clear();
        ss.str(line);

        vector<ll>c, x, v;
        ll num;

        while(ss >> num)
            c.pb(num);

        getline(cin, line);
        ss.clear();
        ss.str(line);

        while(ss >> num)
            x.pb(num);
        ll ans = 0;
        
        for(ll x_val: x){
            int order = c.size();
            ans = 0;
            for(ll c_val: c){
                ans += c_val*binexp(x_val, order-1);
                order--;
            }
            v.pb(ans);
        }
        for(int i=0; i<v.size(); i++){
            cout << v[i];
            if(i+1 != v.size()) cout << ' ';
        }
        cout <<endl;
    }

    return 0;
}