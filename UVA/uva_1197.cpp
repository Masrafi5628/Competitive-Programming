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

int parent[30005];
int siz[30005];

void make_set(int x)
{
    siz[0] = 1; parent[0] = 0;
    for(int i=1; i<=x; i++){
        parent[i] = i;
        siz[i] = 1;
    }
}

int find(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b)
{
    a = find(a); b = find(b);

    if(a == b) return;
    if(a ==0 || b==0){
        siz[0] += a?siz[a]:siz[b];
        siz[a?a:b] = 0;
        parent[a?a:b] = 0;
    }
    else if(siz[a] > siz[b]) {
        siz[a] += siz[b];
        siz[b] = 0;
        parent[b] = a;
    }else {
        siz[b] += siz[a];
        siz[a] = 0;
        parent[a] = b;
    }
}

int main()
{
    int n, m, k;
    while(cin>>n>>m, n || m){
        make_set(n);
        while(m--){
            cin>>k;
            int ara[k+2];

            for(int i=0; i<k; i++){
                cin>>ara[i];
                if(i) {
                    union_set(ara[i-1], ara[i]);
                }
            }
        }
        cout << siz[0] <<endl;
    }

    return 0;
}