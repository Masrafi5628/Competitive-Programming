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
int tree[400005];

void build(int node, int lo, int hi)
{
    if(lo == hi) {
        tree[node] = ara[lo]>0?1:ara[lo]<0?-1:0;
        return;
    }
    int mid = lo+(hi-lo)/2;
    int lft = 2*node;
    int rgt = 2*node+1;
    build(2*node, lo, mid);
    build(2*node+1, mid+1, hi);
    //printf("node %d lft %d rgt %d\n", node, tree[lft], tree[rgt]);
    tree[node] = tree[2*node]*tree[2*node+1];
}

void update(int node, int lo, int hi, int idx, int val)
{
    if(lo == hi) {
        ara[idx] = val;
        int k = ara[idx] < 0?-1:ara[idx]>0?1:0;
        tree[node] = k;
        return;
    }
    int mid = lo+(hi-lo)/2;

    if(idx >= lo && idx <= mid){
        update(node*2, lo, mid, idx, val);
    }else {
        update(node*2+1, mid+1, hi, idx, val);
    }
    tree[node] = tree[node*2]*tree[node*2+1];
}

int query(int node, int lo, int hi, int a, int b)
{
    if(hi < a || b < lo) return 1;
    else if(lo >= a && b >= hi) {
        //printf("node %d %d %d tree %d\n", node, a, b, tree[node]);
        return tree[node];
    }
    int mid = lo+(hi-lo)/2;

    int p1 = query(node*2, lo, mid, a, b);
    int p2 = query(node*2+1, mid+1, hi, a, b);
    return p1*p2;
    //return tree[node] = p1*p2;
}


int main()
{
    int n, k, x;
    string str;
    //getline(cin, str);
    while(getline(cin, str)) {
        //printf("%d\n", str.size());
        //cout << str <<endl;
        
        if(str.empty()) break;
        istringstream ss(str);
        ss >> n; ss >> k;
        //memset(tree, 0, sizeof tree);
        //memset(ara, 0, sizeof ara);
        //printf("n %d k %d\n", n, k);
        for(int i=1; i <= n; i++){
            scanf("%d", &x);
            //x = x < 0?-1:x>0?1:0;
            ara[i] = x;
            //printf("%d ", ara[i]);
        }
        build(1, 1, n);
        //printf("ok\n");
        
        char ch;
        int l, r;
        string ans;
        getline(cin, str);
        while(k--){
            getline(cin, str);
            istringstream ss(str);
            ss >> ch; ss >> l; ss >> r;
            //printf("%c %d %d\n", ch, l, r);
            if(ch == 'C') {
                update(1, 1, n, l, r);
            }else {
                int prod = query(1, 1, n, l, r);
                if(prod > 0)
                    ans += '+';
                else if(prod < 0)
                    ans += '-';
                else 
                    ans += '0';
            }
        }
        printf("%s\n", ans.c_str());
    }

    return 0;
}
