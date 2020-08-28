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

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
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

int n, ans, tower[55];
/* 1st Approach
int hanoi(int i)
{
    if(i == 1) return 1;
    if(i == 2) return 3;
    if(i == 3) return 7;
    if(i%2) return hanoi(i-1)+i+1;
    else return hanoi(i-1)+i;
}
 2nd Approach*/
void hanoi(int num, int idx)
{
    if(idx == n) return;
    if(tower[idx] == 0) {
        tower[idx] = num;
        ans++;
        return hanoi(num+1, idx);
    }
    for(int i=0; i<=idx; i++){
        int root = sqrt(tower[i]+num);
        if(root*root == tower[i]+num) {
            tower[i] = num;
            ans++;
            return hanoi(num+1, idx);
        }
    }
    return hanoi(num, idx+1);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        ans = 0;
        memset(tower, 0, sizeof tower);
        hanoi(1, 0);
        cout << ans <<endl;
    }

    return 0;
}