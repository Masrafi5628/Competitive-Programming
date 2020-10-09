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
const ll mod = 998244353;

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
int ara[lim];
int tree[4*lim]; //lazy[4*lim];

int p, q, val, idx;

void build(int node, int st, int ed)
{
    if(st == ed){
        tree[node] = ara[st];
        return;
    }
    int mid, lft, rgt;

    mid = st+(ed-st)/2;
    lft = 2*node; rgt = lft+1;

    build(lft, st, mid);
    build(rgt, mid+1, ed);

    tree[node] = min(tree[lft], tree[rgt]);
}


void update(int node, int st, int ed)
{
    int mid, lft, rgt;

    mid = st+(ed-st)/2;
    lft = 2*node; rgt = lft+1;

    if(st == ed) {
        tree[node] = val;
        return;
    }

    if(idx >= st && idx <= mid)
        update(lft, st, mid);
    else
        update(rgt, mid+1, ed);

    tree[node] = min(tree[lft], tree[rgt]);
}

int query(int node, int st, int ed)
{
    int mid, lft, rgt;

    mid = st+(ed-st)/2;
    lft = 2*node; rgt = lft+1;

    
    if(ed < p || q < st) return 2000000;
    if(st >= p && ed <= q) return tree[node];

    return min(query(lft, st, mid), 
            query(rgt, mid+1, ed));

}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);

    int n, k;
    scanf("%d%d", &n, &k);

    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);

    build(1, 1, n);
    char str[40], tmp[10], num[10];
    cin.ignore();
    //getline(cin, str);
    vector<int>v;
    while(k--) {
        v.clear();
        scanf("%s", str);

        int len = 0;
        while(sscanf(str+len, "%[^0123456789]%[^ ,)]%", tmp, num) == 2) {
            v.pb(stoi(num));
            //cout << num <<endl;
            len += strlen(tmp)+strlen(num);
        }
        //printf("asce\n");
        //v.pb(v[0]);

        if(str[0] == 's') {
            int sz = v.size();
            int ck = ara[v[0]];
            for(int i=0; i+1 < sz; i++){
                swap(ara[v[i]], ara[v[i+1]]);
                /*
                val = ara[v[i]];
                idx = v[i-1];
                if(i+1 != sz) 
                    swap(ara[v[i]], ara[idx]);
                update(1, 1, n);
                */
                
            }
            ara[v[sz-1]] = ck;
            /*sz--;*/
            for(int i=0; i<sz; i++) {
                idx = v[i], val = ara[v[i]];
                update(1, 1, n);
            }
        }else {
            p = v[0], q = v[1];
            printf("%d\n", query(1, 1, n));
        }
    }
    
    return 0;
}
