#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll n,s,sum;

    while(scanf("%lld %lld",&n,&s)!=EOF){
        vector<ll> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sum=v[0];
        int low=0,high=0,ans=n+1,temp;

        while(high < n){
            if(sum>=s){
                temp=high-low+1;
                if(temp<ans) ans=temp;
            }
            if(sum>=s && low<high){
                sum-=v[low];
                low++;
            }
            else if(sum<s){
                high++;
                if(high<n) sum+=v[high];
            }
        }
        if(ans==n+1) ans=0;
        printf("%d\n",ans);
    }

    return 0;
}
