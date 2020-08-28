#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define REP(i,n) for(int i=0;i<n;i++)
//#define FOR(a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define maxn 1005
using namespace std;

int main()
{
    int n,m,count;
    long long a[maxn],b[maxn],x[maxn],y[maxn],t[maxn];

    while(scanf("%d%d",&n,&m)!=EOF){
        count=0;
        REP(i,n){
            scanf("%lld%lld",&a[i],&b[i]);
        }
        REP(i,m){
            scanf("%lld%lld%lld",&x[i],&y[i],&t[i]);
        }
        REP(i,m){
            if(t[i]==0){
                REP(i,n){
                    if(a[i]>=x[i] && y[i]>=b[i]) count++;
                }
                cout<<count<<endl;
                break;
            }
            /*else {

            }*/
        }
    }
    return 0;
}

