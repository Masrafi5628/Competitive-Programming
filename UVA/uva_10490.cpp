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

int main()
{
    int n;
    sieve();


    int lim = prime.size();
    while(scanf("%d", &n), n!=0){
        unsigned long long ans = (ll)((1<<n)-1)*(ll)(1<<(n-1));
        unsigned long long pr = ans;
        //printf("n %d ans %llu\n", n, ans);
        unsigned long long ck = 1;
        for(int i=0; i<lim && prime[i]*prime[i] <= ans; i++){
            if(ans%prime[i] == 0){
                ll tmp = 1;
                while(ans%prime[i] == 0){
                    ans = ans/prime[i];
                    tmp = tmp*prime[i];
                }
                tmp = prime[i]*tmp;
                tmp -= 1;
                ck = ck*(tmp/(prime[i]-1));
            }
        }
        if(ans > 1){
            ck = ck*(((ans*ans)-1)/(ans-1));
        }
        if(ck-pr == pr) printf("Perfect: %llu!\n", pr);
        else if(isPrime[n]) 
            printf("Given number is prime. But, NO perfect number is available.\n");
        else printf("Given number is NOT prime! NO perfect number is available.\n");
    }
    
    return 0;
}