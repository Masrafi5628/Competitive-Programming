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

struct circle
{
    int x, y, r;
};

int sqr(int a)
{
    return a*a;
}

int main()
{
    map<pii, int>mp;
    int tt, kase = 1, xx, yy;
    cin>>tt;

    while(tt--){
        cin>>xx>>yy;
        vector<circle>ara;
        circle a;

        for(int i=0; i<xx; i++){
            cin>>a.x>>a.y>>a.r;
            ara.pb(a);
        }

        string ans;
        printf("Case %d:\n", kase++);
        while(yy--){
            int x, y;
            ans = "No";
            cin>>x>>y;
            for(int i=0; i<xx; i++) {
                if((sqr(ara[i].x-x)+sqr(ara[i].y-y)) <= sqr(ara[i].r)) {
                    ans = "Yes"; break;
                }
            }
            printf("%s\n", ans.c_str());
        }
    }

    return 0;
}
