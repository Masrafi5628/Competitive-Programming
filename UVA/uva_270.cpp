/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
*/

#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))

//#define inf 1<<30

// isupper() -> upper case check
// tolower() -> convert upper to lower case
// idx = str.find("bear", pos)) != string::npos =>substring find
// Tuple access -> get<0>(v[i])
// cmnt - ctrl []
// stoi("...") -> decimel
// istringstream ss(str) while(ss >> n)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;

const ll inf = 2e18;
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

// for unordered map because unordered
// map does not support pair
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};
/*
Idea: In straight line all points have
        same slope
*/
int main()
{
    int t;
    cin>>t;
    string str;
    cin.ignore();
    getline(cin, str);

    while(t--){
        int a, b;
        vector<pii>ara;

        while(getline(cin, str)){
            if(str.empty()) break;

            istringstream ss(str);
            ss >> a; ss >> b;
            ara.pb({a, b});
        }
        int n = ara.size(), ans = 0;
        //printf("n %d\n", n);
        unordered_map<pii, int, hash_pair>slope;

        for(int i=0; i<n; i++){ 
            //int ver = 0, hor = 0, cur = 0;
            for(int j=i+1; j<n; j++){

                int dif_x = ara[i].ff-ara[j].ff;
                int dif_y = ara[i].ss-ara[j].ss;
                //printf("%d %d\n", dif_x, dif_y);
                //if(!dif_x) ver++;
                //else if(!dif_y) hor++;
                //else { 
                    int gd = __gcd(dif_x, dif_y);
                    dif_x /= gd, dif_y /= gd;

                    slope[{dif_x, dif_y}]++;
                    //cur = max(cur, slope[{dif_x, dif_y}]);
                    ans = max(ans, slope[{dif_x, dif_y}]);
                //}
            }
            //ans = max({ans, cur+1, ver+1, hor+1});
            //ans = max(ans, cur+1);
            slope.clear();
        }
        printf("%d\n", ans+1);
        if(t) printf("\n");
    }

    return 0;
}
