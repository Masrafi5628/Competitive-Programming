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

int parent[30];

void make_set(int x)
{
    for(int i=1; i<=x; i++)
        parent[i] = i;
}

int find_set(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}

int main()
{
    int n, k, val;
    while(cin>>n>>k) {
        val = 4;
        string str;
        map<char, int>mp;
        cin>>str;

        mp[str[0]] = 1;
        mp[str[1]] = 2;
        mp[str[2]] = 3;

        make_set(n);

        for(int i=1; i<=3; i++)
            parent[i] = 1;

        int cnt[n+5], ans=0;
        bool ck[n+5];

        set<int>st;

        memset(cnt, 0, sizeof cnt);
        memset(ck, false, sizeof ck);

        vector<int>adj[30];

        while(k--){
            cin>>str;
            int a, b;
            a = mp[str[0]]?mp[str[0]]:val++;
            b = mp[str[1]]?mp[str[1]]:val++;

            mp[str[0]] = a;
            mp[str[1]] = b;

            //printf("a %d b %d\n", a, b);
            a = find_set(a), b = find_set(b);
            if(a != b){
                if(a == 1){
                    cnt[b]++;
                }
                else if(b == 1){
                    cnt[a]++;
                }
                else {
                    adj[a].pb(b); adj[b].pb(a);
                }
            }else {
                if(a != 1)
                    adj[a].pb(b); adj[b].pb(a);
            }
           
        }

        bool ok = true;
        int awake = 3;

        while(awake < n) {
            vector<int>v;

            for(int i=4; i<=n; i++){
                //cout << find_set(i) << " "<<cnt[i]<< endl;
                if(find_set(i) != 1 && cnt[i] >= 3){
                    awake++;
                    v.pb(i);
                }
            }
            if(v.empty()){
                printf("THIS BRAIN NEVER WAKES UP\n");
                ok = false; break;
            }else {
                ans++;
                for(int x: v){
                    parent[x] = 1;
                    for(int y: adj[x]){
                        cnt[y]++;
                    }
                }
            }
        }
        if(ok) printf("WAKE UP IN, %d, YEARS\n", ans);
        
        for(int i=4; i<=n; i++)
            adj[i].clear();
    }
    return 0;
}
