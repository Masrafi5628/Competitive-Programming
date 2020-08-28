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

const int lim = 2e7+5;
bool prime[lim];
vector<int>twin_prime;

void sieve()
{
    prime[0] = prime[1] = false;

    for(int i=4; i<lim; i+=2) prime[i] = false;

    for(ll i=3; i<lim; i+=2){
        if(prime[i]) {
            //cout << i << "\n";
            for(ll j=i*i; j<lim; j+=i){
                prime[j] = false;
            }
        }
    }
    for(int i=3; i<lim-2; i+=2){
        if(prime[i]) {
            if(prime[i-2] || prime[i+2]) twin_prime.pb(i);
        }
    }
}

int main()
{
    memset(prime, true, sizeof prime);
    sieve();

    vector<pii>ans;
    int len = twin_prime.size();

    for(int i=0; i<len-1; i++){
        if(abs(twin_prime[i]-twin_prime[i+1]) == 2){
            ans.pb({twin_prime[i], twin_prime[i+1]});
        }
    }

    /*for(pii p: ans){
        cout << p.ff << ' '<<p.ss <<endl;
    }*/

    int n;
    while(cin>>n){
        printf("(%d, %d)\n", ans[n-1].ff, ans[n-1].ss);
    }

    return 0;
}