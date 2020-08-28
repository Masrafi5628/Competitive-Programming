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
    int n;
    while(cin>>n, n!=0){
        ll ans = 0;
        for(int i=1; i<n; i++){
            ll sum = 0;
            ll ara[i+1];
            memset(ara, 0, sizeof ara);

            for(int j=i+1; j<= i+i && j<=n; j++){
                ara[j%i] = __gcd(i, j);
                sum += ara[j%i];
            }
            ll cnt = 0;
            if(i+i <= n)  {
                cnt = (n-(i+i))/i;
                ans += ((cnt+1)*sum);
                for(int l=1; l<=(n-(i+i))%i; l++){
                    ans += ara[l];
                }
            }
            else {
                ans += sum;
            }

        }
        cout << ans <<endl;
    }
    
    return 0;
}