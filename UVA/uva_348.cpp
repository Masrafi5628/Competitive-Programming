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

ll ara[20];
ll dp[15][15];
int order[15][15];

ll solve(int i, int j)
{
    if(i == j) {
        dp[i][j] = 0;
        return 0;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 99999999;
    for(int k=i; k<j; k++){
        //printf("(%c, %c)X(%c, %c)\n", i-1+'A', k-1+'A', k+'A', j-1+'A');
        //printf("i %d j %d k %d\n", i, j, k);
        int tmp = solve(i, k)+solve(k+1, j)+(ara[i-1]*ara[k]*ara[j]);
        if(tmp < ans){
            ans = tmp;
            order[i][j] = k;
        }
        //order[i][j] = k;

    }
    //printf("ans %d\n", ans);
    return dp[i][j] = ans;
}
string ans;

void optimal_order(int i, int j)
{
    if(i==j) {
        string str = to_string(i);
        ans += "A"+str;
    }
    else {
        ans += '(';
        optimal_order(i, order[i][j]);
        optimal_order(order[i][j]+1, j);
        ans += ')';
    }
}

int main()
{
    int n, kase =1;
    while(cin>>n, n!=0) {
        ans = "";
        memset(dp, -1, sizeof dp);
        memset(ara, 0, sizeof ara);

        for(int i=0; i<n; i++){
            cin>>ara[i]>>ara[i+1];
        }

        ll cost = solve(1, n);
        optimal_order(1, n);
        //cout << ans <<endl;
        cout << "Case "<< kase++ << ": ";
        for(int i=0; i<ans.size()-1; i++){
            if(ans[i]>='0' && ans[i] <= '9') {
                cout << ans[i];
                if(ans[i+1] == '('){
                    
                    cout <<" x ";
                }
                else if(isupper(ans[i+1])){
                    cout<< " x ";
                    //cout << ans[i+1];
                }
            }else if(ans[i] == ')') {
                cout << ans[i];
                if(isupper(ans[i+1])) {
                    cout << " x ";
                }
                else if(ans[i+1] =='('){
                    cout << " x ";
                }
            }else {
                cout << ans[i];
            }
            
        }
        cout << ")\n";
    }
    
    return 0;
}