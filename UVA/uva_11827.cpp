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
    char ch;
    int t, kase = 1;
    cin>>t;
    //cin>>a;
    while(t--){

        string str;
        int ara[105], i = 0;
        if(kase) cin>>ara[i++];
        getline(cin, str);

        istringstream my_stream(str);
        //cout << str.size() <<endl;

        while(my_stream) {
            my_stream>>ara[i];
            i++;
        }
        //printf("i %d\n", i);
        int ans = 0;
        for(int j=0; j<i-2; j++){
            for(int k=j+1; k<i-1; k++){
                //printf("j %d k %d\n", ara[j], ara[k]);
                ans = max(ans, __gcd(ara[j], ara[k]));
            }
        }
        cout << ans <<endl;
        kase = 0;
    }
    
    return 0;
}