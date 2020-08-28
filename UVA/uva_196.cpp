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

const int inf = 9999999;
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

int main()
{
    int t;
    cin>>t;
    string str;

    while(t--){
        int n, m;
        cin>>m>>n;
        int ara[n+2][m+2];
        vector<string>v;
        vector<pii>idx;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //cin>>ara[j][i];
                cin>>str;
                if(str[0] != '=') ara[j][i] = stoi(str);
                else {
                    v.pb(str);
                    idx.pb({j, i});
                }
            }
        
        }
        int l = 0;
        for(string str: v){
            pii x = idx[l];
            int sum = 0;
            for(int k=1; k<str.size(); k+=3){
                int row = str[k]-'A', col = str[k+1]-'1';
                sum += ara[row][col];
            }
            ara[x.ff][x.ss] = sum;
            l++;
        }
        /*
        string str;
        for(int i=0; i<m; i++){
            cin>>str;
            int sum = 0;
            for(int i=1; i<str.size(); i+=3){
                int row = str[i]-'A', col = str[i+1]-'1';
                sum += ara[row][col];
            }
            ara[i][n-1] = sum; 
        }
        */
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << ara[j][i];
                if(j+1 != m) cout << ' ';
            }
            cout << endl;
        }

    }
    
    return 0;
}