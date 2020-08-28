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

const int LIM = 5e4;
vector<ll>prime;

void sieve()
{
    vector<bool>isPrime(LIM, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=4; i<LIM; i+=2) isPrime[i] = false;
    for(ll i=3; i<LIM; i+=2){
        if(isPrime[i]) {
            for(ll j = i*i; j<LIM; j+=i){
                isPrime[j] = false;
            } 
        }      
    }
    prime.pb(2);
    for(int i=3; i<LIM; i+=2){
        if(isPrime[i]) {
            prime.pb(i);
        }
    }
}

int main()
{
    ll n;
    sieve();

    int lim = prime.size();
    //printf("lim %d\n", lim);

    while(scanf("%lld", &n), n!=0){
        vector<int>ans;
        ll tmp = n;
        int cnt = 0;

        printf("%lld =", tmp);
        if(tmp == 1) {
            printf(" \n");
            continue;
        }
        else if(tmp == -1) {
            printf(" -1 x \n");
            continue;
        }
        if(tmp < 0) {
            printf(" -1");
            n = abs(n);
            cnt++;
        }

        for(int i=0; i<lim && prime[i]*prime[i] <= n; i++) {
            //printf("n %lld prime %lld\n", n, prime[i]);
            while(n%prime[i] == 0){
                //ans.pb(prime[i]);
                if(cnt) printf(" x");
                printf(" %lld", prime[i]);
                n/=prime[i];
                cnt++;
            }
        }
        if(n>1) {
            if(cnt) printf(" x");
            printf(" %lld", n);
        }
        printf("\n");
        /*printf("%lld = ", tmp);
        if(tmp < 0) printf("-1 ");*/
    }
    
    return 0;
}