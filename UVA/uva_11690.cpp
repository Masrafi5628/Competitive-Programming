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

int parent[500005];
int siz[500005];

int find_set(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(int x, int y)
{
    x = find_set(x); y = find_set(y);
    if(x != y){
        if(siz[x] > siz[y]){
            siz[x] += siz[y];
            siz[y] = 0;
            parent[y] = x;

        }else {
            siz[y] += siz[x];
            siz[x] = 0;
            parent[x] = y;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        ll mny[n+2];
        for(int i=0; i<n; i++)
            parent[i] = i, siz[i] = 1;
        //printf("%d %d\n", n, m);
        for(int i=0; i<n; i++) {
            cin>>mny[i];
        }

        while(m--){
            int x, y;
            cin>>x>>y;
            union_set(x, y);

        }
        bool ok = true;

        map<int, vector<int>>mp;
        set<int>st;

        for(int i=0; i<n; i++){
            mp[find_set(parent[i])].pb(i);
            st.insert(find_set(parent[i]));
        }

        for(int x: st){
            ll cnt=0;
            //printf("x %d\n", x);
            for(int y: mp[x]){
                //printf("%d ", y);
                cnt += mny[y];
            }
            if(cnt) {
                //printf("cnt %lld\n", cnt);
                ok = false;
                printf("IMPOSSIBLE\n");
                break;
            }
        }
        if(ok) printf("POSSIBLE\n");

    }

    return 0;
}