#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,a,b;
    cin>>t;

    while(t--){
        bool ck = true;
        cin>>n;
        n--;
        cin>>a>>b;

        int ans = abs(a-b);
        while(n--){
            cin>>a>>b;
            if(ans == abs(a-b)) continue;
            else ck=false;
        }

        if(ck) cout << "yes\n";
        else cout << "no\n";

        if(t>0) cout<< "\n";
    }

    return 0;
}
