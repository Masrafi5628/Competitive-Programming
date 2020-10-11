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

const int lim = 1024010;
int p, q, val;

string str;
int tree[4*lim], lazy[4*lim];


void build(int node, int st, int ed)
{
    if(st == ed){
        //printf("st %d %c\n", st, str[st]);
        //cout << st << " "<< str[st]-'0'<<endl;
        tree[node] = str[st]-'0'; return;
    }
    int mid, lft, rgt;

    mid = st+(ed-st)/2;
    lft = 2*node; rgt = lft+1;

    build(lft, st, mid);
    build(rgt, mid+1, ed);

    tree[node] = tree[lft] + tree[rgt];
}

void update(int node, int st, int ed)
{
    int mid, lft, rgt;

    mid = st+(ed-st)/2;
    lft = 2*node; rgt = lft+1;

    if(lazy[node] != -1) {
        if(lazy[node] == 2) {
            tree[node] = (ed-st+1-tree[node]);
            if(lazy[lft] != -1) {
                if(lazy[lft] == 2) lazy[lft] = -1;
                else lazy[lft] = !lazy[lft];
            }
            else {
                lazy[lft] = lazy[node];
            }
            if(lazy[rgt] != -1) {
                if(lazy[rgt] == 2) lazy[rgt] = -1;
                else lazy[rgt] = !lazy[rgt];
            }
            else {
                lazy[rgt] = lazy[node];
            }
        }
        else tree[node] = (ed-st+1)*lazy[node];

        // if this is not leap node
        if(st != ed && lazy[node] != 2){
            // be careful
            /*
            if(lazy[lft] != -1) {
                if(lazy[lft] == 2) tree[lft] = (ed-st+1-tree[lft]);
                else tree[lft] = (ed-st+1)*lazy[lft];
            } 
            if(lazy[rgt] != -1) {
                if(lazy[rgt] == 2) tree[rgt] = (ed-st+1-tree[rgt]);
                else tree[rgt] = (ed-st+1)*lazy[rgt];
            }*/
            lazy[lft] = lazy[node];
            lazy[rgt] = lazy[node];
        }  
        lazy[node] = -1;
    }

    if(q < st || ed < p) return;
    if(st >= p && ed <= q){
        //printf("st %d ed %d \n", st, ed);
        // only update cur node
        // then pass the value left and right child
        // be careful with overflow
        if(val == 2) {
            tree[node] = (ed-st+1-tree[node]);
            if(lazy[lft] != -1) {
                if(lazy[lft] == 2) lazy[lft] = -1;
                else lazy[lft] = !lazy[lft];
            }
            else {
                lazy[lft] = val;
            }
            if(lazy[rgt] != -1) {
                if(lazy[rgt] == 2) lazy[rgt] = -1;
                else lazy[rgt] = !lazy[rgt];
            }
            else {
                lazy[rgt] = val;
            }
        }
        else tree[node] = (ed-st+1)*val;

        if(st != ed && val != 2) {
            /*
            if(lazy[lft] != -1) {
                if(lazy[lft] == 2) tree[lft] = (ed-st+1-tree[lft]);
                else tree[lft] = (ed-st+1)*lazy[lft];
            } 
            if(lazy[rgt] != -1) {
                if(lazy[rgt] == 2) tree[rgt] = (ed-st+1-tree[rgt]);
                else tree[rgt] = (ed-st+1)*lazy[rgt];
            }*/
            lazy[lft] = val;
            lazy[rgt] = val;
        }
        return;
    }

    update(lft, st, mid);
    update(rgt, mid+1, ed);

    // 
    tree[node] = tree[lft] + tree[rgt];
}

int query(int node, int st, int ed)
{
    //printf("node %d\n", node);
    int mid, lft, rgt;

    mid = st+(ed-st)/2;
    lft = 2*node; rgt = lft+1;

    if(lazy[node] != -1) {
        //printf("qq st %d ed %d\n", st, ed);
        if(lazy[node] == 2) {
            tree[node] = (ed-st+1-tree[node]);
            if(lazy[lft] != -1) {
                if(lazy[lft] == 2) lazy[lft] = -1;
                else lazy[lft] = !lazy[lft];
            }
            else {
                lazy[lft] = lazy[node];
            }
            if(lazy[rgt] != -1) {
                if(lazy[rgt] == 2) lazy[rgt] = -1;
                else lazy[rgt] = !lazy[rgt];
            }
            else {
                lazy[rgt] = lazy[node];
            }
        }
        else tree[node] = (ed-st+1)*lazy[node];

        if(st != ed && lazy[node] != 2) {
            /*
            if(lazy[lft] != -1) {
                if(lazy[lft] == 2) tree[lft] = (ed-st+1-tree[lft]);
                else tree[lft] = (ed-st+1)*lazy[lft];
            } 
            if(lazy[rgt] != -1) {
                if(lazy[rgt] == 2) tree[rgt] = (ed-st+1-tree[rgt]);
                else tree[rgt] = (ed-st+1)*lazy[rgt];
            }*/
            lazy[lft] = lazy[node];
            lazy[rgt] = lazy[node];
        }
        lazy[node] = -1;
    }

    if(q < st || ed < p) return 0;
    if(st >= p && ed <= q) {
        //printf("qq st %d ed %d cnt %d\n", st, ed, tree[node]);
        return tree[node];
    }

    return query(lft, st, mid)+
            query(rgt, mid+1, ed);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt, n, T, m, kase = 1;
    string tmp;

    //scanf("%d", &tt);
    cin>>tt;
    while(tt--){

        memset(lazy, -1, sizeof lazy);
        memset(tree, 0, sizeof tree);
        str.clear();

        //scanf("%d%d", &n, &T);
        cin>>n;
        str.pb('$'); // to make 1-indexing
        //cin.ignore();
        for(int i=0; i<n; i++) {
            cin>>T>>tmp;
            while(T--) {
                str += tmp;
            }
            //cout << tmp<<endl;
        }
        //cout << str <<endl;
        int len = str.size();
        //printf("len %d \n", len, str.c_str());
        build(1, 1, len-1);
        //prnt(1, 1, len-1);
        //scanf("%d", &m);
        cin>>m;
        char ch;
        int qry = 1;
        printf("Case %d:\n", kase++);
        while(m--){
            //scanf("%c%d%d", &ch, &p, &q);
            cin>>ch>>p>>q;
            p++, q++;
            if(ch == 'F') {
                val = 1;
            }
            if(ch == 'E') {
                val = 0;
            }
            if(ch == 'I') {
                val = 2;
            }

            if(ch == 'S') {
                printf("Q%d: %d\n", qry++, query(1, 1, len-1));
            }
            else {
                update(1, 1, len-1);
                //prnt(1, 1, len-1);
            }
        }
    }

    return 0;
}
