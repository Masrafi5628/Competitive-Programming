
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;


    while(scanf("%lld",&n)){
        if(!n) break;
        long long ans = 0,temp=0;
        while(n>0 || ans > 9){
            if(n>0){
                ans+=n%10;
                n/=10;
            }
            else if(ans>9 && n==0){
                n=ans;
                ans=0;
            }
        }
        cout << ans<<endl;
    }

    return 0;
}
