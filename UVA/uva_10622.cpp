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

const int LIM = 1e5;
vector<ll>prime;
vector<bool>isPrime(LIM, true);

void sieve()
{
    
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
    ///if(isPrime[2047]) printf("yessss\n");
}

int ok(vector<int>v)
{
    int lim = v.size();
    int gd = v[0];
    for(int i=0; i<lim; i++){
        //if(v[i]%ans) return false;
        gd = __gcd(gd, v[i]);
    }
    return gd;
}

int main()
{
    ll n;
    sieve();
    int lim = prime.size();

    while(scanf("%lld", &n), n!=0){
        int cnt=0, ans = 999999999;
        //ll ans = 1;
        int tmp = n;
        if(n<0) n*=(-1);
        //cout << n<<endl;
        vector<int>v;
        //printf("n %lld\n", n);
        for(int i=0; i<lim && prime[i]*prime[i] <= n; i++){
            if(n%prime[i] == 0){
                cnt = 0;
                //printf("n %lld pr %lld\n", n, prime[i]);
                while(n%prime[i] == 0) {
                    n/=prime[i];
                    cnt++;
                }
                //printf("%lld^%d\n",prime[i], cnt);
                v.pb(cnt);
                ans = min(ans, cnt);
            }
        }
        if(n>1) v.pb(1);
        
        /*if(ans != 1 && ok(v, ans)) {
            if(tmp < 0) {
                if(ans%2) cout << ans <<endl;
                else cout << 1 <<endl;
            }else 
                cout << ans <<endl;
        }
        else cout<< 1 <<endl;*/
        ans = ok(v);
        if(tmp < 0){
            while(ans%2 == 0) ans/=2;
            cout << ans <<endl;
        }else {
            cout << ans <<endl;
        }
    }
    
    return 0;
}