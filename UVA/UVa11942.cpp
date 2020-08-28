#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ara[13],k;

    cin>>n;
    k=n;
    while(n--){
        bool ck1=true,ck2=true;
        for(int i=0;i<10;i++){
            cin>>ara[i];
        }
        for(int j=0;j<9;j++){
            if(ara[j]<ara[j+1]) continue;
            else ck1=false;
        }

        for(int j=0;j<9;j++){
            if(ara[j]>ara[j+1]) continue;
            else ck2=false;
        }
        if(n+1==k) printf("Lumberjacks:\n");
        if(ck1 || ck2) cout << "Ordered\n";
        else cout<< "Unordered\n";


    }

    return 0;
}
