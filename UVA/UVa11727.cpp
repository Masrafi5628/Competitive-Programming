#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,kase=1;
    cin>>t;


    while(t--){
        int a,b,c;

        cin>>a>>b>>c;
        printf("Case %d: ",kase++);

        if((a>b && a<c) || (a<b && a>c))    cout <<a<<endl;

        else if((b>a && b<c) || (b<a && b>c)) cout <<b<<endl;

        else cout <<c<<endl;
    }

    return 0;
}
