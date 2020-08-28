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


using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pcc = pair<char, char>;

const int inf = 9999999;
const ll mod = 1e9+7;

//int dr[] = {-1, 0, 1,  0};// up, right, down, left
//int dc[] = { 0, 1, 0, -1};

// King moves similar to 8 direction
int dr[] = {-1, -1, 0, 1, 1,  1, 0, -1};
int dc[] = { 0,  1, 1, 1, 0, -1,-1, -1};

// Knight moves
int kr[] = {-1,  1, -2, -2, -1, 1,  2,  2};
int kc[] = {-2, -2, -1,  1,  2, 2, -1,  1};

//vector<pair<double, int> >adj[800];
double adj[800][800];
bool visit[800];
vector<pii>ans;
int n;

ll sqr(int x)
{
    return x*x;
}

double dis(pii a, pii b)
{
    return sqrt(sqr(a.ff-b.ff)+sqr(a.ss-b.ss));
}

bool comp(pii a, pii b)
{
    return adj[a.ff][a.ss] < adj[b.ff][b.ss];
}

void prim(int src)
{
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > >pq;
    pq.push({0.0, src});

    while(!pq.empty()) {
        int v = pq.top().ss; pq.pop();
        if(visit[v]) {
            continue;
        }
        visit[v] = true;

        if(src < v)
            ans.pb({src, v});
        else 
            ans.pb({v, src});

        src = v;
        for(int i=1; i<=n; i++){
            if(adj[v][i] != 0.0 && !visit[i]) {
                pq.push({adj[v][i], i});
            }
        }
    }
    if(ans.empty()) {
        printf("No new highways need\n");
        return;
    }
    sort(all(ans), comp);
    for(pii x: ans){
        printf("%d %d\n", x.ff, x.ss);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        
        cin>>n;
        vector<pii>ara(n);
        for(int i=0; i<n; i++){
            cin>>ara[i].ff>>ara[i].ss;
        }
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                adj[i][j] = 0.0;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double wt = dis({ara[i].ff, ara[i].ss}, 
                    {ara[j].ff, ara[j].ss});

                printf(" %d -> %d = wt %f\n", i+1, j+1, wt);
                //adj[i+1].pb({wt, j+1});
                //adj[j+1].pb({wt, i+1});
                adj[i+1][j+1] = wt;
                adj[j+1][i+1] = wt;
            }
        }
        int m;
        cin>>m;
        memset(visit, false, sizeof visit);
        int a, b;
        while(m--){
            
            cin>>a>>b;
            //visit[a] = visit[b] = true;
            //adj[a].pb({0.0, b});
            //adj[b].pb({0.0, a});
            adj[a][b] = 0.0;
            adj[b][a] = 0.0;
        }/*
        for(int i=1; i<=n; i++){
            if(!visit[i]) {
                prim(i);
                break;
            }
        }*/
        prim(a);
        
        if(t) printf("\n");
    }

    return 0;
}