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

const int lim = 1e7+5;
bool prime[lim];

vector<int>ans;

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
    
}
void solve()
{
    ans.pb(2);
    for(int i=3; i<lim; i+=2){
        if(prime[i]) {
            ans.pb(i);
        }
    }
}

int main()
{
    int n;
    memset(prime, true, sizeof prime);
    sieve();
    solve();

    while(cin>>n){
        if(n < 8){
            printf("Impossible.\n");
        }else {
            
            int a, b, c, d;
            //solve(n);
    
            if(n%2) {
                a = 2, b = 3;
                n -= 5;
                bool ck = false;
                for(int x: ans){
                    if(bs(all(ans), n-x)) {
                        c = x, d = n-x;
                        ck = true;
                        break;
                    }
                }
                if(ck) {
                    printf("%d %d %d %d\n", a, b, c, d);
                }else {
                    printf("Impossible.\n");
                }
            }else {
                a = b = 2;
                n -= 4;
                bool ck = false;
                for(int x: ans) {
                    if(bs(all(ans), n-x)) {
                        c = x, d = n-x;
                        ck = true;
                        break;
                    }
                }
                if(ck) {
                    printf("%d %d %d %d\n", a, b, c, d);
                }else {
                    printf("Impossible.\n");
                }
            }
            //ans.clear();
        }
    }

    return 0;
}