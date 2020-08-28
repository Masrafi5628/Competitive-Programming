#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,k,n) for(int i=k;i<=n;i++)
#define REPR(i,k,n) for(int i=k;i>=n;--i)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

/*memset(memo, -1, sizeof memo);
memset(arr, 0, sizeof arr);
vector<int> v(N, 0); // OR vi v(N, 0);*/

#define f first
#define s second
#define pb push_back
#define mp make_pair

bool isPowerof_2(int x)
{

    return x && (!(x&(x-1)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a = 1234567891;
    int c = 1111111111;
    ll b= (ll)a*c;

    cout<<b<< "\n";

    int x = -5, mod=3;

    int ans = x%mod;
    cout<< ans<<endl;// before add
    if(ans < 0) 
        ans += mod;

    cout<<ans << '\n';// after add if <0

    double y = 0.3*3+0.1;
    printf("%.20f\n", y);

    if(abs(a-b) < 1e-9)
        // if a and b are equal

    vector<int> ara;
    pii p;

    //ara.push_back(12);
    p = mp(12,32);

    //cout<<ara[0]<< '\n';
    cout<<p.f<< ' '<<p.s<<endl;

    return 0;
}
