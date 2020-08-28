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

const int white = 0, gray = 1, black = 2;

vector<int>adj[111];
int color[111]; // fill with 0

bool dfsVisit(int x)
{
    color[x] = gray;
    for(int i=0; i<adj[x].size(); i++){
        if(color[adj[x][i]]==gray){
            return true;
        }
        else if(color[adj[x][i]]==white && 
            dfsVisit(adj[x][i])){
            return true;
        }
    }
    color[x] = black;
    return false;
}
int cnt = 0;

void dfs(int vertex)
{
    for(int i=1; i<=vertex; i++){
        if(color[i] == white){
            if(dfsVisit(i)) {
                printf("asce\n");
                cnt++;
                return;
            }
        }
    }
    printf("Graph does not contain cycle\n");
}

int main()
{
    //int cnt = 0;
    for(int i=0; i<120; i++){
        int edge = 0;
        memset(color, 0, sizeof color);
        for(int i=1; i<=5; i++) adj[i].clear();
        map<int, int>mp;
        int ara[8];
        for(int j=0; j<5; j++)
            cin>>ara[j];
        for(int k=0; k<5; k++){
            for(int l = k-1; l>=0; l--){
                if(ara[k] < ara[l])
                    //edge+=2, mp[ara[k]]++, mp[ara[l]]++;
                    adj[k].pb(l), adj[l].pb(k);
            }
            for(int l=k+1; l<5; l++){
                if(ara[k] < ara[l])
                    //edge+=2, mp[ara[k]]++, mp[ara[l]]++;
                    adj[k].pb(l), adj[l].pb(k);
            }
        }
        int node = 0;
        for(int i=1; i<=5; i++) {
            if(mp[i]) node++;
        }

        dfs(5);
    } 
    cout << cnt <<endl;
    
    return 0;
}
