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

int par_fr[100005];
int par_enm[100005];

int find_frnd(int x) 
{
    if(par_fr[x] == x) return x;
    return par_fr[x] = find_frnd(par_fr[x]);
}

int find_enmy(int x) 
{
    if(par_enm[x] == x) return x;
    return par_enm[x] = find_enmy(par_enm[x]);
}

void make_frnd(int a, int b)
{
    a = find_frnd(a); b = find_frnd(b);
    if(a == b) {
        //printf("-1\n");
        return;
    }
    par_fr[a] = b;
}

void make_enmy(int a, int b)
{
    a = find_enmy(a); b = find_enmy(b);
    if(a == b) {
        //printf("-1\n");
        return;
    }
    par_enm[a] = b;
}

vector<int>frnd[100005];
vector<int>enmy[100005];

int main()
{
    int n, c, x, y;
    cin>>n;

    for(int i=0; i<=n; i++) {
        par_enm[i] = i;
        par_fr[i] = i;
    }

    while(cin>>c>>x>>y, c || x || y){
        //printf("yes\n");
        int ans;
        if(c == 1){
            if(find_enmy(x) == find_enmy(y)){
                printf("-1\n");
                continue;
            }
            frnd[x].pb(y); frnd[y].pb(x);

            make_frnd(x, y);
            for(int i: enmy[y]){
                if(i != x && i!=y) {
                    enmy[x].pb(i); enmy[i].pb(x);
                    make_enmy(x, i);
                }
            }/*
            for(int i: enmy[x]){
                if(i != x && i!=y) {
                    enmy[y].pb(i); enmy[i].pb(y);
                    make_enmy(y, i);
                }
            }*/
        }
        else if(c == 2){
            if((find_frnd(x) == find_frnd(y))) {
                printf("-1\n");
                continue;
            }
            enmy[x].pb(y); enmy[y].pb(x);
            make_enmy(x, y);
            for(int i: enmy[y]) {
                if(i != x && i!=y) {
                    frnd[x].pb(i);
                    frnd[i].pb(x);
                    make_frnd(x, i);
                }
            }/*
            for(int i: enmy[x]) {
                if(i != x && i!=y) {
                    frnd[y].pb(i);
                    frnd[i].pb(y);
                    make_frnd(y, i);
                }
            }
            for(int i: frnd[x]){
                if(i != x && i!=y) {
                    enmy[y].pb(i);
                    enmy[i].pb(y);
                    make_enmy(y, i);
                }
            }*/
            for(int i: frnd[y]){
                if(i != x && i!=y) {
                    enmy[x].pb(i);
                    enmy[i].pb(x);
                    make_enmy(x, i);
                }
            }
        }
        else if(c == 3){
            ans = (find_frnd(x) == find_frnd(y));
            printf("%d\n", ans);
        }
        else {
            ans = (find_enmy(x) == find_enmy(y));
            printf("%d\n", ans);
        }
    }/*
    for(int i=0; i<10; i++){
        printf("frend of i %d\n", i);
        for(int j: frnd[i]) {
            printf("%d ", j);
        }
        printf("\n");
        printf("enemy of i %d \n", i);
        for(int j: enmy[i]) {
            printf("%d ", j);
        }
        printf("\n");
    }*/

    return 0;
}