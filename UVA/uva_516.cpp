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

ll binexp(ll a, ll b)
{
    if(!b) return 1;
    if(b%2) return a*(binexp(a*a, (b-1)/2));
    return binexp(a*a, b/2);
}

bool comp(pii a, pii b)
{
    /*if(a.ss == b.ss) return a.ff > b.ff;
    return a.ss > b.ss;
    */
    return a.ff > b.ff;
}

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

int main()
{
    sieve();
    int lim = prime.size();

    string str;
    while(getline(cin, str)){
        //cout << str <<endl;
        if(str.size() == 1 ) break;
        istringstream ss(str);
        ll n, val=1;
        while(ss >> n){
            int pwr;
            ss>>pwr;
            //printf("n %lld pr %d\n", n, pwr);
            val *= binexp(n, pwr);
        }
        val--;
        //cout << val <<endl;
        vector<pii>ans;
        for(int i=0; i<lim && prime[i]*prime[i] <= val; i++){
            if(val%prime[i] == 0) {
                int cnt = 0;
                while(val%prime[i] == 0){
                    val/=prime[i];
                    cnt++;
                }
                ans.pb({prime[i], cnt});
            }
        }
        if(val > 1){
            ans.pb({val, 1});
        }
        sort(all(ans), comp);
        int k = ans.size();
        for(int i=0; i<k; i++){
            printf("%d %d", ans[i].ff, ans[i].ss);
            if(i+1 != k) printf(" ");
            else printf("\n");
        }
    }
    
    return 0;
}