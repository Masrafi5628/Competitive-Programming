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

#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))

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

const int lim = 1e6+5;
int ans[lim+5];
int spf[lim+5];

void factor()
{
    spf[1] = 1;
    //spf[2] = 2;
    for(int i=2; 1LL*i*i <= lim; i++){
        if(!spf[i]) {
            spf[i] = i;
            for(ll j=1LL*i*i; j<lim; j+=i){
                spf[j] = i;
            }
        }
    }

    for(int i=3; i<lim; i+=2){
        if(!spf[i]) spf[i] = i;
    }
}

int main()
{
    factor();

    ans[2] = 1;
    for(int i=3; i<lim; i++){
        int val = i, cnt = 0;
        while(spf[val] != 1){
            val = val/spf[val]; cnt++;
        }
        ans[i] = ans[i-1]+cnt;
    }

    int x;
    while(scanf("%d", &x) != EOF){
        printf("%d\n", ans[x]);
    }

    return 0;
}
