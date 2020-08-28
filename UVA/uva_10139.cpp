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

const ll inf = 1e18;
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

const int lim = 5e4+5;
vector<ll>prime;
bool isPrime[lim];

void sieve()
{
    memset(isPrime, true, sizeof isPrime);
    for(ll i=4; i<lim; i+=2) isPrime[i] = false;

    for(ll i=3; i<lim; i+=2){
        if(isPrime[i]) {
            for(ll j = i*i; j<lim; j+=i){
                isPrime[j] = false;
            }
        }
    }
    prime.pb(2);
    for(ll i=3; i<lim; i+=2){
        if(isPrime[i]) {
            prime.pb(i);
        }
    }
}

int main()
{
    sieve();
    ll n, m;// check n! is divisible by m or not

    int LIM = prime.size();
    //for(int i=0; i<100; i++) cout << prime[i] <<endl;
    while(cin>>n>>m){
        ll mm = m;
        bool ok = true;
        if(!m) {
            printf("%lld divides %lld!\n", mm, n);
            continue;
        }
        for(int i=0; i<LIM && prime[i]*prime[i]<=m; i++){
            int cnt = 0, ck = 0;
            while(m%prime[i] == 0){
                cnt++; m/=prime[i];
            }
            //printf("cnt %d\n", cnt);
            if(cnt){
                ll tmp = prime[i], plus = 1;
                ck += n/tmp;
                tmp *= prime[i];
                while((n/tmp) > 0){
                    ck += plus;
                    plus++, tmp *= prime[i];
                }
                if(ck < cnt){
                    ok = false; break;
                }
            }
        }
        if(m > 1){
            if(ok)
                ok = ((n/m) >= 1);
        }
        if(ok) {
            printf("%lld divides %lld!\n", mm, n);
        }else {
            printf("%lld does not divide %lld!\n", mm, n);
        }
    }
    
    return 0;
}