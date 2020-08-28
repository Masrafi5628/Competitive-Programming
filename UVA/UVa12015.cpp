#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,kase=1,ck,ara[15];
    char str[15][105];

    cin>>t;
    while(t--){
        ck=INT_MIN;

        for(int i=0;i<10;i++){
            cin>>str[i]>>ara[i];
            if(ara[i]>ck) ck=ara[i];
        }

        printf("Case #%d:\n",kase++);
        for(int j=0;j<10;j++){
            if(ara[j]>=ck) cout << str[j]<<endl;
        }
    }

    return 0;
}
