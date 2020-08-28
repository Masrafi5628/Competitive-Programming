#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        long long n,ans;
        string str;

        cin>>n;

        ans=(((63*n+7492)*235)/47)-498;
        str=to_string(ans);


        cout <<str[str.length()-2]<<endl;
    }

    return 0;
}
