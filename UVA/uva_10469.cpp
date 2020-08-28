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
    int a, b;
    while(cin>>a>>b){
        string str_a, str_b;
        while(a != 0){
            if(a%2) str_a += '1';
            else str_a += '0';
            a = a/2;
        }
        while(b != 0){
            if(b%2) str_b += '1';
            else str_b += '0';
            b = b/2;
        }
        reverse(all(str_a));
        reverse(all(str_b));
        int len1 = str_a.size();
        int len2 = str_b.size();

        string tmp;
        if(len2 > len1) {
            while(len2 != len1) {
                tmp.pb('0'); len1++;
            }
            str_a = tmp + str_a;
        }else {
            while(len1 != len2) {
                tmp.pb('0'); len2++;
            }
            str_b = tmp + str_b;
        }

        string ans;
        for(int i=0; i<len2; i++){
            if(str_a[i] == str_b[i]) ans.pb('0');
            else ans.pb('1');
        }
        int val = 0, k=1;
        for(int i=ans.size()-1; i>=0; i--, k*=2){
            if(ans[i] == '1') val += k;
        }

        cout <<val <<endl;
    }
    
    return 0;
}