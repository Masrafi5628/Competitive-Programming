#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n,Min=INT_MAX,Max=INT_MIN;
        cin>>n;
        vector<int> v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]<Min) Min=v[i];
            if(v[i]>Max) Max=v[i];
        }

        cout << (Max-Min)*2 <<endl;
    }

    return 0;
}
