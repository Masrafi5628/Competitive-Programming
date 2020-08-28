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

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;

const int inf = 2e9;
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

int m, n, make;
queue<pii>q;
map<pii, pii>parent;
map<pii, int>ans;
map<pii, bool>visit;
vector<string>str;

void sol(pii x)
{
    //string str[1111];
    //printf("asce\n");
    int a = x.ff, b = x.ss;
    while(a || b){
        //a = x.ff, b = x.ss;
        //printf("a %d b %d\n", a, b);
        switch(ans[{a, b}]) {
            case 1: 
                str.pb("fill A");
                break;
            case 2: 
                str.pb("fill B");
                break;
            case 3:
                str.pb("pour A B");
                break;
            case 4:
                str.pb("pour B A");
                break;
            case 5:
                str.pb("empty A");
                break;
            default:
                str.pb("empty B");
                break;
        }
        x = parent[{a, b}];
        a = x.ff, b = x.ss;
    }
    for(int i=str.size()-1; i>=0; i--){
        printf("%s\n", str[i].c_str());
    }
}

void bfs()
{
    q.push({0, 0});
    int step = 1;
    while(!q.empty()){
        pii water = q.front(); q.pop();
        int a = water.ff, b = water.ss;
        //printf("step %d\n", step);
        //printf("a %d b %d\n", a, b);

        if(a == make || b == make){
            sol({a, b});
            return;
        }
        if(visit[{a, b}])
            continue;
        // fill a or b
        if(!a){
            if(!visit[{m, b}]) {
                q.push({m, b}); parent[{m, b}] = {a, b};
                ans[{m, b}] = 1; //visit[{m, b}] = true;
            }
        }
        if(!b){
            if(!visit[{a, n}]) {
                q.push({a, n}); parent[{a, n}] = {a, b};
                ans[{a, n}] = 2; //visit[{a, n}] = true;
            }
        }
        // pour a -> b or b -> a
        if((a && (b < n))){
            if(!visit[{max(0, a-(n-b)), min(a+b, n)}]) {
                q.push({max(0, a-(n-b)), min(a+b, n)});
                parent[{max(0, a-(n-b)), min(a+b, n)}] = {a, b};
                ans[{max(0, a-(n-b)), min(a+b, n)}] = 3;
            //visit[{max(0, a-(n-b)), min(a+b, n)}] = true;
            }
               
        }
        if((b && (a < m))) {
            if(!visit[{min(a+b, m), max(0, b-(m-a))}]) {
                q.push({min(a+b, m), max(0, b-(m-a))});
                parent[{min(a+b, m), max(0, b-(m-a))}] = {a, b};
                ans[{min(a+b, m), max(0, b-(m-a))}] = 4;
            //visit[{min(a+b, m), max(0, b-(m-a))}] = true;
            }
               
        }
        // empty a or b

        if(a){// check 
            if(!visit[{0, b}]) {
                q.push({0, b}); parent[{0, b}] = {a, b};
                ans[{0, b}] = 5; //visit[{0, b}] = true;
            }
        }
        if(b){
            if(!visit[{a, 0}]) {
                q.push({a, 0}); parent[{a, 0}] = {a, b};
                ans[{a, 0}] = 6; //visit[{a, 0}] = true;
            }
        }
        visit[{a, b}] = true;
    }
}

int main()
{
    
    while(cin>>m>>n>>make){
        str.clear();
        parent.clear();
        ans.clear();
        visit.clear();
        while(!q.empty()) q.pop();

        bfs();
        printf("success\n");
    }

    return 0;
}