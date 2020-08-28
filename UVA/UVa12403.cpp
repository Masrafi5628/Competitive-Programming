#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,k;
    long long ans=0;

    char str[50];
    cin>>t;

    while(t--){
        scanf("%s",str);
        if(!strcmp(str, "donate")){
            cin>>k;
            ans+=k;
        }else {
            cout << ans<<endl;
        }
    }

    return 0;
}
