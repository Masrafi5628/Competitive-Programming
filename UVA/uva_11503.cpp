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

int parent[100030];
int siz[100030];

int char_to_int(char ch)
{
    return ch-'A'+1;
}
void make_set(int x)
{
    for(int i=1; i<=x; i++) {
        siz[i] = 1;
        parent[i] = i;
    }
}

int find_set(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}

int union_set(int x, int y)
{
    x = find_set(x); y = find_set(y);
    if(x != y) {
        if(siz[x] > siz[y]){
            siz[x] += siz[y];
            parent[y] = x;
            siz[y] = 0;
            return x;
        }else {
            siz[y] += siz[x];
            parent[x] = y;
            siz[x] = 0;
            return y;
        }
    }
}

int main()
{
    int t;
    string str;
    cin>>t;

    while(t--){
        int n, k=1, x, y, cnt=1;
        cin>>n;
        map<string, int>mp;

        make_set(1e5+5);

        while(n--){
            string a, b;
            cin>>a>>b;

            x = mp[a]?mp[a]:k++;
            mp[a] = x;

            y = mp[b]?mp[b]:k++;
            mp[b] = y;

            if(find_set(x) != find_set(y)){
                cout << siz[union_set(x, y)] <<endl;
            }else {
                cout << siz[find_set(x)] << endl;
            }
        }
    }

    return 0;
}