/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
*/

#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

//#define inf 1<<30

// isupper() -> upper case check
// tolower() -> convert upper to lower case
// idx = str.find("bear", pos)) != string::npos =>substring find
// Tuple access -> get<0>(v[i])
// cmnt - ctrl []
// stoi("...") -> decimel
// istringstream ss(str) while(ss >> n)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;

const ll inf = 2e18;
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

const int lim = 1e5+5;
bool isPrime[lim];
vector<ll>prime;

void sieve()
{
	prime.pb(2);
	memset(isPrime, true, sizeof isPrime);

	for(int i=4; i<lim; i+=2) isPrime[i] = false;

	for(ll i=3; i<lim; i+=2){
		if(isPrime[i]) {
			for(ll j = i*i; j<lim; j+=i) {
				isPrime[j] = false;
			}
		}
	}
	for(ll i=3; i<lim; i+=2) {
		if(isPrime[i]) prime.pb(i);
	}
}

int main()
{
    ll n, d;
    sieve();
    int LIM = prime.size();

    while(scanf("%lld%lld", &n, &d), n || d) {
    	if(n == 0 || n == 1) {
    		if(d == 1) printf("1\n");
    		else printf("0\n");
    		continue;
    	}
    	set<ll>st, st2;
    	map<ll, ll>mp, mp2;

    	for(int i=0; i<LIM && prime[i]*prime[i] <= d; i++) {
    		if(d%prime[i] == 0) {
    			st.insert(prime[i]);
	    		while(d%prime[i] == 0) {
	    			mp[prime[i]]++;
	    			d/=prime[i];
	    		}
	    	}
    	}
    	if(d > 1) {
    		st.insert(d);
    		mp[d]++;
    	}
    	
    	for(int i=2; i<=n; i++) {
    		ll tmp = i;
    		for(int j=0; j<LIM && prime[j]*prime[j] <= tmp; j++) {
    			if(tmp%prime[j] == 0) {
	    			st2.insert(prime[j]);
		    		while(tmp%prime[j] == 0) {
		    			mp2[prime[j]]++;
		    			tmp/=prime[j];
		    		}
		    	}
    		}
    		if(tmp > 1) {
    			st2.insert(tmp);
    			mp2[tmp]++;
    		}
    	}
    	ll ans = 1;
    	//cout <<" size "<< st.size()<<endl;
    	for(ll x: st) {
    		if(mp[x] > mp2[x]) {
    			ans = 0; break;
    		}
    	}
    	if(!ans) {
    		printf("%lld\n", ans);
    	}
    	else {
    		for(ll x: st2) {
    			ans *= (mp2[x]-mp[x]+1);
    		}
    		printf("%lld\n", ans);
    	}
    }   
    
    return 0;
}